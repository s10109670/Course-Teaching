#include <iostream>
#include <string.h>

#define MAXD 200

class bigInt{
private:
        int n[MAXD] = {0};
        int maxdigit = 0;
        void maintain(){
                for(int i = 0; i < MAXD; i++){
                        while(n[i] < 0){
                                n[i+1] --;
                                n[i] += 10;
                        }
                        while(n[i] >= 10){
                                n[i+1] ++;
                                n[i] -= 10;
                        }
                }
                for(int i = MAXD-1; i >= 0; i--){
                        if(n[i] > 0){
                                maxdigit = i+1;
                                break;
                        }
                }
        }
public:
        bigInt(){
                maxdigit = 0;
        }
        bigInt(char* s){
                maxdigit = strlen(s);
                for(int i = 0; i < maxdigit; i++){
                        n[i] = s[maxdigit-i-1]-'0';
                }
        }
        bigInt(bigInt *bi){
                maxdigit = bi->maxdigit;
                for(int i = 0; i < MAXD; i++){
                        n[i] = bi->n[i];
                }
        }
        bigInt(int num){
                maxdigit = 0;
                while(num > 0){
                        n[maxdigit++] = num % 10;
                        num /= 10;
                }
        }
        ~bigInt(){}
        char* show(){
                char* s = new char[MAXD+1];
                if (maxdigit == 0){
                        maxdigit++;
                }
                for(int i = 0; i < maxdigit; i++){
                        s[i] = (n[maxdigit-i-1]+'0');
                }
                s[maxdigit] = '\0';
                return s;
        }
        bool operator<(const bigInt &b)const{
                if(maxdigit < b.maxdigit)
                        return true;
                if(maxdigit > b.maxdigit)
                        return false;
                for(int i = maxdigit-1; i >= 0; i--){
                        if(n[i] < b.n[i])
                                return true;
                }
                return false;
        }
        bigInt operator << (const int &d)const{
                bigInt tmp;
                tmp.maxdigit = maxdigit+d;
                for(int i = 0; i < maxdigit && i < MAXD; i++){
                        tmp.n[i+d] = n[i];
                }
                return tmp;
        }
        bigInt operator+(const bigInt &b){
                bigInt tmp;
                int md = (b.maxdigit > maxdigit)?b.maxdigit:maxdigit;
                for(int i = 0; i < md; i++){
                        tmp.n[i] = n[i] + b.n[i];
                }
                tmp.maintain();
                return tmp;
        }
        bigInt operator-(const bigInt &b){
                bigInt tmp;
                int md = maxdigit;
                for(int i = 0; i < md; i++){
                        tmp.n[i] = n[i] - b.n[i];
                }
                tmp.maintain();
                return tmp;
        }
        bigInt operator*(const bigInt &b) {
                bigInt tmp;
                for(int i = 0; i < maxdigit; i++){
                        for(int j = 0; j < b.maxdigit; j++)
                                tmp.n[i+j] += n[i] * b.n[j];
                }
                tmp.maintain();
                return tmp;
        }
        bigInt operator*(const int &p) {
                bigInt tmp;
                for(int i = 0; i < maxdigit; i++){
                        tmp.n[i] = n[i] * p;
                }
                tmp.maintain();
                return tmp;
        }
        bigInt operator/(const bigInt &b) {
                bigInt t = new bigInt(this);
                bigInt tmp;
                for(int i = t.maxdigit - b.maxdigit; i >= 0; i--){
                        bigInt newb(b << i);
                        while(!(t < newb)){
                                t = t - newb;
                                tmp.n[i]++;
                        }
                }
                tmp.maintain();
                return tmp;
        }
};

int main(){
        char a[MAXD] = {'\0'}, b[MAXD] = {'\0'};
        char op;
        while(scanf("%s %c %s", a, &op, b) == 3){
                bigInt A(a);
                bigInt B(b);
                char* s;
                if(op == '+'){
                        s = (A+B).show();
                }
                else if(op == '-'){
                        if(A<B){
                                s = (B-A).show();
                                printf("-%s\n", s);
                                delete s;
                                continue;
                        }
                        else
                                s = (A-B).show();
                }
                else if(op == '*'){
                        s = (A*B).show();
                }
                else{ // divide
                        s = (A/B).show();
                }
                printf("%s\n", s);
                delete s;
        }
        return 0;
}
