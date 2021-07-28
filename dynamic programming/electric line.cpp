#include<iostream>
using namespace std;
#define MAX 500+1
int arr[MAX] = { 0 , };
int DP[MAX] = { 0, };
int main(void)
{
	int input, num, max;
	cin >> input;
	for (int a = 0; a < input; a++) {
		cin >> num;
		cin >> arr[num];
	}
	for (int a = 0; a < MAX; a++) {
		if (!(arr[a] == 0)) {
			max = 0;
			for (int b = 0; b < a; b++) {
				if (arr[a] > arr[b] && DP[b] >= max)
					max = DP[b];
			}
			DP[a] = max + 1;
		}
	}
	max = 0;
	for (int a = 0; a < MAX; a++) {
		if (max < DP[a])
			max = DP[a];
	}
	cout << input - max << endl;
}
