#include <bits/stdc++.h>
using namespace std;
typedef struct node{
	char ch;
	struct node *left, *right;
}NODE;
NODE *createNode(char c){
	NODE *p = (NODE*)malloc(sizeof(NODE));
	p->ch=c;
	p->left = NULL;
	p->right = NULL;
	return p;
}
NODE *huffmann(char arr[], int freq[], int n){
	int i = n;
	vector<pair <int, NODE*> > Q;
	while(i--){
		NODE *new_node = createNode(arr[i]);
		Q.push_back(make_pair(freq[i],new_node));
	}
	sort(Q.begin(),Q.end());
	while(Q.size()>1){
		char k = '\0';
		NODE *temp = createNode(k);
		temp->left = Q[0].second;
		temp-> right = Q[1].second;
		int val = Q[0].first + Q[1].first;
		Q.erase(Q.begin());
		Q.erase(Q.begin());
		Q.push_back(make_pair(val,temp));
		sort(Q.begin(),Q.end());
	}
	return Q[0].second;
}	
void printCodes(NODE *root, int code[], int i){
	if(root->left){
		code[i]=0;
		printCodes(root->left,code,i+1);
	}
	if(root->right){
		code[i]=1;
		printCodes(root->right,code,i+1);
	}
	if(!root->left && !root->right){
		cout << root->ch << " - ";
		int j;
		for(j=0;j<i;j++)
			cout << code[j];
		cout << endl;
	}
}
void searchCodes(NODE *root, int code[], int i, char k){
	if(root->left){
		code[i] = 0;
		searchCodes(root->left,code,i+1,k);
	}
	if(root->right){
		code[i] = 1;
		searchCodes(root->right,code,i+1,k);
	}
	if(!root->left && !root->right && root->ch == k){
		int j;
		for( j=0; j<i; j++)
			cout << code[j];
		cout << endl;
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int i,n;
		cin >> n;
		char *arr = (char*)malloc(n*sizeof(char));
		int *freq = (int*)malloc(n*sizeof(int));
		int code[100];
		for(i=0; i<n; i++){
			cin >> arr[i];
			cin >> freq[i];
		}
		NODE *root = huffmann(arr,freq,n);
		for(i=0; i<n; i++)
			searchCodes(root,code,0,arr[i]);
	}
	return 0;
}