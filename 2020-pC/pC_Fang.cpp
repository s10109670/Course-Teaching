#include <iostream>

using std::cin;
using std::cout;

int cnt = 0 , max_h = 0;
void chop(int n, int i, int next[], int last[], int c[], int h[]){
	if(i==0 || next[i]==n+2)
		return;
	if(c[i]+h[i] <= c[next[i]] || c[i]-h[i] >= c[last[i]]){
		next[last[i]] = next[i];
		last[next[i]] = last[i];
		if(h[i] > max_h)
			max_h = h[i];
		cnt++;
		chop(n,last[i],next,last,c,h); //#2
	}
}

int main(){
	int h[100005] = {0},c[100005] = {0};  //#3
	int next[100005] = {0}, last[100005] = {0};
	int n,l;
	cin >> n >> l;
	for(int i = 1; i <= n; i++)
		cin >> c[i];
	c[n+1] = l;			//#1
	for(int i = 1; i <= n; i++)
		cin >> h[i];

	for(int i = 0; i < n+2; i++){
		next[i] = i+1;
		last[i] = i-1;
	}

	for(int i=1;i<=n+1;i++){
		chop(n, i, next, last, c, h);
	}

	if(cnt == 0)
		cout << 0 << '\n' << 0 << '\n';
	else
		cout << cnt << '\n' << max_h << '\n';
}
