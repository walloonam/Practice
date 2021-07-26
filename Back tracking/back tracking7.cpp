#include<iostream>
using namespace std;
#define MAX 11
int OP[4];
int minn = 1000000000;
int maxx = -1000000000;
int input;
int num[MAX] = { 0, };
int num2[MAX - 1] = { 0, };
bool visited[MAX] = { 0, };
int sum[MAX];
void check(int count) {
	if (count == (input-1)) {
		if (sum[count] > maxx)
			maxx = sum[count];
		if (sum[count] < minn)
			minn = sum[count];
		return;
	}for (int i=0; i < input - 1; i++) {
		if (!visited[i]) {
			switch (num2[i]) {
			case 0: sum[count+1] = sum[count] + num[count+1];
				break;
			case 1: sum[count+1] = sum[count] - num[count+1];
				break;
			case 2: sum[count+1] = sum[count] * num[count+1];
				break;
			case 3: sum[count+1] = sum[count] / num[count+1];
				break;
			}
			visited[i] = true;
			check(count + 1);
			visited[i] = false;
		}
	}
}
int main(void) {
	cin >> input;
	int c=0;
	for (int a = 0; a < input; a++) {
		cin >> num[a];
	}

	for (int a = 0; a < 4; a++) {
		cin >> OP[a];
		for (int b = 0; b < OP[a]; b++) {
			num2[c] = a;
			c++;
		}
	}
	sum[0] = num[0];
	check(0);
	cout << maxx << endl << minn << endl;

	return 0;
}