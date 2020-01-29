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
		int next = i+1; //next[i] is always i+1
		if(c[i] + h[i] <= c[next] || c[i]-h[i] >= c[last[i]]){
			if(maxh < h[i])
				maxh = h[i];
			cnt++;
			//chop tree[i]
			last[next] = last[i];
			//chop back
			int p = last[i];
			while(p != 0 && c[p]+h[p] <= c[next]){
				if(maxh < h[p])
					maxh = h[p];
				cnt++;
				last[next] = last[p];
				p = last[p];
			}
		}
	}

	/* Output */
	cout << cnt << '\n' << maxh << endl;
}

