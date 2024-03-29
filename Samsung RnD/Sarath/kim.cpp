#include<bits/stdc++.h>
using namespace std;

int n,max_ans,x[100],y[100],visited[100],dx,dy;

int absdiff(int sx,int sy,int dx,int dy) {
	int xd=(sx>dx)?(sx-dx):(dx-sx);
	int yd=(sy>dy)?(sy-dy):(dy-sy);
	return (xd+yd);
}
void fun(int shot,int sx,int sy,int ans) {
	if(shot==n+1 && sx==dx && sy==dy) {
		if(ans<max_ans) {
			max_ans=ans;
		}
		return;
	}
	int cr_ans=ans;
	for(int i=0;i<=n;i++) {
		if(visited[i]==0) {
			visited[i]=1;
			ans+=absdiff(sx,sy,x[i],y[i]);
			fun(shot+1,x[i],y[i],ans);
			visited[i]=0;
			ans=cr_ans;
		}
	}
}
int main() {
	
	int t,index=1;
	cin>>t;
	while(t--) {
		cin>>n;
		int sx,sy;
		cin>>sx>>sy;
		for(int i=0;i<n+1;i++) {
			cin>>x[i]>>y[i];
			visited[i]=0;
		}
		dx=x[0];
		dy=y[0];
		max_ans=999999;
		fun(0,sx,sy,0);
		cout<<"#"<<index<<" "<<max_ans<<endl;
		index++;
	}
	
	return 0;
}
