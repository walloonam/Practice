#include <iostream>
#include <cmath>
using namespace std;
#define MAX 101
int weight[MAX] = { 0, };
int value[MAX] = { 0, };
int DP[MAX][100001] = { 0, };
int N, K,maxx=0;
int max(int a, int b) {
	if (a > b)
		return a;
	else
		return b;
}
int main(void)
{
	cin >> N >> K;
	for (int a = 1; a <= N; a++) {
		cin >> weight[a] >> value[a];
	}
	for (int a = 1; a <= N; a++) {
		for (int b = 1; b <= K; b++) {
			if (weight[a] > b)
				DP[a][b] = DP[a - 1][b];
			else
				DP[a][b] = max(DP[a-1][b],value[a]+DP[a-1][b-weight[a]]);
			if (DP[a][b] > maxx)
				maxx = DP[a][b];
		}
	}
	cout << maxx << endl;
	return 0;
}
