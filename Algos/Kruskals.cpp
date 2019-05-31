#include <bits/stdc++.h>
using namespace std;
typedef struct node{
	int weight,src,dest;
}NODE;
typedef struct tree{
	int val;
	struct tree *left,*right;
}TREE;
NODE *createNode(int src,int dest,int wt){
	NODE *p=(NODE*)malloc(sizeof(NODE));
	p->weight=wt;
	p->src=src;
	p->dest=dest;
	return p;
}
int find(int x,int *parent){
	if(parent[x-1]==x)
		return x;
	else
		return find(parent[x-1],parent);
}
struct myComp{
	bool operator()(NODE *x,NODE *y){
		return x->weight>y->weight;
	}
};
void kruskal(priority_queue<NODE*,deque<NODE*>,myComp>& Q, int *parent,int *height,int n){
	int p1,p2,i,count=0;
	while(Q.size()>0){
		p1=find(Q.top()->src,parent);
		p2=find(Q.top()->dest,parent);
		if(p1!=p2){
			if(height[p1-1]<height[p2-1]){
				parent[p1-1]=p2;
				height[p1-1]=height[p2-1];
			}
			else if(height[p1-1]==height[p2-1]){
				parent[p1-1]=p2;
				height[p2-1]++;
				height[p1-1]=height[p2-1];
			}
			else{
				parent[p2-1]=p1;
				height[p2-1]=height[p1-1];
			}
			count+=Q.top()->weight;	
		}
		Q.pop();
	}
	cout<< count << endl;
}
int main(){
	int i,n,e,src,dest,j,wt;
	cin >> n >> e;
	int *parent=(int*)malloc(n*sizeof(int));
	int *height=(int*)calloc(n,sizeof(int));
	priority_queue<NODE*,deque<NODE*>,myComp>Q;
	for(i=0;i<e;i++){
		cin >> src >> dest >> wt;
		Q.push(createNode(src,dest,wt));
		parent[src-1]=src;
		parent[dest-1]=dest;
	}
	kruskal(Q,parent,height,n);
	return 0;
}