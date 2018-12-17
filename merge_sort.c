#include <stdio.h>

#define MAX_INT 1000000


void merge(int arr[], int l, int r,int m){
	/* print array before sorting*/
	/*
	printf("Before sorting:");
	for(int i = l; i < r; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	*/
	
	/* move array to Left and Right subarray */
	int n1 = m - l;
	int n2 = r - m;
	int L[n1+1], R[n2+1];
	for(int i = 0; i < n1; i++){
		L[i] = arr[l+i];
	}
	L[n1] = MAX_INT;		//sentinel
	for(int j = 0; j < n2; j++){
		R[j] = arr[m+j];
	}
	R[n2] = MAX_INT;		//sentinel
	
	/* merge */
	for(int i = 0, j = 0, k = l; k < r; k++){
		if(L[i] < R[j]){
			arr[k] = L[i];
			i++;
		}
		else{
			arr[k] = R[j];
			j++;
		}
	}
	
	/* print array after sorting*/
	/*
	printf("After sorting:");
	for(int i = l; i < r; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	*/
	return;
}

void merge_sort(int arr[], int l, int r){ // by recursive (top down)
	if(r == l+1) return;
	int m = (l+r)/2;
	//printf("l = %d, m = %d, r = %d\n", l, m, r);
	merge_sort(arr, l, m);
	merge_sort(arr, m, r);

	merge(arr, l, r, m);
}

void merge_sort2(int arr[], int l, int r){	// by iterative (bottom up)
	int n = r-l;
	int blocksize = 1;	// # of elements in L/R subarray
	while(blocksize < n){
		for(int newl = l; newl < r; newl+= 2*blocksize){
			int newr = newl + 2*blocksize;
			if (newr > r) newr = r;
			int newm = newl + blocksize;
			if (newm > r) newm = r;
			merge(arr, newl, newr, newm);
		}
		blocksize *= 2;
	}
}

int main(){
	int a[8] = {1, 3, 5, 6, 2, 4, 7, 8};
	merge(a, 0, 8, 4);
	//merge_sort(a, 0, 8);
	
	int b[100];
	for(int i = 0; i < 100; i++){
		b[i] = 100-i;
	}
	
	merge_sort2(b, 0, 100);
	for(int i = 0; i < 100; i++){
		printf((i == 99)?"%d\n":"%d ", b[i]);
	}
}
