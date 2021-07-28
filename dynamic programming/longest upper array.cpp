#include <iostream>
using namespace std;
#define MAX 1001
int arr[MAX] = { 0, };
int num[MAX];
int main(void)
{
	int input,max = 0,count=0;
	cin >> input;
	arr[0] = 0;
	num[0] = 0;
	for (int a = 1; a <= input; a++) {
		cin >> num[a];
		max = 0;
		for (int b = 0; b < a; b++) {
			if (num[a] > num[b] && arr[b] >= max)
				max = arr[b];
		}
		arr[a] = max + 1;
	}
	max = 0;
	for (int a = 1; a <= input; a++) {
		if (arr[a] > max) {
			max = arr[a];
		}
	}
	cout << max << endl;
	return 0;

}
