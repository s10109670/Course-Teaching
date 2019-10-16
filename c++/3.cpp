#include<iostream>
using namespace std;

int main(){
	int cnt[10] = {0};
	int n = 0, x = 0;
	cin >> n;
	for(int k = 0; k < n; k++)
	{
		cin >> x;
		if(x >= 100)
			cnt[9]++;
		else
			cnt[x/10]++;
	}
	for(int i = 0; i < 10; i++){
		if (i < 9)
			cout << cnt[i] << ',';
		else
			cout << cnt[i] << endl;
	}
	return 0;

}
