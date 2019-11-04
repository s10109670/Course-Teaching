#include <iostream>
#include <string>

using namespace std;

int main(){
	int n, m;
	char encry[128];
	string follower[128];
	for(int i = 0; i < 128; i++){
		encry[i] = (char)i;
		follower[i] += i;
	}
	cin >> n >> m;
	string msg;
	cin >> msg;
	string before, after;
	cin >> before >> after;
	for(int i = 0; i < m; i++){
		char b = before[i];
		char a = after[i];
		if(b!=a){
			for(int j = 0; j < follower[b].length(); j++){
				encry[follower[b][j]] = a;
			}
			follower[a] += follower[b];
			follower[b] = "";
		}
		
	}
	for(int i = 0; i < n; i++){
		msg[i] = encry[msg[i]];
	}
	cout << msg << endl;
}
