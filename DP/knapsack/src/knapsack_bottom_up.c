#include <stdio.h>

int Value[501][500001] = {{0}};

int max(int a, int b){
	if(a >= b)
		return a;
	else 
		return b;
}

int main(){
	int N, Wei;
	int v[1000] = {0}, w[1000] = {0};
	//input
	scanf("%d %d", &Wei, &N);
	for(int i = 0; i < N; i++){
		scanf("%d %d", &v[i], &w[i]);
	}
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j <= Wei; j++){
			if(j < w[i])
				Value[i+1][j] = Value[i][j];
			else
				Value[i+1][j] = max(Value[i][j],
					 Value[i][j-w[i]] + v[i]);
		}
	}

	//processing&output
	printf("%d\n", Value[N][Wei]);
#ifdef SHOW
	for(int i = 0; i <= N; i++){
		for(int j = 0; j <= Wei; j++){
			printf((j == Wei)?"%2d\n":"%2d ",
					 Value[i][j]);
		}
	}
	printf("\n");
	printf("Optimal Solution:");
	for(int i = N-1, j = Wei; i >= 0; i--){
		if(Value[i+1][j] == 
				Value[i][j-w[i]] + v[i]){
			printf("%d ", i);
			j -= w[i];
		}
	}
	printf("\n");
#endif
	return 0;
}
