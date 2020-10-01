
#include<bits/stdc++.h>
using namespace std;
//#define int         long long int
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
//const int inf = 1e+18;
//const int mod = 1e+9 + 7;

void solve()
{
	int cars;
	cin>>cars;
	long long int ans = 0;
	map<pair<pair<int, int>,int>,int> mp;
	while(cars--)
	{
		long long int x,y,s;
		cin>>x>>y>>s;
		x=abs(x);
		y=abs(y);
		long long int hcf = __gcd(x,y);
		hcf = __gcd(hcf,s);
		x/=hcf;
		y/=hcf;
		s/=hcf;
		mp[{{max(x,y),min(x,y)},s}]++;
	}
	for(auto i:mp)
	  {
	  	cout<<i.ss<<" ";
	  	if(i.ss>1)
	    {
	    	ans+=(i.ss*(i.ss-1))/2;
	    }
	  }
	cout<<ans<<endl;
     
}


int main()
{ 
  fast;
  //test
  solve();
  return 0;
}
