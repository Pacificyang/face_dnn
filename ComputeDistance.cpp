#include "ComputeDistance.h"
#include   <iostream> 
using namespace std;

float dotProduct(const vector<float>& v1, const vector<float>& v2)
{
	assert(v1.size() == v2.size());
	float ret = 0.0;
	for (vector<float>::size_type i = 0; i != v1.size()-2; ++i)
	{
		ret += v1[i] * v2[i];
		//cout << "v1["<<i <<"]:" << v1[i]<< " v2[" << i << "]:" << v2[i] << endl;
	}
	return ret;
}
float module(const vector<float>& v)
{
	float ret = 0.0;
	for (vector<float>::size_type i = 0; i != v.size()-2; ++i)
	{
		ret += v[i] * v[i];
	}
	return sqrt(ret);
}
float cosine(const vector<float>& v1, const vector<float>& v2)
{
	assert(v1.size() == v2.size());
	return dotProduct(v1, v2) / (module(v1) * module(v2));
}