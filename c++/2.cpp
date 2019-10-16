#include<iostream>
using namespace std;

void print(int a[][9]){
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}
int main(){
	int m = 0, n = 0, pos = 0, x = 0, y = 0;
	int a[9][9] = {0};
	cin >> m >> n;
	for(int k = 0; k<m; k++)
	{
		cin >> pos;
		//pos--;
		x = (pos-1) / 7 + 1;
		y = (pos-1) % 7 + 1;
		for(int i = x-1; i <= x + 1; i++)
			for(int j = y-1; j <= y + 1; j++)
				a[i][j] = 1;
 
	}
	//print(a);
	for(int k = 0; k < n; k++)
	{
		cin >> pos;
		x = (pos-1) / 7 + 1;
		y = (pos-1) % 7 + 1;
		for(int i = 0; i < 9; i++)
			a[i][y] = 2;
		for(int j = 0; j < 9; j++)
			a[x][j] = 2;
	}
	//print(a);
	int safeCnt = 0;
	int safe[49] = {0};
	for(int i = 1; i <= 7; i++)
	{
		for(int j = 1; j <= 7; j++)
		{
			if(a[i][j] == 0){
				safe[safeCnt] = (i-1)*7 + j;
				safeCnt++;
			}
		}
	}
	if (safeCnt == 0)
		cout << 0 <<endl;
	for(int i = 0; i < safeCnt; i++)
	{
		if(i < safeCnt-1)
			cout << safe[i] << ',';
		else
			cout << safe[i] << endl;
	}
	return 0;
}
