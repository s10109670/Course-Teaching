#include <iostream>

using namespace std;

int main(){
	int n, m;
	char table[128];
	for(char i = 0; i < 128; i++){
		table[i] = i;
	}
	cin >> n >> m;
	cout << "read"<<endl;
	string msg;
	cin >> msg;
	string before,after;
	cin >> before >> after;
	cout << "read"<<endl;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < 128; j++){
			if(table[j] == before[i]){
				table[j] = after[i];
			}
		}
	}
	for(int i = 0; i < n; i++){
		msg[i] = table[msg[i]];
	}
	cout << msg << endl;
}
