#include<iostream>
using namespace std;

int n,m;
int a[100][100],rs[100],visited[100],path[100];
int rv,inx=0,flag=0;

void swap(int *xp,int *yp) {
	int temp=*xp;
	*xp=*yp;
	*yp=temp;
}
void bubblesort(int a[],int n) {
	
	bool swapped;
	
	for(int i=0;i<n-1;i++) {
		for(int j=0;j<n-i-1;j++) {
			swapped=false;
			if(a[j]>a[j+1]) {
				swap(&a[j],&a[j+1]);
				swapped=true;
			}
		}
		if(swapped==false) {
			break;
		}
	}
	
}
void rec(int cur) {
	rs[cur]=1;
	path[inx]=cur;
	
	for(int i=0;i<n;i++) {
		if(a[cur][i]==1) {
			if(rs[i]) {
				rv=i;
				flag=1;
				return;
			}
			else if(visited[i]) {
				continue;
			}
			else {
				inx++;
				rec(i);
				if(flag==1) {
					return;
				}
			}
		}
	}
	
	inx--;
	rs[cur]=0;
	visited[cur]=1;
	return;
	
}
int main() {
	int t,index=1;
	cin>>t;
	while(t--) {
		cin>>n>>m;
		flag=0;
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				a[i][j]=0;
			}
			rs[i]=0;
			visited[i]=0;
		}
		
		int x,y;
		for(int i=0;i<m;i++) {
			cin>>x>>y;
			a[x][y]=1;
		}
		
		for(int i=0;i<n;i++) {
			if(flag==1) {
				break;
			}
			if(!visited[i]) {
				inx=0;
				rec(i);
			}
		}
		cout<<"#"<<index;
		int i;
		if(flag==0) {
			cout<<" 0";
		}
		else {
			for(i=0;path[i]!=rv;i++) {
				
			}
			bubblesort(path+i,inx+1);
			for(;i<=inx;i++) {
				cout<<" "<<path[i];
			}
		}
		cout<<endl;
		index++;
	}
	return 0;
}
