#include <iostream>
#include <vector>
using namespace std;

#define SIZE 100

int main()
{
	vector<int> vec;
	int	size = SIZE;

	srand((unsigned int)time(NULL));

	for (int i=0; i<size; ++i)
		vec.push_back(i);

	while (!vec.empty())
	{
		int num = rand() % size;
		cout << vec[num] << ' ';
		vec.erase(vec.begin() + num);
		--size;
	}
}