#include<bits/stdc++.h>

using namespace std;

int c[1000][1000]={0},v[1000][1000]={1};
long long S;
long long count(long long i,long long j,long long n,long long m)
{
    v[i][j]=0;
    S++;
    if(i>0)
    {
        if(c[i-1][j]&&v[i-1][j])
        count(i-1,j,n,m);
    }
    if(j>0)
    {
        if(c[i][j-1]&&v[i][j-1])
        count(i,j-1,n,m);
    }
    if(i<n-1)
    {
        if(c[i+1][j]&&v[i+1][j])
        count(i+1,j,n,m);
    }
    if(j<m-1)
    {
        if(c[i][j+1]&&v[i][j+1])
        count(i,j+1,n,m);
    }
    return S;
}

int main()
{
    long long n,m;
    cin>>n>>m;
    long long k;
    cin>>k;
    vector<pair<long long,long long>> V;
    long long x,y;
    long long M=0;
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    {
        v[i][j]=1;
        c[i][j]=0;
    }
    for(int i=0;i<k;i++)
    {
        cin>>x>>y;
        x--;
        y--;
        V.push_back({x,y});
        c[x][y]=1;
    }
    
    for(int i=0;i<k;i++)
    {
        
        if(v[V[i].first][V[i].second])
        {
            S=0;
            long long C=count(V[i].first,V[i].second,n,m);
            M=max(M,C);
        }
    }
    cout<<M<<endl;
}
