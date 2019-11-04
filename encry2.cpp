#include <iostream>
#include <string>

using namespace std;

int main(){
	int n, m;
	char encry[128];
	for(int i = 0; i < 128; i++){
		encry[i] = (char)i;
	}
	ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	cin >> n >> m;
	string msg;
	cin >> msg;
	string before, after;
	cin >> before;
	cin >> after;
	int left = 62;
	for(int i = m-1; i >= 0; i--){
		char b = before[i];
		char a = after[i];
		encry[b] = encry[a];
	}
	for(int i = 0; i < n; i++){
		msg[i] = encry[msg[i]];
	}
	cout << msg << endl;
}
