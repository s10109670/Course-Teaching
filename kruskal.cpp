#include <iostream>
#include <algorithm>

using namespace std;
#define MAXM 500
#define MAXN 501

class Edge{
	public:
		int u;
		int v;
		int wei;
};

bool cmp(Edge a, Edge b){
	if(a.wei == b.wei){
		if(a.u + a.v == b.u + b.v)
			return a.u < b.u;
		return a.u+a.v < b.u +b.v;
	}
	return (a.wei < b.wei);
}

int main(){
	int n, m, t;	//vertex_num, edge_num, degree_limit
	cin >> n >> m >> t;
	Edge edges[MAXM];
	/* Input and Preprocessing*/
	for(int i = 0; i < m; i++){
		cin >> edges[i].u >> edges[i].v >> edges[i].wei;
		if(edges[i].u > edges[i].v)
			edges[i].u ^= edges[i].v ^= edges[i].u ^= edges[i].v; //swap
	}
	sort(edges, edges+m, cmp);
	/* Processing */
	Edge answer[MAXM];
	int cnt = 0;
	int weight = 0;
	int head[MAXM] = {0};	//check whether two vertex are in same group
	int degree[MAXM] = {0};
	for(int j = 1; j <= n; j++){
		head[j] = j;
	}
	for(int i = 0; i < m; i++){
		int tmpu = edges[i].u, tmpv = edges[i].v;
		//cout << tmpu << tmpv << endl;
		int headu = head[tmpu], headv = head[tmpv];
		if(head[tmpu] != head[tmpv] && degree[tmpu] <= t && degree[tmpv] <= t){
			//connect
			answer[cnt].u = tmpu;
			answer[cnt].v = tmpv;
			weight += edges[i].wei;
			cnt++;
			for(int j = 1; j <= n; j++){
				if(head[j] == headv)
					head[j] = headu;
			}
		}
	
	}
	cout << weight << '\n';
	for(int i = 0; i < cnt; i++){
		cout << answer[i].u << ',' << answer[i].v << ((i == cnt-1)?'\n':';');
	}
}
