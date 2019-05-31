#include<iostream>
#include<string.h>
#include<math.h>
#include<queue>
#include<stdlib.h>
#include <stdio.h>
#include<map>
#include <bits/stdc++.h>
using namespace std;

map<string,char> items;

typedef struct node{
	char c;
	struct node *l;
	struct node *r;
	int freq;
}NODE;

NODE* creNode(char ch,int freq){
	NODE *node =(NODE *)malloc(sizeof(NODE));
    	node->c = ch;
    	node->l = NULL;
   	node->r = NULL;
   	node->freq = freq;
    	return node;
}

void print_chf_tree(NODE *head){
	if(head==NULL){
		return;
	}
	else{
		print_chf_tree(head->l);
		cout << head->c  << " " << (head->freq) << endl;
		print_chf_tree(head->r);
	}
}
void huffman_printing(NODE* head, NODE* root,NODE* p,int flag1,int flag2,int index,char str[],int count,int n){

	if(head==NULL){
		return;
	}
	else{
		if(head->l!=NULL){
			flag1=1;
			flag2=0;
			str[index++] = '0';
			p=head;
			huffman_printing(head->l,root,p,flag1,flag2,index,str,count,n);
		}
		else if(head->r!=NULL){
			flag1=0;
			flag2=1;
			str[index++] = '1';
			p=head;
			huffman_printing(head->r,root,p,flag1,flag2,index,str,count,n);
		}
		else if(head->l==NULL && head->r==NULL)
		{
			if(head->c!='*'){
				str[index] = '\0';
				//printf("%s %c\n",str,head->c );
				items.insert(make_pair(str,head->c));
				count++;
				index=0;
				if(flag1==1 && flag2 == 0){
					p->l=NULL;
				}
				else{
					p->r=NULL;
				}
			p=NULL;
			str[index]='\0';
			if(count<n){
				huffman_printing(root,root,p,0,0,index,str,count,n);
			}
			}
			else{
				index=0;
				//str.clear();
				if(flag1==1 && flag2 == 0){
					p->l=NULL;
				}
				else{
					p->r=NULL;
				}
			p=NULL;
			str[index]='\0';
			if(count<n){
				huffman_printing(root,root,p,0,0,index,str,count,n);
			}
			}
		}
	}
}
int main(){
	int testcases,k;
	cin >> testcases;
	for(k=0;k<testcases;k++){
	int n;
	cin >> n;
	int freq,i;
	char ch,c[1000];
	vector<pair<int , NODE*> >  q;
	for(int i=0;i<n;i++){
		cin >> ch ;
		cin >> freq;
		c[i] = ch;
		NODE* nn = creNode(ch,freq);
		q.push_back(make_pair(freq,nn));
	}
	int e= q.size();
	sort(q.begin(),q.end());
	while(q.size()>=2){
		
		NODE* s2 = creNode('*',0);
		s2->l = q[0].second;
		s2->r = q[1].second;
		int freuency = q[0].first + q[1].first;
		q.push_back(make_pair(freuency,s2));
		q.erase(q.begin());
		q.erase(q.begin());
		sort(q.begin(),q.end());
	}
	NODE *head = q[0].second;
	NODE *root = NULL;
	root = head;
	char str[200];
	NODE *store=NULL;
	huffman_printing(head,root,store,0,0,0,str,0,n);
	for(i=0;i<e;i++){
	for( map<string,char> ::iterator ii=items.begin(); ii!=items.end(); ++ii){
		if(ii->second == c[i]){
       	cout << ii->first << endl;
  		}
	}
}
}
return 0;
}
