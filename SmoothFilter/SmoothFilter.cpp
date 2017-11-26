#include <cmath>
#include <iostream>

#include "SmoothFilter.h"

using namespace std;

void SmoothFilter::setGussinvar(float variance)
{
	_gussin_para.gussin_var = variance;
	//float step = 3 * sqrt(variance) / _size;

	_gussin_para.seq.resize(_size);
	for (unsigned int i = 0; i < _size; i++)
		_gussin_para.seq[i] = exp(i*i / (-2 * variance));

	float sum = 0;
	for each (float var in _gussin_para.seq)
		sum += var;

	for (vector<float>::iterator iter = _gussin_para.seq.begin();
		iter!=_gussin_para.seq.end(); iter++)
		*iter /= sum;
}

void SmoothFilter::push(float cur_data)
{
	_seq.push_front(cur_data);
	_seq.pop_back();

	_output = 0;
	vector<float>::iterator vec_iter = _gussin_para.seq.begin();

	switch (_type)
	{
	case GUSSIAN:
		for (list<float>::iterator list_iter = _seq.begin();
			list_iter != _seq.end(); list_iter++,vec_iter++)
			_output += (*list_iter)*(*vec_iter);
		break;
	default:
		float sum = 0;
		for each (float var in _seq)
			sum += var;
		_output = sum / _size;
		break;
	}
	
}

void SmoothFilter::init(vector<float> &initvec)
{
	if (_size != initvec.size())
	{
		cout << "init_vec size do not match with filter size" << endl;
		exit(0);
	}

	else
	{
		for each (float var in initvec)
			_seq.push_back(var);
	}
}

void SmoothFilter::setsize(unsigned int size)
{
	_size = size;
	setGussinvar(_gussin_para.gussin_var);
}