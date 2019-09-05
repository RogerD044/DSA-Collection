#include<bits/stdc++.h>
using namespace std;
#define c 5

int maa = INT_MIN;

void func(int ar[][c],int ma,int row,int col,int det)
{
	if(row<0)	{	maa = max(maa,ma);	return;	}
	if(col>=5 || col<0)					return;
	if(ar[row][col]==2 && ma<1)	{	maa = max(maa,ma);	return;		}
	else if(ar[row][col]==2 && ma>0)		--ma;
	

	if(ar[row][col]==1)
		if(ma==-1)	ma=1;
		else		++ma;
	
	//cout<<ma<<" "<<row<<" "<<col<<" "<<det<<endl;
	
	func(ar,ma,row-1,col-1,det);
	func(ar,ma,row-1,col,det);
	func(ar,ma,row-1,col+1,det);
	
	if(row==0||det==0)	return;
	
	for(int i = row-1;i>=row-5 && i>=0;--i)
	{
	    for(int j=0;j<5;++j)
			{
			    //cout<<i<<" "<<j<<endl;
			    if(ar[i][j]==2)	
			    {
			        ar[i][j]=0;
			    }
			}
	}	
			    
	
	func(ar,ma,row-1,col-1,0);
	func(ar,ma,row-1,col,0);
	func(ar,ma,row-1,col+1,0);
	
}

int main()
{
	int t;	cin>>t;
	while(t--)
	{
		int n;	cin>>n;
		int ar[n][c];
		int d = 1;
		for(int i=0;i<n;++i)
			for(int j=0;j<c;++j)
				cin>>ar[i][j];

		maa = INT_MIN;
		//if(ar[n-1][1]==2 && ar[n-1][3]==2 && ar[n-1][2]==2) {   cout<<-1<<endl; continue;   }
		func(ar,-1,n-1,1,1);
		func(ar,-1,n-1,2,1);
		func(ar,-1,n-1,3,1);
		
		for(int i = n-1;i>n-5 && i>=0;--i)
			for(int j=0;j<5;++j)
				if(ar[i][j]==2)	ar[i][j]=0;
		
		func(ar,-1,n-1,1,0);
		func(ar,-1,n-1,2,0);
		func(ar,-1,n-1,3,0);
		
		cout<<maa<<endl;
	}
}