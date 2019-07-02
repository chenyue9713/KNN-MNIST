#include<cstdlib>
using namespace std;

#include "MNISTDataset.h"
#include "knn.h"
#include<utility>
#include<queue>

typedef pair<double, uint8> distLabel;

uint32 KNN(MNISTDataset &trainSet, MNISTDataset &testSet, uint32 k, uint32 max, bool verbose)
{
	uint32 trainSetNum = trainSet.getNumImages();
	const MNISTImage* testImg;
	const MNISTImage* trainImg;
	uint32 Numcurrect = 0;

	
	for (uint32 i = 0; i < max; i++) {
		testImg = testSet.getImage(i);
		int testLabel = testImg->getLabel();
		priority_queue<distLabel, vector<distLabel>, greater<distLabel>> imgqueue;
		for (uint32 j = 0; j < trainSetNum; j++) {
			trainImg = trainSet.getImage(j);
			uint8 trainLabel = trainImg->getLabel();
			double dist = trainImg->distance(testImg);
			imgqueue.push(make_pair(dist, trainLabel));
		}

		uint8 Labelcounter[10] = {0,0,0,0,0,0,0,0,0,0};
		for (uint8 j = 0; j < k; j++) {
			distLabel dlpair = imgqueue.top();
			Labelcounter[dlpair.second] += 1;
			imgqueue.pop();
		}

		uint8 highest_count = 0;
		uint8 highest_label = 0;
		for (uint8 j = 0; j < 10; j++) {
			if (Labelcounter[j] > highest_count) {
				highest_label = j;
				highest_count = Labelcounter[j];
			}

		}

		if (highest_label == testLabel) {
			Numcurrect++;
		}
		
	}

	return Numcurrect;
   
}


