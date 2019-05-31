#include <bits/stdc++.h>
using namespace std;
void multiStage(int *adj, int low, int high){
	int i, j, temp;
	int *path = (int*)calloc((high+1),sizeof(int));
	for(i=(low+1); i<high; i++){
		temp = INT_MAX;
		for(j=low; j<i; j++)
			if(*(adj+high*j+i))
				if(path[j]+*(adj+high*j+i) < temp) 
					path[i] = path[j] + *(adj+high*j+i);
	}
	cout<<path[high-1]<<endl;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		int n, e, vertex1, vertex2, len, i; 
		cin>>n>>e;
		int *adj = (int*)calloc(n*n,sizeof(int));
		for(i=0; i<e; i++){
			cin>>vertex1>>vertex2>>len;
			*(adj+n*(vertex1-1)+vertex2-1) = len;
		}
		multiStage(adj, 0, n);
	}
	return 0;
}