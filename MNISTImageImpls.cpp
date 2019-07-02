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
	return 0;
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
	for(uint32 i=0; i < size; i++){
		this->data[i] = data[i];
	}

	this->label = label;
	this->size = size;
  
}


DownsampleMNISTImage::DownsampleMNISTImage(uint8 data[], uint32 size, uint8 label, uint32 factor):
		ArrayMNISTImage(label)
{
   
}

ScaledMNISTImage::ScaledMNISTImage(uint8 data[], uint32 numRows, uint32 numCols, uint8 label, uint32 factor):
		ArrayMNISTImage(label)
{
    
}



SumMNISTImage::SumMNISTImage(uint8 data[], uint32 size, uint8 label):
		MNISTImage(label)
{
	
}


double SumMNISTImage::distance(const MNISTImage *img) const
{
	return 0;
}



