#include<stdio.h>


unsigned long long int factorial(int n){
	if(n < 0){
		return 0;
	}
	if(n == 0){
		return 1;
	}
	return n * factorial(n-1) % 1000000007;
}

int main(){
	int n;
	scanf("%d", &n);
	printf("%llu\n", factorial(n));
	return 0;
}
