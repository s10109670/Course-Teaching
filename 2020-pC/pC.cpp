#include <iostream>

#define MAXN 100005
using namespace std;
int main(){
	int N, L;
	cin >> N >> L;
	/* Inintialize and Input */
	int c[MAXN+2] = {0};
	int h[MAXN+2] = {0};
	int last[MAXN+2] = {0};
	for(int i = 1; i <= N; i++){
		cin >> c[i];
	}
	for(int i = 1; i <= N; i++){
		cin >> h[i];
	}
	for(int i = 1; i <= N; i++){
		last[i] = i-1;
	}
	/* Processing */
	int cnt = 0, maxh = 0;
	for(int i = 1; i <= N; i++){
		int p = i, next = i+1; //next[i] is always i+1
		while(p != 0 && (c[p] + h[p] <= c[next] || c[p]-h[p] >= c[last[p]])){
			if(maxh < h[p])
				maxh = h[p];
			cnt++;
			//chop tree[p]
			last[next] = last[p];
			//chop back
			p = last[p];
		}
	}
	/* Output */
	cout << cnt << '\n' << maxh << endl;
}

