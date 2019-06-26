#include <stdio.h>

int f[10001] = {0};

int main(){
	int n;
	scanf("%d", &n);
	f[0] = 1;
	f[1] = 1;
	for(int i = 2; i <= n; i++){
		f[i] = (f[i-1]+f[i-2]) % 1000000007;
	}
	printf("%d\n", f[n]);
}
