#ifndef _SMOOTHFILTER_H_ 
#define _SMOOTHFILTER_H_

#include <list>
#include <vector>
using std::list;
using std::vector;


enum flitertype{
	MEDINE=0,
	GUSSIAN=1
};

struct Gussin_para{
	float gussin_var;
	vector<float> seq;
};

class SmoothFilter
{
public:
	//构造函数，参数1为滤波窗口大小，默认为均值滤波
	SmoothFilter(unsigned int size, flitertype type = MEDINE){
		_size = size;
		_type = type;
	}
	/*构造函数，参数1为滤波窗口大小，参数2为高斯函数的方差
	，默认为高斯平滑滤波*/
	SmoothFilter(unsigned int size, float variance,
		flitertype type = GUSSIAN){
		_size = size;
		_type = type;
		setGussinvar(variance);
	}
	/*SmoothFilter();
	~SmoothFilter();*/

	//新数据cur_data入队
	void push(float cur_data);
	//滤波器输出
	float output(){ return _output; }
	//设置滤波窗口大小
	void setsize(unsigned int size);
	//设置高斯函数的方差
	void setGussinvar(float variance);
	//初始化，需要传入一个与滤波窗口大小相同的向量
	void init(vector<float> &init_vec);


private:
	unsigned int _size;
	float _output;
	list<float> _seq;
	flitertype _type;
	Gussin_para _gussin_para;
};


#endif