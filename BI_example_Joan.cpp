#include <iostream>
#include <string.h>
using namespace std;
#define MAXD 128

class BigInt{
private:
        int num[MAXD] = {0};
        int digit = 0;
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
        BigInt(char* s){
                digit = strlen(s);
                for(int i = 0; i < digit; i++){
                        num[i] = s[digit-i-1]-'0';
                }
        }
        ~BigInt(){}
        char* show(){
                char* s = new char[MAXD+1];
                if (digit == 0){
                        digit++;
                }
                for(int i = 0; i < digit; i++){
                        s[i] = (num[digit-i-1]+'0');
                }
                s[digit] = '\0';
                return s;
        }
		void print(){
			cout << show() << '\n';
		}
        void add(BigInt b){
                int md = (b.digit > digit)? b.digit : digit;
                for(int i = 0; i < md; i++){
                        num[i] = num[i] + b.num[i];
                }
                maintain();
				return;
        }
        void substract(BigInt b){
                int md = digit;
                for(int i = 0; i < md; i++){
                        num[i] = num[i] - b.num[i];
                }
                maintain();
                return;
        }
};

int main(){
	//Example
	BigInt a("1234567890");
	a.print();
	BigInt b("9");
	a.add(b);
	a.print();
	a.substract(b);
	a.print();	

	char str[256];
	while(cin.getline(str, 256)){
		//string process and calculate
	}
}
