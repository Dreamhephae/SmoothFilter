#include <iostream>
#include "SmoothFilter.h"

using namespace std;
void main()
{
	vector<float> init_vec;
	int size = 10;
	for (int i = 0; i < size; i++)
	{
		init_vec.push_back(1.0);
	}
	cout << init_vec.size() << endl;
	SmoothFilter filter(size,100,GUSSIAN);
	
	filter.init(init_vec);
	
	for (int i = 0; i < 10; i++)
	{
		float ran = rand() % (2 - 0 + 1);
		filter.push(ran);
		cout << ran << "    " << filter.output() << endl;
	}

	for (int i = 0; i < 20; i++)
	{
		
		filter.push(2);
		cout << 2 << "    " << filter.output() << endl;
	}
	
}