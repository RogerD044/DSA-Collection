#include<bits/stdc++.h>
using namespace std;

int gl= INT_MAX;

void func(int visit[], int ar[], int n, int k, int ind, vector<int> v, int pre[], int kk)
{
//	if(k==0)	return;

	if(k==kk)
	{
		int mi = INT_MAX, ma = INT_MIN,ans;
		ans = ((v[0]==0)?0:pre[v[0]-1]) + (pre[n-1] - pre[v[k-1]-1]);
		ma = max(ma,ans);
		mi = min(mi,ans);
		for(int i=1;i<k;++i)
		{
			ans = pre[v[i]-1] - pre[v[i-1]] + ar[v[i-1]];
			ma = max(ma,ans);
			mi = min(mi,ans);
		}
		gl = min(gl,abs(ma-mi));
		//for(auto it:v)	cout<<it<<" ";		cout<<ma<<" "<<mi<<endl;
		return;
	}

	for(int i=ind;i<n;++i)
	{
		visit[i]=1;
		v.push_back(i);
		func(visit,ar,n,k,i,v,pre,kk+1);
		visit[i]=0;
		v.pop_back();
	}
}

int main()
{
	int n,k;	cin>>n>>k;
	int ar[n];
	int pre[n];
	for(int i=0;i<n;++i)	cin>>ar[i];
		pre[0]=ar[0];
	for(int i=1;i<n;++i)	
		pre[i]=ar[i]+pre[i-1];

	int visit[n] = {0};
	vector<int> v;
	
	//cout<<"start"<<endl;
	for(int i=0;i<n;++i)
	{
		visit[i]=1;
		v.push_back(i);
		func(visit,ar,n,k,i+1,v,pre,1);
		visit[i]=0;
		v.pop_back();
	}

	cout<<gl;

}