#include <iostream>

using namespace std;

void convert(int num[], string s, int &d){
	d = s.length();
	for(int i = 0; i < d; i++){
		num[i] = s[d-i-1]-'0';
	}
	for(int i = d; i < 505; i++)
		num[i] = 0;
	return;
}

void print(int num[], int d){
	for(int i = d-1; i >= 0; i--){
		cout << num[i];
	}
	cout << endl;
}

void add(int ans[], int n1[], int n2[], int d1, int d2, int &d_ans){
	d_ans = (d1 > d2)?d1:d2;
	for(int i = 0; i < d_ans; i++){
		ans[i] = n1[i] + n2[i];
	}
	for(int i = 0; i < d_ans; i++){
		ans[i+1] += ans[i]/10;
		ans[i] %= 10;
	}
	if(ans[d_ans]){
		d_ans++;
	}
}
void sub(int ans[], int n1[], int n2[], int d1, int d2, int &d_ans){
	d_ans = d1;
	for(int i = 0; i < d_ans; i++){
		ans[i] = n1[i] - n2[i];
	}
	for(int i = 0; i < d_ans; i++){
		if(ans[i] < 0){
			ans[i+1]--;
			ans[i] += 10;
		}
	}
	while(d_ans > 1 && !ans[d_ans-1]){
		d_ans--;
	}
}
void mul(int ans[], int n1[], int n2[], int d1, int d2, int &d_ans){
	d_ans = d1 + d2 - 1;
	for(int i = 0; i < d1; i++){
		for(int j = 0; j < d2; j++){
			ans[i+j] += n1[i]*n2[j];
		}
	}
	for(int i = 0; i < d_ans; i++){
		ans[i+1] += ans[i]/10;
		ans[i] %= 10;
	}
	if(ans[d_ans]){
		d_ans++;
	}
}

bool bigger(int n1[], int n2[], int shift, int d1, int d2){
	if(d2+shift > d1)
		return false;
	else if(d2+shift < d1)
		return true;
	for(int i = d2-1; i >= 0; i--){
		if(n1[i+shift] > n2[i])
			return true;
		else if(n1[i+shift] < n2[i])
			return false;
	}
	return true;
}
void div(int ans[], int n1[], int n2[], int d1, int d2, int &d_ans){
	d_ans = d1 - d2 + 1;
	if(d_ans < 1){
		d_ans = 1;
		ans[0] = 0;
		return;
	}
	// copy n1 to a tmp;
	int n_tmp[500] = {0};
	for(int i = 0; i < d1; i++)
		n_tmp[i] = n1[i];
	
	for(int i = d_ans-1; i >= 0; i--){
		while (bigger(n_tmp, n2, i, d1, d2)){
			ans[i]++;
			for(int j = 0; j < d2; j++){
				n_tmp[j+i] -= n2[j];
			}
			for(int j = 0; j < d2; j++){
				if(n_tmp[j+i] < 0){
					n_tmp[j+i+1]--;
					n_tmp[j+i] += 10;
				}
			}
			while(d1 > 1 && !n_tmp[d1-1]){
				d1--;
			}
		}
	}
	if(d_ans > 1 && !ans[d_ans-1]){
		d_ans--;
	}
}


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	string input;
	string s1, s2;
	char op;
	while(cin >> s1 >> op >> s2){
		int n1[501] = {0};
		int n2[501] = {0};
		int ans[501] = {0};
		int d1, d2, d_ans;
		convert(n1, s1, d1);
		convert(n2, s2, d2);
		if(op == '+')
			add(ans, n1, n2, d1, d2, d_ans);
		else if(op == '-'){
			if(bigger(n1, n2, 0, d1, d2))
				sub(ans, n1, n2, d1, d2, d_ans);
			else{
				cout << '-';
				sub(ans, n2, n1, d2, d1, d_ans);
			}
		}
		else if(op == '*')
			mul(ans, n1, n2, d1, d2, d_ans);
		else
			div(ans, n1, n2, d1, d2, d_ans);
		print(ans, d_ans);
	}
}
