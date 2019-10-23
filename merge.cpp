#include<iostream>
using namespace std;

const int MAX = 1000001; 

int ans[MAX] = {0};
int main()
{
	int n1, n2;
	int x[MAX] = {0}, y[MAX] = {0};
	/* Input */
	cin >> n1;
	for(int i = 0; i < n1; i++)
	{
		cin >> x[i];
	}
	cin >> n2;
	for(int i = 0; i < n2; i++)
	{
		cin >> y[i];
	}
	/* Processing */
	x[n1] = MAX;	//infinity
	y[n2] = MAX;	//infinity
	int pos_x = 0;
	int pos_y = 0;
	int cnt = 0;
	while(pos_x < n1 || pos_y < n2)
	{
		if(x[pos_x] <= y[pos_y]){
			ans[cnt] = x[pos_x];
			pos_x++;
		}
		else{
			ans[cnt] = y[pos_y];
			pos_y++;
		}
		while(x[pos_x] == ans[cnt])
			pos_x++;
		while(y[pos_y] == ans[cnt])
			pos_y++;
		cnt++;
	}
	/* Output */
	for(int k = 0; k < cnt; k++)
	{
		if(k < cnt-1)
			cout << ans[k] << ",";
		else
			cout << ans[k] << endl;
	}
	return 0;
}
