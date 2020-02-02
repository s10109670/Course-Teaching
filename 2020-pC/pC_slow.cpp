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
	int next[MAXN+2] = {0};
	for(int i = 1; i <= N; i++){
		cin >> c[i];
	}
	c[N+1] = L;
	for(int i = 1; i <= N; i++){
		cin >> h[i];
	}
	for(int i = 0; i <= N+1; i++){
		last[i] = i-1;
		next[i] = i+1;
	}
	/* Processing */
	int cnt = 0, maxh = 0;
	int converge = false;
	while (!converge){
		converge = true;
		for(int i = next[0]; i <= N; i = next[i]){
			if(c[i] + h[i] <= c[next[i]] || c[i]-h[i] >= c[last[i]]){
				if(maxh < h[i])
					maxh = h[i];
				cnt++;
				//chop tree[i]
				last[next[i]] = last[i];
				next[last[i]] = next[i];
				converge = false;
				//cout << c[i]<< endl;
			}
		}
	}
	/* Output */
	cout << cnt << '\n' << maxh << endl;
}

