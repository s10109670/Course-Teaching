#include <iostream>

using namespace std;

int main(){
	int a[3][2] = {{1}, {3,4}, {5, 6}};
	//int a[3][2] = {1,2,3,4,5,7};
	//cout << a[0][1] << '\n';
	cout << a << " " << &a[0] << '\n';
	cout << a[0] << " " << &a[0][0] << '\n';
	cout << a+1 << " " << &a[1] << '\n';
	cout << *(a+1) << " " << a[1] << '\n';

	cout << a[1] - a[0] << '\n';
	cout << &a[1][0] - &a[0][0] << '\n';
	cout << &a[1] - &a[0] << '\n';
	cout << a+1 - a << '\n'; 
	//int *p = a;
	//cout << *(p+1) << '\n';
}
