#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define F first
#define S second
#define ld long double
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vpii vector<pii>  
#define rep(i,n) for(i=0;i<n;i++)
#define repr(i,n) for(i=n-1;i>=0;i--)
#define o4(a,b,c,d) cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<endl;
#define initial(arr,val) memset(arr,val,sizeof(arr)) 
#define value(x) cout << #x << " is " << x << endl;
void buildtree(ll* arr, ll* segtree ,int start,int end ,int tnode){
	if(start == end){
		segtree[tnode]=arr[start];
		return ;
	}
	int mid = start + (end - start)/2;
	buildtree(arr,segtree,start,mid,2*tnode);
	buildtree(arr,segtree,mid+1,end,2*tnode+1);
	segtree[tnode]= min(segtree[2*tnode],segtree[2*tnode+1]);
}
void update(ll* arr, ll* segtree ,int start,int end ,int tnode,int ind,int val){
	if(start == end){
		arr[start]= val;
		segtree[tnode]=val;
		return ;
	}
	int mid = start + (end - start)/2;
	if(ind<=mid)
	update(arr,segtree,start,mid,2*tnode,ind,val);
    else
	update(arr,segtree,mid+1,end,2*tnode+1,ind,val);
	segtree[tnode]=min(segtree[2*tnode],segtree[2*tnode+1]);
}
ll minrange(ll* arr,ll* segtree,int start ,int end,int qstart,int qend,int tnode){
	if(qstart>end||qend<start){
		return LLONG_MAX;
	}
	if(start>=qstart&&end<=qend){
		return segtree[tnode];
	}
	int mid = start + (end - start)/2;
	ll ans1=minrange(arr,segtree,start,mid,qstart,qend,2*tnode);
	ll ans2=minrange(arr,segtree,mid+1,end,qstart,qend,2*tnode+1);
  return min(ans1,ans2);
}
int main() { 
ios_base::sync_with_stdio(false); 
cin.tie(0); 
cout.tie(0);
int n ,i,m;
cin>>n>>m;
ll a[n];
for(i=0;i<n;i++){
	cin>>a[i];
}
ll segtree[4*n];
for(i=0;i<4*n;i++){
	segtree[i]=LLONG_MAX;
}
buildtree(a, segtree,0,n-1,1);
// for(i=0;i<4*n;i++)
//  //cout<<segtree[i]<<" ";
// cout<<endl;
 while(m--){
   char c ; int ind1,ind2;
   ll val;
   cin>>c; 
   if(c=='u'){
   	cin>>ind1>>val;
   	ind1--; 
   	update(a,segtree,0,n-1,1,ind1,val);
   }
   else{
   	cin>>ind1>>ind2;
   	ind1--;ind2--;
   cout<<minrange(a,segtree,0,n-1,ind1,ind2,1)<<endl;
   }
 }



return 0;
}
