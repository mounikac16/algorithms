#include <bits/stdc++.h>
using namespace std;
void swap(int* a,int* b){
	int t = *a;
	*a=*b;
	*b=t;
}
int getMedian(int arr[],int low, int high){
	int i,j;
	for(i=low;i<high;i++){
		for(j=i+1;j<high;j++){
			if(arr[i]>arr[j])
				swap(&arr[i],&arr[j]);
		}
	}
	return(arr[(low+high)/2]);
}
int medOfMed(int *arr, int low, int high){ 
	int m=(high-low+4)/5,i=0;
	int *median = (int*)malloc(m*sizeof(int));
	while(i<m-1){
		median[i] = getMedian(arr,low+i*5,low+(i+1)*5);
		i++;
	}
	median[i] = getMedian(arr,low+i*5,high);
	int j;
	if(i==0) {
		return median[0];
	}
	else return medOfMed(median,0,i+1);
}
void kthmin(int arr[],int low,int high,int k){
	int med = medOfMed(arr, low, high);
	int less[10000];
	int great[10000];	
	int i,count=0,j=0,l=0;
	for(i=0;i<high;i++){
		if(arr[i]<med)
			less[j++] = arr[i];
		else if(arr[i]>med)
			great[l++] = arr[i];
		else{
			if(count>0)
				less[j++] = arr[i];
			count++;
		}
	}
	if(j-low==k-1 || j-low==0)
		cout << med << endl;
	else if(j-low>k-1)
		kthmin(less,0,j,k);
	else
		kthmin(great,0,l,k-j-1);
}
int main(){
	int t,n,k,i;
	cin >> t;
	while(t--){
		cin >>  n >> k;
		int arr[10000];
		for(i=0;i<n;i++)
			cin >> arr[i];
		kthmin(arr,0,n,k);
	}
	return 0;
}