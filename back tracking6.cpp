#include <iostream>
#include <vector>
using namespace std;
#define MAX 9
int sudoku[MAX][MAX];				//sudoku
bool col[MAX][MAX + 1];				//check the number of column
bool row[MAX][MAX + 1];				//check the number of row
bool square[MAX][MAX + 1];			//check the number of square

int CheckSquare(int a, int b) {
	return (a / 3) * 3 + b/3;
}
void CheckSudoku(int cnt)
{
	if (cnt == 81) {
		for (int a = 0; a < MAX; a++) {					//if sudoku is filled then print it
			for (int b = 0; b < MAX; b++) {									
				cout << sudoku[a][b]<<' ';
			}
			cout << endl;
		}
		exit(0);
	}
	int y = cnt / 9;								
	int x = cnt % 9;
	if (sudoku[y][x])
		CheckSudoku(cnt + 1);
	else {
		for (int c = 1; c < (MAX + 1); c++) {							//fill in if you meet the conditions.		
			if (!col[y][c] && !row[x][c] && !square[CheckSquare(y, x)][c]) {
				col[y][c] = true;
				row[x][c] = true;
				square[CheckSquare(y, x)][c] = true;
				sudoku[y][x] = c;
				CheckSudoku(cnt + 1);
				col[y][c] = false;
				row[x][c] = false;
				square[CheckSquare(y, x)][c] = false;
				sudoku[y][x] = 0;

			}
		}
	}
}
int main(void) {
	for (int a = 0; a < MAX; a++) {
		for (int b = 0; b < MAX; b++) {
			cin >> sudoku[a][b];
			col[a][sudoku[a][b]] = true;
			row[b][sudoku[a][b]] = true;
			square[CheckSquare(a,b)][sudoku[a][b]] = true;
		}
	}
	CheckSudoku(0);
	return 0;
}