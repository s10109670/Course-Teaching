#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct Treenode{
	int value;
	int left, right;
};

Treenode tree[1005] = {{0}};
int cnt = 0;

int insert(int root, int v){
	if(root == 0){
		cnt++;
		tree[cnt].value = v;
		return cnt;
	}
	if(v > tree[root].value){
		tree[root].right = insert(tree[root].right, v);
		return root;
	}
	else{
		tree[root].left = insert(tree[root].left, v);
		return root;
	}
}

void level(int root){
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int r = q.front();
		cout << tree[r].value << ' ';
		q.pop();
		if(tree[r].left)
			q.push(tree[r].left);
		if(tree[r].right)
			q.push(tree[r].right);
	}
	cout << '\n';
}

void postorder(int root){
	int traversed[10005] = {0};
	stack<int> q;
	q.push(root);
	while(!q.empty()){
		int r = q.top();
		q.pop();
		if(traversed[r] == 2)
			cout << tree[r].value << ' ';
		else if(!traversed[r]){
			q.push(r);
			if(tree[r].right)
				q.push(tree[r].right);
			q.push(r);
			if(tree[r].left)
				q.push(tree[r].left);
		}
		traversed[r]++;
	}
	cout << '\n';
}

void inorder(int root){
	int traversed[10005] = {0};
	stack<int> q;
	q.push(root);
	while(!q.empty()){
		int r = q.top();
		q.pop();
		if(traversed[r])
			cout << tree[r].value << ' ';
		else{
			if(tree[r].right)
				q.push(tree[r].right);
			q.push(r);
			if(tree[r].left)
				q.push(tree[r].left);
		}
		traversed[r]++;
	}
	cout << '\n';
}

void preorder(int root){
	stack<int> q;
	q.push(root);
	while(!q.empty()){
		int r = q.top();
		cout << tree[r].value << ' ';
		q.pop();
		if(tree[r].right)
			q.push(tree[r].right);
		if(tree[r].left)
			q.push(tree[r].left);
	}
	cout << '\n';
}

int main(){
	int n, v;
	int root = 0;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> v;
		root = insert(root, v);
	}
	/* check tree ok */
	cout << "root = " << root << '\n';
	for(int i = 1; i <= n; i++){
		cout << tree[i].value << ' ' << tree[i].left << ' ' << tree[i].right << '\n';
	}
	cout << "Level order: ";
	level(root);
	cout << "preorder: ";
	preorder(root);
	cout << "inorder: ";
	inorder(root);
	cout << "postorder: ";
	postorder(root);
}
