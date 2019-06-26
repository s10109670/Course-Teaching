#include <stdio.h>


int max(int a, int b){
	if(a >= b)
		return a;
	else 
		return b;
}

int Val(int v[], int w[], int n, int Wei){
	if(n == 0){
		return 0;
	}
	//can't get i-th
	if(Wei < w[n]){
		return Val(v, w, n-1, Wei);
	}
	return max(Val(v, w, n-1, Wei), Val(v, w, n-1, Wei-w[n]) + v[n]);
}

int Val2(int v[], int w[], int n, int Wei){
	if(Wei < 0){
		return -1e9;
	}
	if(n == 0){
		return 0;
	}
	return max(Val2(v, w, n-1, Wei), Val2(v, w, n-1, Wei-w[n]) + v[n]);
}

int main(){
	int N, Wei;
	int v[1001] = {0}, w[1001] = {0};
	//input
	scanf("%d %d", &Wei, &N);
	for(int i = 1; i <= N; i++){
		scanf("%d %d", &v[i], &w[i]);
	}

	//processing&output
	printf("%d\n", Val(v, w, N, Wei));
	//printf("%d\n", Val2(v, w, N, Wei));

	return 0;
}
