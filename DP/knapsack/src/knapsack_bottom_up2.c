#include <stdio.h>

int Value[5000001] = {0};

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
		int we = w[i];
		int co = v[i];
		for(int j = Wei; j >= we && j >= 0; j--){
			//printf("%d %d\n", i, j);
			Value[j] = max(Value[j], Value[j-we] + co);
		}
	}

	//processing&output
	printf("%d\n", Value[Wei]);
#ifdef SHOW
	for(int j = 0; j <= Wei; j++){
		printf((j == Wei)?"%2d\n":"%2d ", Value[j]);
	}
#endif

	return 0;
}
