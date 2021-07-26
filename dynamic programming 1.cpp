
#include <iostream>
using namespace std;

int main()
{
	int arr[41][2];
	arr[0][0] = 1;
	arr[0][1] = 0;
	arr[1][0] = 0;
	arr[1][1] = 1;
	for (int a = 2; a < 41; a++) {
		arr[a][0] = arr[a - 1][0] + arr[a - 2][0];
		arr[a][1] = arr[a - 1][1] + arr[a - 2][1];
	}
	int num;
	cin >> num;
	int *arr1 = new int[num];
	for (int a = 0; a < num; a++ ) {
		cin >> arr1[a];
	}
	for (int a = 0; a < num; a++) {
		cout << arr[arr1[a]][0] << " " << arr[arr1[a]][1] << endl;
	}
	delete[] arr1;
	return 0;
}
