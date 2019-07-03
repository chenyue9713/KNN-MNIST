#include<cstdlib>
using namespace std;
#include<iostream>
#include"MNISTImageImpls.h"
#include<math.h>
#include<vector>

using namespace std;

RandomMNISTImage::RandomMNISTImage(uint8 label):
		MNISTImage(label)
{



}

double RandomMNISTImage::distance(const MNISTImage *img) const
{
	return ((double)(rand() % 714000)) / 100.0;
}


ArrayMNISTImage::ArrayMNISTImage(uint8 label):
		MNISTImage(label)
{
	
	this->label = label;
	this->data = NULL;
	this->size = 0;
}


double ArrayMNISTImage::distance(const MNISTImage *img) const
{
	double dist = 0.0;
	const ArrayMNISTImage* arrayimg = dynamic_cast<const ArrayMNISTImage*>(img);
	for (uint32 i = 0; i < this->size; i++) {
		dist += pow((this->data[i] - arrayimg->data[i]),2);
	}
	dist = sqrt(dist);
	return dist;
}


FullArrayMNISTImage::FullArrayMNISTImage(uint8 data[], uint32 size, uint8 label):
		ArrayMNISTImage(label)
{
	this->data = new uint8[size];
	for (uint32 i = 0; i < size; i++) {
		this->data[i] = data[i];
	}

	this->label = label;
	this->size = size;
  
}


DownsampleMNISTImage::DownsampleMNISTImage(uint8 data[], uint32 size, uint8 label, uint32 factor):
		ArrayMNISTImage(label)
{
	uint32 new_size = size / factor;
	this->data = new uint8[new_size];
	for (uint32 i = 0; i < new_size; i++) {
		this->data[i] = data[i*factor];
	}

	this->label = label;
	this->size = new_size;

   
}

ScaledMNISTImage::ScaledMNISTImage(uint8 data[], uint32 numRows, uint32 numCols, uint8 label, uint32 factor):
		ArrayMNISTImage(label)
{
	uint8 new_numRows = numRows / factor;
	uint8 new_numCols = numCols / factor;
	uint32 new_size = new_numRows * new_numCols;
	this->data = new uint8[new_size];
	for (uint8 i = 0; i < numRows; i++) {
		for (uint8 j = 0; j < numCols; j++) {
			this->data[(i/factor)*new_numRows + (j/factor)] += (data[(i* numRows) + j]) / (factor * factor);
		}
	}

	this->size = new_size;
	this->label = label;

    
}



SumMNISTImage::SumMNISTImage(uint8 data[], uint32 size, uint8 label):
		MNISTImage(label)
{
	double sum = 0;

	for (uint32 i = 0; i < size; i++) {
		sum += data[i];
	}

	this->sum = sum;

}


double SumMNISTImage::distance(const MNISTImage *img) const
{
	const SumMNISTImage* arrayimg = dynamic_cast<const SumMNISTImage*>(img);
	double first_img_sum = this->sum;
	double second_img_sum = arrayimg->sum;
	double diff = first_img_sum - second_img_sum;
	double distance = sqrt((diff * diff));

	return distance;



}



