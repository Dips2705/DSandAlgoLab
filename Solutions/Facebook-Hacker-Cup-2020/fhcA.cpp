
#include<bits/stdc++.h>
using namespace std;
#define int         long long int
#define vi           vector<int>
#define pii          pair<int,int>
#define vpp          vector<pii>
#define mii          map<int,int>
#define pb           push_back
#define rep(i,a,bb)  for(int i=a;i<bb;i++)
#define ff           first
#define ss           second
#define fast         ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define test         int T;cin>>T;while(T--)
#define __sort(v)    sort(v.begin(),v.end())
#define __rsort(v)   sort(v.rbegin(),v.rend())
#define setbits(x)   __builtin_popcount(x)
#define zrobits(x)   __builtin_ctzint(x)
#define endl '\n'
#define debug(x)  cerr<<"[ "<<#x<<" : "<<x<<" ]"<<endl
#define debugp(x) cerr<<"[ "<<#x<<".ff : "<<x.first<<", "<<#x<<".ss : "<<x.second<<" ]"<<endl
#define debugs(x) cerr<<"[ "; for(auto i:x) cerr<<i<<" "; cerr<<" ]"<<endl;
#define debugm(x) cerr<<"----------"<<endl; for(auto i:x) cerr<<i.ff<<":"<<i.ss<<endl; cerr<<"----------"; 
#define PI 3.14159265359
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int dxk[]={0,0,1,-1,1,1,-1,-1};
int dyk[]={1,-1,0,0,1,-1,1,-1};
const int inf = 1e+18;
const int mod = 1e+9 + 7;
int cases = 1;
bool vis[100];

void dfs(int src, int& n, string& in, string& out){
	vis[src] = 1;
	if(src+1<n&&out[src]=='Y'&&in[src+1]=='Y'&&!vis[src+1])
	   dfs(src+1, n, in, out);
	if(src-1>=0&&out[src]=='Y'&&in[src-1]=='Y'&&!vis[src-1])
	   dfs(src-1, n, in, out);
}

void solve()
{
	int n;
	cin>>n;
	string in , out;
	cin>>in >> out;
	vector<string> res;
	rep(i, 0, n){
		memset(vis, 0, sizeof(vis));
		dfs(i, n, in, out);
		string ans;
		rep(j, 0, n){
			if(vis[j]){
				ans+='Y';
			}
			else
			     ans+='N';
		}
		res.pb(ans);
	}
	for(auto ans : res)
	  cout<<ans<<endl;
	
}

int32_t main()
{
  fast;
  test{
cout<<"Case #"<<cases<<":"<<endl;;
  solve();
  ++cases;
  }
  return 0;
}
