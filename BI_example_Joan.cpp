#include <iostream>
#include <cstring>
using namespace std;
#define MAXD 128

class BigInt{
private:
	int* num;
	int digit;
	bool neg;
	void maintain(){
		for(int i = 0; i < MAXD; i++){
			while(num[i] < 0){
				num[i+1] --;
				num[i] += 10;
			}
			while(num[i] >= 10){
				num[i+1] ++;
				num[i] -= 10;
			}
		}
		for(int i = MAXD-1; i >= 0; i--){
			if(num[i] > 0){
				digit = i+1;
				break;
			}
		}
	}
public:
	char name[16] = "";
	BigInt(){
		digit = 0;
	}
	BigInt(char* s, char* n){
		num = new int[MAXD]();
		if(*s == '-'){
			neg = true;
			s++;
		}
		digit = strlen(s);
		for(int i = 0; i < digit; i++){
			num[i] = s[digit-i-1]-'0';
		}
		strcpy(name, n);
	}
	~BigInt(){
		delete[] num;
	}
	void print(){
		char* s = new char[MAXD+1];
		if (digit == 0){
			digit++;
		}
		for(int i = 0; i < digit; i++){
			s[i] = (num[digit-i-1]+'0');
		}
		s[digit] = '\0';
		if(neg)
			cout << '-';
		cout << s << '\n';
		delete s;
		return;
	}
	void abs(){
		neg = false;
		return;
	}
	void negate(){
		neg = !neg;
		return;
	}
	void add(BigInt b){
		int md = (b.digit > digit)? b.digit : digit;
		for(int i = 0; i < md; i++){
			num[i] = num[i] + b.num[i];
		}
		maintain();
		return;
	}
	void subtract(BigInt b){
		int md = digit;
		for(int i = 0; i < md; i++){
			num[i] = num[i] - b.num[i];
		}
		maintain();
		return;
	}
};

int find_index(BigInt var_array[], int cnt, char* name);

int main(){
	//Example
/*	BigInt i("-9876543210");
	BigInt j("7465");
	BigInt k("0");
	i.add(j);
	k.print();
	BigInt m("12345");
	m.print();
	j.negate();
	i.abs();
	j.print();
	i.print();
*/	
	int var_cnt = 0;
	BigInt var_arr[16];
	char str[256];
	while(cin.getline(str, 256)){
		if(strncmp("BigInt ", str, 7) == 0){ //construct
			char*name = strtok(str+7, "(");
			char*value = strtok(NULL, ")");
			var_arr[var_cnt] = BigInt(value, name);
			var_cnt++;
		}
		else{
			char* name = strtok(str, ".");
			int i = find_index(var_arr, var_cnt, name);
			char* function = strtok(NULL, "(");
			char* value = strtok(NULL, ")");
			if(strcmp("print", function) == 0){
				var_arr[i].print();
			}
			else if(strcmp("add", function) == 0){
				int j = find_index(var_arr, var_cnt, value);
				var_arr[i].add(var_arr[j]);
			}
			else if(strcmp("subtract", function) == 0){
				int j = find_index(var_arr, var_cnt, value);
				var_arr[i].subtract(var_arr[j]);
			}
			else if(strcmp("negate", function) == 0){
				var_arr[i].negate();
			}
			else if(strcmp("abs", function) == 0){
				var_arr[i].abs();
			}
		}
	}
}

int find_index(BigInt var_array[], int cnt, char* name){
	for(int i = 0; i < cnt; i++){
		if(strcmp(name, var_array[i].name) == 0)
			return i;
	}
	return -1;
}
