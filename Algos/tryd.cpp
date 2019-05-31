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
void bellmanford(vector< vector<NODE*> >& G,int *dist,int *visited,int started){
	priority_queue<NODE*> track;
	track.push(started);
	visited[started-1]=1;
	int i,s,u,v;
	while(track.size()>0){
		u=track.front();
		s=G[u-1].size();
		for(i=1;i<s;i++){
			v=G[u-1][i]->dest;
			if(visited[v-1]==0){
				visited[v-1]=1;
				dist[v-1]=dist[u-1]+6;
				track.push(v);
			}
		}
		track.pop();
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
			cin >> src >> dest;
			G[src-1].push_back(createNode(src,dest,6));
			G[dest-1].push_back(createNode(dest,src,6));
		}
		cin >> started;
		int *dist=(int*)calloc(n,sizeof(int));
		int *visited=(int*)calloc(n,sizeof(int));
		bellmanford(G,dist,visited,started);
		for(i=0;i<n;i++){
			if(dist[i]>0)
				cout << dist[i] << " ";
			else if(dist[i]==0 && i!=started-1)
				cout << "-1" << " ";
		}
		cout << endl;
	}
	return 0;
}