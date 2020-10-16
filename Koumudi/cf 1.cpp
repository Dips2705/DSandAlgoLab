#include <bits/stdc++.h>
using namespace std;

int main() 
{
    long long int n,x;
    cin>>n;
    cin>>x;
    long long int e[n],b[n],i,c=0;
    for (i=0;i<n;i++)
    {
        cin>>e[i];
    }
    for (i=0;i<n;i++)
    {
        cin>>b[i];
    }
    pair<long long int, long long int> pairt[n]; 
    for (i = 0; i < n; i++)  
    { 
        pairt[i].first = e[i]; 
        pairt[i].second = b[i]; 
    } 
 
    sort(pairt, pairt + n); 

    for (i = 0; i < n; i++)  
    { 
        e[i] = pairt[i].first; 
        b[i] = pairt[i].second; 
        cout<<e[i]<<" ";
    }
    cout<<endl;
    for (i=0;i<n;i++)
    {
        if (x>e[i])
        {
            c++;
            x=x+b[i];
        }
        else
        {
            break;
        }
    }
    cout<<c;
	return 0;
}
