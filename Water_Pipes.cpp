    #include<iostream>
    #define ll long long int
    using namespace std;
    ll v[1001][1001];
    ll visit[1001][1001];
     
    struct queue{
    int ax,ay;
    };
     
    queue q[1000001];
     
    bool checkUp( ll x,ll y,ll t,ll length){
       if(t<0 || v[x][y]==0 || v[t][y]==0 || visit[t][y]!=0 || visit[x][y]==length)
        return false;
       if((v[x][y]==1 || v[x][y]==2 || v[x][y]==4 || v[x][y]==7) && (v[t][y]==1 || v[t][y]==2 || v[t][y]==5 || v[t][y]==6)){
        return true;
       }
        return false;
    }
     
    bool checkDown(ll x,ll y,ll t,ll row,ll length){
     if(t>=row || v[x][y]==0 || v[t][y]==0 || visit[t][y]!=0 || visit[x][y]==length){
            return false;
     }
        if((v[x][y]==1 || v[x][y]==2 || v[x][y]==5 || v[x][y]==6) && (v[t][y]==1 || v[t][y]==2 || v[t][y]==4 || v[t][y]==7)){
                return true;
        }
        return false;
    }
     
    bool checkLeft(ll x,ll y,ll t,ll length){
        if(t<0 || v[x][y]==0 || v[x][t]==0 || visit[x][t]!=0 || visit[x][y]==length){
                return false;
        }
        if((v[x][y]==1 || v[x][y]==3 || v[x][y]==6 || v[x][y]==7) && (v[x][t]==1 || v[x][t]==3 || v[x][t]==4 || v[x][t]==5))
        {
            return true;
        }
        return false;
    }
     
    bool checkRight(ll x,ll y ,ll t,ll col, ll length){
      if(t>=col || v[x][y]==0 || v[x][t]==0 || visit[x][t]!=0 || visit[x][y]==length)
      {
          return false;
      }
        if((v[x][y]==1 || v[x][y]==3 || v[x][y]==4 || v[x][y]==5) && (v[x][t]==1 || v[x][t]==3 || v[x][t]==6 || v[x][t]==7)){
                return true;
        }
        return false;
    }
     
     
    int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int t;
        cin>>t;
        while(t--){
     
                ll row,col,x,y,length;
                cin>>row>>col>>x>>y>>length;
     
                for(int i = 0 ; i < row ; i++){
                    for(int j = 0; j < col ; j++){
                        cin>>v[i][j];
                    }
                }
     
                for(int i = 0 ; i < row ; i++){
                    for(int j = 0; j < col ; j++){
                        visit[i][j] = 0;
                    }
                }
     
                if(v[x][y] == 0){
                    cout<<"0\n";
                }
                else if(length == 1){
                    cout<<"1\n";
                }
                else{
                  queue p;
                  ll start=0,end=0,count=0;
                  p.ax=x;
                  p.ay=y;
                  q[end++]=p;
                 visit[x][y]=1;
     
                    while(start!=end){
                         p=q[start];
                        ll a1=p.ax;
                        ll a2=p.ay;
                        start++;
     
                    if(checkUp(a1,a2,a1-1,length)){
                        p.ax=a1-1;
                        p.ay=a2;
                        q[end++]=p;
                        visit[a1-1][a2]=1+visit[a1][a2];
                    }
                    if(checkDown(a1,a2,a1+1,row,length)){
                        p.ax=a1+1;
                        p.ay=a2;
                        q[end++]=p;
                        visit[a1+1][a2]=1+visit[a1][a2];
                    }
                    if(checkLeft(a1,a2,a2-1,length)){
                        p.ay=a2-1;
                        p.ax=a1;
                        q[end++]=p;
                        visit[a1][a2-1]=1+visit[a1][a2];
                    }
                    if(checkRight(a1,a2,a2+1,col,length)){
                        p.ay=a2+1;
                        p.ax=a1;
                        q[end++]=p;
                        visit[a1][a2+1]=1+visit[a1][a2];
                    }
                }
                    for(ll i=0;i<row;i++){
                        for(ll j=0;j<col;j++){
                                if(visit[i][j] != 0){
                                    count++;
                                }
                        }
                     }
                   cout<<count<<"\n";
     
            }
        }
        return 0;
    }