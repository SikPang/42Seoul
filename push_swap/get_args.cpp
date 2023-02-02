#include <iostream>
#include <vector>
using namespace std;

#define SIZE 500

vector<int> vec;
int	arg_size = SIZE;

void with_negative()
{
	for (int i=0; i<arg_size/2; ++i)
		vec.push_back(i);

	for (int i=1; i<arg_size - arg_size/2 + 1; ++i)
		vec.push_back(-i);
}

void only_positive()
{
	int	arg_size = SIZE;

	for (int i=0; i<arg_size; ++i)
		vec.push_back(i);
}

int main()
{
	srand((unsigned int)time(NULL));

	with_negative();	// 음수 포함
	//only_positive();	// 양수만

	while (!vec.empty())
	{
		int num = rand() % arg_size;
		cout << vec[num] << ' ';
		vec.erase(vec.begin() + num);
		--arg_size;
	}
}