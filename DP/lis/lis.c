#include <stdio.h>

int lis(){
}

int main(){
	int N;
	int score[101] = {0};
	scanf("%d", &N);
	for(int i = 1; i <= N; i++){
		scanf("%d", &score[i]);
	}
	int longest[101] = {0};
	for(int i = 1; i <= N; i++){
		for(int j = 0; j < i; j++){
			if(score[j] < score[i] && longest[j]+1 > longest[i]){
				longest[i] = longest[j]+1;
			}
		}
	}
	int max = 0;
	for(int i = 1; i <= N; i++){
		if(longest[i] > max)
			max = longest[i];
	}
	printf("%d\n", max);
}
