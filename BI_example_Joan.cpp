#include <iostream>
#include <cstring>
using namespace std;
#define MAXD 128

class BigInt{
private:
	int* num; 
	int digit;
	int sign = 1; // 1 for positive, -1 for negative
	void maintain(){
		//let every digit between -9 to 9
		for(int i = 0; i < MAXD; i++){
			num[i+1] += num[i] / 10;
			num[i] %= 10;
		}
		// if num[max_digit-1] < 0 => the value is negative
		int md;
		for(md = MAXD; md > 0 && num[md] != 0; md--){
			if(num[md-1] < 0){
				sign = -1;
			}
		}
		//make the value of num positive
		for(int i = md-1; i >= 0; i--){
			num[i] *= sign;
		}
		//let every bit between 0 to 9
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
		//find maxdigit
		digit = 1;
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
		num = new int[MAXD]();
		digit = 0;
	}
	BigInt(char* s, char* n){
		num = new int[MAXD]();
		if(*s == '-'){
			sign = -1;
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
		if(sign == -1)
			cout << '-';
		if(digit == 0){
			digit++;
		}
		else{
			for(int i = digit - 1; i >= 0; i--){
				if(i%3 == 0 && i != 0)
					cout << num[i] << ',';
				else
					cout << num[i];
			}
		}
		cout << '\n';
		return;
	}
	void abs(){
		sign = 1;
		return;
	}
	void negate(){
		sign *= -1;
		return;
	}
	void add(const BigInt &b){
		int md = (b.digit > digit)? b.digit : digit;
		for(int i = 0; i < md; i++){
			num[i] = num[i]*sign + b.num[i]*b.sign;
		}
		maintain();
		return;
	}
	void subtract(const BigInt &b){
		int md = digit;
		for(int i = 0; i < md; i++){
			num[i] = num[i]*sign - b.num[i]*b.sign;
		}
		maintain();
		return;
	}
};

int find_index(BigInt* var_array[], int cnt, char* name);

int main(){
	int var_cnt = 0;
	BigInt* var_arr[50];
	char str[256];
	while(cin.getline(str, 256)){
		if(strncmp("BigInt ", str, 7) == 0){ //construct: BigInt name(value)
			char*name = strtok(str+7, "(");
			char*value = strtok(NULL, ")");
			var_arr[var_cnt] = new BigInt(value, name);
			var_cnt++;
		}
		else{		//method: name.function(value);
			char* name = strtok(str, ".");
			int i = find_index(var_arr, var_cnt, name);
			if(i < 0)
				continue;
			char* function = strtok(NULL, "(");
			char* value = strtok(NULL, ")");
			if(strcmp("print", function) == 0){
				var_arr[i]->print();
			}
			else if(strcmp("add", function) == 0){
				int j = find_index(var_arr, var_cnt, value);
				if(j < 0)
					continue;
				var_arr[i]->add(*(var_arr[j]));
			}
			else if(strcmp("subtract", function) == 0){
				int j = find_index(var_arr, var_cnt, value);
				if(j < 0)
					continue;
				var_arr[i]->subtract(*(var_arr[j]));
			}
			else if(strcmp("negate", function) == 0){
				var_arr[i]->negate();
			}
			else if(strcmp("abs", function) == 0){
				var_arr[i]->abs();
			}
		}
	}
	for(int i = 0; i < var_cnt; i++){
		delete var_arr[i];
	}
}

int find_index(BigInt* var_array[], int cnt, char* name){
	for(int i = 0; i < cnt; i++){
		if(strcmp(name, var_array[i]->name) == 0)
			return i;
	}
	return -1;
}
