
// Problem : Can you answer these queries I
// Contest : SPOJ - Classical
// URL : https://www.spoj.com/problems/GSS1/
// Memory Limit : 1536 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)


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

struct data{
	int sum;
	int maxsum;
	int presum;
	int suffsum;
};

const int mxN = 200000;
data tree[mxN];

void update(int v){
	tree[v].maxsum  = max({tree[2*v].maxsum, tree[2*v+1].maxsum, tree[2*v].suffsum+tree[2*v+1].presum});
	tree[v].sum     = tree[2*v].sum+tree[2*v+1].sum;
	tree[v].presum  = max(tree[2*v].presum, tree[2*v].sum+tree[2*v+1].presum);
	tree[v].suffsum = max(tree[2*v+1].suffsum, tree[2*v+1].sum+tree[2*v].suffsum);
}

data combine(data l, data r){
    data res;
    res.sum = l.sum+r.sum;
    res.sum = l.sum + r.sum;
    res.presum = max(l.presum, l.sum + r.presum);
    res.suffsum = max(r.suffsum, r.sum + l.suffsum);
    res.maxsum = max({l.maxsum, r.maxsum, l.suffsum + r.presum});
    return res;
}

void build(int v, int tl, int tr, int* a){
	if(tl>tr)
	   return;
	if(tl==tr){
		tree[v].sum = a[tl];
		tree[v].maxsum = a[tl];
		tree[v].presum = a[tl];
		tree[v].suffsum = a[tl];
		return;
	}
	int mid = (tl+tr)/2;
	build(2*v, tl, mid, a);
	build(2*v+1, mid+1, tr, a);
	update(v);
	
}

void modify(int v, int tl, int tr, int pos, int val){
	if(tl>tr)
	   return;
	if(tl==tr){
		tree[v].sum = val;
		tree[v].maxsum = val;
		tree[v].presum = val;
		tree[v].suffsum = val;
		return;
	}
	int mid = (tl+tr)/2;
	if(pos<=mid)
	   modify(2*v, tl, mid, pos, val);
	else 
	  modify(2*v+1, mid+1, tr, pos, val);
	update(v);
	
}
data mrs(int v, int tl, int tr, int ql, int qr){
	if(tl>qr||tr<ql)
	{
		data temp;
		int x = INT_MIN;
		temp.sum = x;
		temp.maxsum = x;
		temp.presum = x;
		temp.suffsum = x;
		return temp;
	}
	if(tl>=ql&&tr<=qr){
		return tree[v];
	}
	int mid = (tl+tr)/2;
     return combine(mrs(2*v, tl, mid, ql, qr), mrs(2*v+1, mid+1, tr, ql, qr));
}




void solve()
{
	int n;
	cin>>n;
	int a[n];
	rep(i,0,n){
		cin>>a[i];
	}
	build(1, 0, n-1, a);
	int q;
	cin>>q;
	while(q--){
		int c, x, y ;
		cin>>c>>x>>y;
          if(c){
		--x;
		--y;
		}
		else
		--x;
		if(c){
		data d = mrs(1, 0, n-1, x, y);
		cout<<max({d.sum, d.maxsum, d.presum, d.suffsum})<<endl;
		//cout<<d.maxsum<<endl;
		}
		else{
			modify(1, 0, n-1, x, y);
		}
	}
}

int32_t main()
{
  fast;
  //test
  solve();
  return 0;
}
