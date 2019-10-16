#include<iostream>
using namespace std;

int main(){
	int T = 1;
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0, x3 = 0, y3 = 0, x4 = 0, y4 = 0;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
	/* 我希望依照1234順序  x1 == x2; y1 == y4 */
	int tmp;
	if(x1 != x2){
		tmp = x2;
		x2 = x3;
		x3 = tmp;
		tmp = y2;
		x2 = y3;
		y3 = tmp;
	}
	if(x1 != x2){
		tmp = x2;
		x2 = x4;
		x4 = tmp;
		tmp = y2;
		y2 = y4;
		y4 = tmp;
	}
	if(y1 != y4){
		tmp = x4;
		x4 = x3;
		x3 = tmp;
		tmp = y4;
		y4 = y3;
		y3 = tmp;
	}
	if(x1 == x2 && x3 == x4 && y1==y4 && y2 == y3){		//是矩形
		int dx = x1 - x4;
		if(dx < 0)
			dx = -dx;
		int dy = y1 - y2;
		if(dy < 0)
			dy = -dy;
		if(dx == dy){
			cout << 1 << endl;
		}
		else
			cout << 2 << endl;
	}
	else
		cout << 0 << endl;
	return 0;
}
