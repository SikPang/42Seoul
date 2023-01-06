#include <iostream>
#include <queue>

using namespace std;

#define MAX_NUM 1000
#define NUM_CNT 20

int main()
{
	queue<int> que[10];
	int arr[NUM_CNT];
	int max_cnt = 0;	// 가장 큰 수의 자릿수 개수
	int div_cnt = 0;

	srand(time(NULL));

	cout << "before : "; 
	for (int i=0; i<NUM_CNT; ++i) 
	{
		arr[i] = rand() % MAX_NUM;

		int temp = arr[i];
		int cnt = 0;
		while (temp > 0)
		{
			temp /= 10;
			++cnt;
		}
		if (cnt > max_cnt)
			max_cnt = cnt;
		
		cout << arr[i] << ' ';
	}
	cout << '\n';

	while (div_cnt < max_cnt)
	{
		for (int i=0; i<NUM_CNT; ++i)
		{
			int temp = arr[i];
			
			for (int j=0; j<div_cnt; ++j)
				temp /= 10;
			que[temp % 10].push(arr[i]);
		}

		int cur_idx = 0;
		for (int i=0; i<10; ++i)
		{
			while (!que[i].empty())
			{
				arr[cur_idx] = que[i].front();
				que[i].pop();
				++cur_idx;
			}
		}

		++div_cnt;
	}

	cout << "after : "; 
	for (int i=0; i<NUM_CNT; ++i) 
		cout << arr[i] << ' ';
	cout << '\n';

  	return 0;
}