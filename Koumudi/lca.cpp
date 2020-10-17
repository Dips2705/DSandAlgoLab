#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define initial(arr,val) memset(arr,val,sizeof(arr))
#define mod1 998244353
#define mod 1000000007
#define INF  INT_MAX
#define LINF LLONG_MAX
#define ll long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vpii vector<pii>  
#define rep(i,n) for(i=0;i<n;i++)  
#define rep1(i,n) for(i=1;i<=n;i++)
#define repr(i,n) for(i=n-1;i>=0;i--)
#define all(a) a.begin(),a.end()
#define value(x) cout << #x << " is " << x << endl;
const int dx[8] = {-1, 0, 0,1    ,1, 1 ,-1,-1};
const int dy[8] = { 0,-1, 1,0    ,-1, 1 ,-1,1};
int gcd(int a, int b) { if (a == 0) return b; return gcd(b % a, a);}
const int N=1e5+2;
int  FT[N];
int timer=1;
vector<int> adj[N]; // reset needed

void addedge(int u , int v){
  adj[u].pb(v);
  adj[v].pb(u);
}

int parent[N] ,level[N]; 
bool visit[N]; // need to reset this 
void dfs(int v ,int par,int lev){
  visit[v]=true;
  parent[v]=par;
  level[v]=lev;
  for(auto u : adj[v]){
    if(!visit[u]){
      dfs(u,v,lev+1);
    }
  }
}
int lca(int a ,int b ){
  if(level[b]<level[a]){ 
    swap(a,b); // b should be at greater depth , we will lift this node to the same level of a 
  }
  int d= level[b]-level[a];
  while(d>0){
    b=parent[b];
    d--;
  }
  if(a==b){  // they are in the same subtree 
    return a ;
  }
  else{   // they are at the same level now but in different subtrees
while(parent[a]!=parent[b]){  // lift both of them simultaneously to the same node
  a=parent[a];
  b=parent[b];  
}
return parent[a];
  }

}
void reset(int n ){
  int i;
  rep1(i,n){
    adj[i].clear();
    visit[i]=false;
  }
}
int main() { 
ios_base::sync_with_stdio(false); 
cin.tie(0); 
cout.tie(0);
int tc =1;
//cin>>tc;
while(tc--){
int n,i;
cin>>n;
reset(n);
int x,y;
for(i=1;i<=n-1;i++){
  cin>>x>>y;
  addedge(x,y);
}
dfs(1,0,0); // 1 is starting node , last 0 is level of 1
int q,j;

cin>>q;
 rep(i,q){
  cin>>x>>y;
cout<<lca(x,y)<<endl;
}
  
}
return 0;
}

