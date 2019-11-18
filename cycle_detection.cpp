#include <iostream>

using namespace std;

int di[4] = {1,0,-1,0};
int dj[4] = {0,1,0,-1};
void clean(char map[][32], int i, int j){
	if(map[i][j] == '#')
		return;
	map[i][j] = '#';
	for(int d = 0; d < 4; d++){
		clean(map, i+di[d], j+dj[d]);
	}
}

int trace(char map[][32], int i, int j){
	map[i][j] = '#';
	for(int d = 0; d < 4; d++){
		if(map[i+di[d]][j+dj[d]] == '.'){
			return 1+trace(map, i+di[d], j+dj[d]);
		}
	}
	return 1;	
}

int main(){
	int W, H;
	cin >> H >> W;
	char map[32][32];
	for(int i = 0; i < H+2; i++){
		for(int j = 0; j < W+2; j++){
			if(i == 0 || i == H+1 || j == 0 || j == W+1)
				map[i][j] = '#';
			else
				cin >> map[i][j];
		}
	}
	//clean useless garbage
	for(int i = 1; i <= H; i++){
		for(int j = 1; j <= W; j++){
			int nei_cnt = 0;
			int neighbor[4] = {0};
			for(int d = 0; d < 4; d++){
				if(map[i+di[d]][j+dj[d]] == '.')
					neighbor[nei_cnt++] = d;
			}
			if(nei_cnt != 2){
				clean(map, i, j);
			}
		}
	}
	//count
	int cnt = 0, sum = 0;
	unsigned long long int pro = 1;
	int last = -1;
	for(int i = 1; i <= H; i++){
		for(int j = 1; j <= W; j++){
			if(map[i][j] == '.'){
				cnt++;
				int len = trace(map, i, j);
				sum += len;
				pro *= len;
			}
		}
	}
	cout << cnt << ' ' << sum << ' ' << pro << '\n';
}
