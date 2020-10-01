#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi vector<ll>
#define pi pair<ll,ll>
#define vp vector<pi>
#define mp map<ll,ll>
#define pb push_back
#define endl '\n'
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define INF 1e+9
int32_t main(){
    fast;
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        vector<vi> v(n, vi (m,0));
        vector<vi> d(n, vi (m,0));
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<m;j++)
            cin>>v[i][j];
        }
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<m;j++)
            cin>>d[i][j];
        }
        vector<vi> dp(n, vi (m,INF));
        ll cm=INF;
        
        for(ll i=0;i<m;i++)dp[0][i]=v[0][i];
        
        for(ll i=1;i<n;i++)
        {
            cm=*min_element(dp[i-1].begin(),dp[i-1].end());
            for(ll j=0;j<m;j++)
                dp[i][j]=min(cm+v[i][j],dp[i-1][j]+max(v[i][j]-d[i-1][j],0LL));
        }
        
        cm=*min_element(dp[n-1].begin(),dp[n-1].end());
        
        cout<<cm<<endl;
        v.clear();
        dp.clear();
        d.clear();
    }
}