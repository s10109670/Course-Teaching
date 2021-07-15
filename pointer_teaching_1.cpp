#include <iostream>

using namespace std;

void add(int *p){
	(*p)++;
}

int main(){
	int n = 10;
	int *p = &n;
	int m = n;
	//cout << sizeof(p) << " " << sizeof(q) << '\n';
	(*p)++;
	m++;
	int *q = p;
	(*q)++;
	add(&n);

	cout << &n << '\n';
	cout << p << " " << *p << '\n';
	cout << &p << '\n';

	return 0;
}
