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
	//���캯��������1Ϊ�˲����ڴ�С��Ĭ��Ϊ��ֵ�˲�
	SmoothFilter(unsigned int size, flitertype type = MEDINE){
		_size = size;
		_type = type;
	}
	/*���캯��������1Ϊ�˲����ڴ�С������2Ϊ��˹�����ķ���
	��Ĭ��Ϊ��˹ƽ���˲�*/
	SmoothFilter(unsigned int size, float variance,
		flitertype type = GUSSIAN){
		_size = size;
		_type = type;
		setGussinvar(variance);
	}
	/*SmoothFilter();
	~SmoothFilter();*/

	//������cur_data���
	void push(float cur_data);
	//�˲������
	float output(){ return _output; }
	//�����˲����ڴ�С
	void setsize(unsigned int size);
	//���ø�˹�����ķ���
	void setGussinvar(float variance);
	//��ʼ������Ҫ����һ�����˲����ڴ�С��ͬ������
	void init(vector<float> &init_vec);


private:
	unsigned int _size;
	float _output;
	list<float> _seq;
	flitertype _type;
	Gussin_para _gussin_para;
};


#endif