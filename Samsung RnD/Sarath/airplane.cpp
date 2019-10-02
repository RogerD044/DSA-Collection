#include<bits/stdc++.h>
using namespace std;
int n,a[15][15],given[15][15],max_ans;
void plane(int pos,int bomb,int cr,int ans) {
	if(cr==-1 || ans==-1) {
		if(ans>max_ans) {
			max_ans=ans;
		}
		return;
	}
	//bomb
	if(bomb==0) {
		for(int i=cr;i>=0 && i>=cr-4;i--) {
			for(int j=0;j<5;j++) {
				if(a[i][j]==2) {
					a[i][j]=0;
				}
			}
		}
		plane(pos,1,cr,ans);
		for(int i=cr;i>=0 && i>=cr-4;i--) {
			for(int j=0;j<5;j++) {
				a[i][j]=given[i][j];
			}
		}
	}
	//center
	if(a[cr][pos]==0) {
		plane(pos,bomb,cr-1,ans);
	}
	else if(a[cr][pos]==1) {
		plane(pos,bomb,cr-1,ans+1);
	}
	else {
		plane(pos,bomb,cr-1,ans-1);
	}
	//left
	if(pos!=0) {
		if(a[cr][pos-1]==0) {
			plane(pos-1,bomb,cr-1,ans);
		}
		else if(a[cr][pos-1]==1) {
			plane(pos-1,bomb,cr-1,ans+1);
		}
		else {
			plane(pos-1,bomb,cr-1,ans-1);
		}
	}
	//right
	if(pos!=4) {
		if(a[cr][pos+1]==0) {
			plane(pos+1,bomb,cr-1,ans);
		}
		else if(a[cr][pos+1]==1) {
			plane(pos+1,bomb,cr-1,ans+1);
		}
		else {
			plane(pos+1,bomb,cr-1,ans-1);
		}
	}
}
int main() {

	int t,index=1;
	cin>>t;
	while(t--) {
		//int n;
		cin>>n;
		for(int i=0;i<n;i++) {
			for(int j=0;j<5;j++) {
				cin>>a[i][j];
				given[i][j]=a[i][j];
			}
		}
		max_ans=-99;
		plane(2,0,n-1,0);
		cout<<"#"<<index<<" "<<max_ans<<endl;
		index++;
	}
	return 0;
}
