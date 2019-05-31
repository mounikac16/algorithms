#include <bits/stdc++.h>
using namespace std;
typedef struct node{
	int src,dest,weight;
}NODE;
NODE *createNode(int src,int dest,int wt){
	NODE *p=(NODE*)malloc(sizeof(NODE));
	p->src=src;
	p->dest=dest;
	p->weight=wt;
	return p;
}
struct myComp{
	bool operator()(NODE *x,NODE *y){
		return x->weight>y->weight;
	}
};
void dijkestra(vector< vector<NODE*> >& G,int *dist,int *visited,int started){
	priority_queue<NODE*,deque<NODE*>,myComp>track;
	track.push(G[started-1][0]);
	int i,u,v;
	visited[started-1]=1;
	while(track.size()>0){
		u=track.top()->dest;
		int s=G[u-1].size();
		track.pop();
		visited[u-1]=1;
		for(i=1;i<s;i++){
			v=G[u-1][i]->dest;
			if(visited[v-1]==0){
				if(dist[v-1]>dist[u-1]+G[u-1][i]->weight){
					dist[v-1]=dist[u-1]+G[u-1][i]->weight;
					G[u-1][i]->weight=dist[v-1];
					track.push(G[u-1][i]);
				}
			}
		}
	}
}
int main(){
	int t;
	cin >> t;
	while(t--){
		int n,m,i,src,dest,wt,started;
		cin >> n >> m; 
		vector< vector<NODE*> > G;
		for(i=0;i<n;i++){
			vector<NODE*> temp;
			temp.push_back(createNode(i+1,i+1,0));
			G.push_back(temp);
		}
		for(i=0;i<m;i++){
			cin >> src >> dest >> wt;
			G[src-1].push_back(createNode(src,dest,wt));
			G[dest-1].push_back(createNode(dest,src,wt));
		}
		cin >> started;
		int *dist=(int*)calloc(n,sizeof(int));
		int *visited=(int*)calloc(n,sizeof(int));
		for(i=0;i<n;i++)
			dist[i]=INT_MAX;
		dist[started-1]=0;
		dijkestra(G,dist,visited,started);
		for(i=0;i<n;i++){
			if(dist[i]!=INT_MAX && i!=started-1)
				cout << dist[i] << " ";
			else if(dist[i]==INT_MAX)
				cout << "-1" << " ";
		}
		cout << endl;
	}
	return 0;
}