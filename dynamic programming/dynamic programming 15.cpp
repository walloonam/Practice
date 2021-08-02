#include<iostream>
#include<vector>
using namespace std;
#define MAX 100001
vector<int>v1(MAX,0);
vector<int>v2(MAX,0);

int main(void)
{
	int input,maxx=-1000,sum=0;
	cin >> input;
	for (int a = 1; a <= input; a++) {
		cin >> v1[a];
	}
	v2[1] = v1[1];
	maxx = v1[1];
	for (int a = 1; a <= input; a++) {
		if (v2[a - 1] < 0) {
			v2[a] = v1[a];
			if (v2[a] > maxx)
				maxx = v2[a];
		}
		else {
			v2[a] = v1[a] + v2[a - 1];
			if (v2[a] > maxx)
				maxx = v2[a];
		}
		
	}
	cout << maxx << endl;
	return 0;
}

