#include<bits/stdc++.h>
using namespace std;
int findMin(int *visited,int *dist,int n){
	int i,temp = INT_MAX,var;
		for(i=0;i<n;i++){
			if(visited[i]==0 && dist[i] < temp){
				temp=dist[i];
				var=i;
			}
		}
	return var;
}
void dijsktra(vector<vector<int> > adj,int n,int start,int *dist,int *visited){
	int i,j;
	for(i=0;i<n-1;i++){
		int u=findMin(visited,dist,n);
		visited[u]=1;
		for(j=0;j<n;j++){
			if(visited[j]==0 && adj[u][j]!=0 && dist[u]+adj[u][j]<dist[j] && dist[u]!=INT_MAX){
					dist[j] = dist[u] + adj[u][j];
			}
		}
	}
}
int main(){
	int t,i;
	cin >> t ;
	while(t--){
		int i,j,n,m,start,src,dest,wt;
		cin >> n >> m;
		vector<int> inside(n);
		vector<vector<int> > adj(n,inside);
		for(i=0;i<m;i++){
			cin >> src >> dest >> wt;
            if(adj[src-1][dest-1]==0 || adj[src-1][dest-1]>wt){
				adj[src-1][dest-1]=wt;
				adj[dest-1][src-1]=wt;
            }                
        }
		cin>>start;
		int *visited=(int*)calloc(n,sizeof(int));
		int *dist=(int*)calloc(n,sizeof(int));
		for(i=0;i<n;i++){
			dist[i]=INT_MAX;
		}
		dist[start-1]=0;
		dijsktra(adj,n,start,dist,visited);
		for(i=0;i<n;i++){
			if(dist[i]==INT_MAX)
				cout << "-1" << " ";
			else if(i!=start-1)
				cout << dist[i] << " ";
		}
		cout<<endl;
	}
	return 0;
}