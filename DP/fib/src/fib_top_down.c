#include <stdio.h>

int f[10000] = {0};

int fib(int n){
	if (n < 0){
		return 0;
	}
	if (f[n] == 0){
		f[n] = (fib(n-1) + fib(n-2)) % 1000000007;
	}
	return f[n];

}


int main(){
	int n;
	f[0] = 1;
	f[1] = 1;
	scanf("%d", &n);
	printf("%d\n", fib(n));
}
