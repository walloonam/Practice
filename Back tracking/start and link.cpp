#include <iostream>
#include <cstdlib>
using namespace std;
#define MAX 21
#define TEAM 10
int input;
int arr[MAX][MAX];
int minn = 2000000000;
int minuss;
bool visited[MAX] = { 0, };
int team1[TEAM];
int team2[TEAM];

int point(int a)
{
	int sum = 0;
	if (a == 0) {
		for (int a = 0; a < input / 2; a++) {
			for (int b = 0;b< input / 2; b++) {
				if(!(a==b))
					sum = sum + arr[team1[a]][team1[b]]- arr[team2[a]][team2[b]];
			}
		}
		return sum;
	}
	
}
void check(int count)
{
	if (count == (input / 2)) {
		int b = 0;
		for (int a = 1; a <= input; a++) {
			if (!visited[a]) {
				team2[b]=a;
				b++;
			}
		}
		minuss = abs(point(0));
		if (minuss < minn)
			minn = minuss;
		return;
	}
		
	for (int a = 1; a <= input; a++) {
		if (!visited[a]) {
			team1[count] = a;
			visited[a] = true;
			check(count + 1);
			visited[a] = false;
		}

	}
}
int main(void) 
{
	cin >> input;
	for (int a = 1; a <= input; a++) {
		for (int b = 1; b <= input; b++) {
			cin >> arr[a][b];
		}
	}
	check(0);
	cout << minn << endl;
}
