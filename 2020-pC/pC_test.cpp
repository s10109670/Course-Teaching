#include <iostream>

using namespace std;

int main(){
	cout << 100000 << ' ' << 500000 << endl;
	for (int i = 0; i < 100000; i++){
		cout << i << ' ';
	}
	cout << endl;
	for(int i = 0; i < 100000; i++){
		cout << i+5 << ' ';
	}
	cout << endl;
}
