
// Problem : E. Weights Distributing
// Contest : Codeforces - Codeforces Round #636 (Div. 3)
// URL : https://codeforces.com/contest/1343/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
using namespace std;
#define int         long long int
#define vi           vector<int>
#define pii          pair<int,int>
#define vpp          vector<pii>
#define mii          map<int,int>
#define pb           push_back
#define endl        '\n'
#define rep(i,a,bb)  for(int i=a;i<bb;i++)
#define ff           first
#define ss           second
#define fast         ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define test         int T;cin>>T;while(T--)
#define __sort(v)    sort(v.begin(),v.end())
#define __rsort(v)   sort(v.rbegin(),v.rend())
#define setbits(x)   __builtin_popcount(x)
#define zrobits(x)   __builtin_ctzint(x)
const int inf = 5 * (1e+18);
const int mod = 1e+9 + 7;

int n, m, a, b, c;
vector<int> adj[200005];

void init()
{
    for(int i=0; i<200005; i++)
       {	
       adj[i].clear();
       }
       	 
}

void bfs(int src, vector<int> &dist)
{
	  vector<bool> vis(dist.size()+1, 0);
	  dist[src] = 0;
	  queue<int> q;
	  q.push(src);
	  while(!q.empty())
	  {
	  	 int curr = q.front();
	  	 q.pop();
	  	 vis[curr] = 1;
	  	 for(auto i:adj[curr])
	  	      {
	  	      	
	  	      	 if(!vis[i])
	  	      	    {
	  	      	    	       dist[i] = min(dist[i], dist[curr]+1);
	  	      	    	       q.push(i);
	  	      	    }
	  	      }
	  }
	  
	  
}
int32_t main()
{
  
  test
  {
  	  init();
  	  cin>>n>>m>>a>>b>>c;
  	  vi prices(m);
  	  rep(i,0,m)
  	     cin>>prices[i];
  	  rep(i,0,m)
  	  {
  	  	 int x, y;
  	  	 cin>>x>>y;
  	  	 adj[x].pb(y);
  	  	 adj[y].pb(x);
  	  }
  	  __sort(prices);
  	  vector<int> pre(m+1, 0);
  	  rep(i, 1, m+1)
  	     pre[i] = pre[i-1]+prices[i-1];
  	  
  	  
  	  vector<int> da(n+1, inf), db(n+1, inf), dc(n+1, inf);
  	  da[0] = 0;
  	  db[0] = 0;
  	  dc[0] = 0;
  	  
  	  bfs(a, da);
  	  bfs(b, db);
  	  bfs(c, dc);  	  
  	  
  	  //rep(i, 0, m+1)
  	  //  cout<<pre[i]<<" ";
  	  //cout<<endl;
  	  
  	  int ans = inf;
  	  for(int i=1;i<=n;i++)
  	     {
  	     	//cout<<da[i]<<" "<<db[i]<<" "<<dc[i]<<endl;
  	     	if(da[i]+db[i]+dc[i]<=m)
  	  	   		ans = min(ans, pre[db[i]]+pre[db[i]+da[i]+dc[i]]);
  	  	}
  	  
  	  cout<<ans<<endl;
  	  
  }

  return 0;
}
