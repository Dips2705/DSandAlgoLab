#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mod 1000000007 //1e9+7
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define F first
#define S second
#define ld double
#define ll long long
#define initial(arr,val) memset(arr,val,sizeof(arr)) 
#define value(x) cout << #x << " is " << x << endl;
void dfs(int v,vector<int> adj[],bool visited[],int *count,vector<int> &stck) 
{ 
    visited[v] = true; 
    stck.pb(v);
     vector<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); i++) {
    vector<int>::iterator itr;
    itr= std::find(stck.begin(), stck.end(), *i);
    if(itr!=stck.end()){
    //	cout<<v<<" dhf "<<stck.end()-itr<<endl;
    *count+= stck.end()-itr;
        return ;
    }
    	if(!visited[*i])
        dfs(*i,adj,visited,count,stck); 
        }
} 
int main() { 
ios_base::sync_with_stdio(false); 
cin.tie(0); 
cout.tie(0); 
int t;
cin>>t;
while(t--){
    int n,i;
    cin>>n;
    ll to;
   vector<int> *adj = new vector<int> [n+1];
  // vector<int> adj[n+1];
    for(i=1;i<=n;i++){
        cin>>to;
        if((i+(to%n)+1)%n!=0)
        adj[i].pb((i+(to%n)+1)%n);
        else
        adj[i].pb(n);
    }
    /*for(i=1;i<=n;i++){
    	vector<int>::iterator itr;
    	cout<<i<<" ";
    for(itr = adj[i].begin(); itr != adj[i].end(); itr++){
    	cout<<" "<<*itr;	
	}
	cout<<endl; }*/
    	
    bool visited[n+1]={false};
    int cycle[n+1]={0};
    vector<int> stck;
    int count=0;
    for(i=1;i<=n;i++){
        if(!visited[i]){
            dfs(i,adj,visited,&count,stck);
           // cout<<count<<" "<<i<<endl;
            stck.clear();
        }
    }
    cout<<count<<endl;
    
}


return 0;
}
