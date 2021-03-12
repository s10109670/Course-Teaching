#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct Treenode{
	int value;
	Treenode *left, *right;
};

Treenode* insert(Treenode* root, int v){
	if(root == NULL){
		root = new Treenode;
		root->value = v;
		return root;
	}
	if(v > root->value){
		root->right = insert(root->right, v);
		return root;
	}
	else{
		root->left = insert(root->left, v);
		return root;
	}
}

void level(Treenode* root){
	queue<Treenode*> q;
	q.push(root);
	while(!q.empty()){
		Treenode* r = q.front();
		cout << r->value << ' ';
		q.pop();
		if(r->left)
			q.push(r->left);
		if(r->right)
			q.push(r->right);
	}
	cout << '\n';
}

void preorder(Treenode* root){
	stack<Treenode*> q;
	q.push(root);
	while(!q.empty()){
		Treenode* r = q.top();
		cout << r->value << ' ';
		q.pop();
		if(r->right)
			q.push(r->right);
		if(r->left)
			q.push(r->left);
	}
	cout << '\n';
}

int main(){
	int n, v;
	Treenode* root = NULL;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> v;
		root = insert(root, v);
	}
	/* check tree ok */
	cout << "Level order: ";
	level(root);
	cout << "preorder: ";
	preorder(root);
}
