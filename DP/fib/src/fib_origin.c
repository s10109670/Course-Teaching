


#include <stdio.h>

int fib(int n){
	if (n < 0)
		return 0;
	if(n == 0 || n == 1)
		return 1;
	return (fib(n-1) + fib(n-2)) % 1000000007;
}

int main(){
	int n;
	scanf("%d", &n);
	printf("%d\n", fib(n));
}
