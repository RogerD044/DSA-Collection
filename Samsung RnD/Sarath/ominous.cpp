#include<iostream>
using namespace std;

int s,e,n,k,a[100];
int main() {
	int t,index=1;
	cin>>t;
	while(t--) {
		cin>>s>>e;
		cin>>n>>k;
		for(int i=0;i<n;i++) {
			cin>>a[i];
		}
		int dummy,rem,k1;
		int count=0;
		for(int i=s;i<=e;i++) {
			dummy=i;
			k1=k;
			while(dummy!=0) {
				rem=dummy%10;
				for(int j=0;j<n;j++) {
					if(rem==a[j]) {
						k1--;
						break;
					}
				}
				dummy=dummy/10;
			}
			if(k1<=0 && k1>=k-n) {
				count++;
			}
		}
		cout<<"#"<<index<<" "<<(e-s+1)-count<<endl;
		index++;
	}
	return 0;
}
