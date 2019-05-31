#include <bits/stdc++.h>
using namespace std;
void lcs(char s1[], char s2[], int len1, int len2, int arr[][100]){
	int i,j,count=0;
	for(i=1;i<=len1;i++){
		for(j=1;j<=len2;j++){
			if(s1[i-1]!=s2[j-1]) arr[i][j] = arr[i-1][j]>arr[i][j-1] ? arr[i-1][j] : arr[i][j-1];
			else arr[i][j] = arr[i-1][j-1]+1;
		}
	}
	int index = arr[len1][len2];
	char *seq = (char*)malloc((index+1)*sizeof(char));
	seq[index]='\0';
	i=len1;
	j=len2;
	while(i && j){
		if(s1[i-1]==s2[j-1]){
			seq[index-1]=s1[i-1];
			i--;
			j--;
			index--;
		}
		else if(arr[i-1][j]>arr[i][j-1]) i--;
		else j--;
	}
	cout << seq << endl;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		char s1[1000],s2[1000];
		getchar();
		scanf("%[^\n]s", s1);
		getchar();
		scanf("%[^\n]s", s2);
		int len1 = strlen(s1), len2 = strlen(s2);
		int arr[100][100]={0};
		lcs(s1,s2,len1,len2,arr);
	}
	return 0;
}																																																																																																																																																																																																																																																																																																																																																																																																																																																										