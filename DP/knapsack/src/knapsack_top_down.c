#include <stdio.h>

int Value[501][500001] = {{0}};
int cnt = 0;
int max(int a, int b){
	if(a >= b)
		return a;
	else 
		return b;
}

int Val2(int v[], int w[], int n, int Wei){
	if(Wei < 0){
		return -1e9;
	}
	if(n == 0){
		return 0;
	}
	if(Value[n][Wei] == 0){
		Value[n][Wei] = max(Val2(v, w, n-1, Wei), Val2(v, w, n-1, Wei-w[n]) + v[n]);
		cnt++;
	}
	return Value[n][Wei];
}

int main(){
	int N, Wei;
	int v[501] = {0}, w[501] = {0};
	//input
	scanf("%d %d", &Wei, &N);
	for(int i = 1; i <= N; i++){
		scanf("%d %d", &v[i], &w[i]);
	}

	//processing&output
	printf("%d\n", Val2(v, w, N, Wei));
	printf("%d/%d\n", cnt, N*Wei);	
#ifdef SHOW
	for(int i = 0; i <= N; i++){
		for(int j = 0; j <= Wei; j++){
			printf((j == Wei)?"%2d\n":"%2d ", Value[i][j]);
		}
	}
#endif

	return 0;
}
