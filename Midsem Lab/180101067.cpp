#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	long long fact[n+1]={1};
	int i;
	for(i=1;i<=n;i++)
		fact[i]=fact[i-1]*i;
	// for(i=0;i<=n;i++)
	// 	cout<<fact[i]<<endl;
	int q;
	cin>>q;
	while(q--)
	{
		int x,y,p;
		cin>>x>>y;
		p=(x==-1)?(y-1):(n-y);
		int a,b,c,i=0,j=0,k=0;
		long long sum=0;
		a=p/3;
		b=p/5;
		c=p/7;
		int m=p;
		// cout<<a<<b<<c<<endl;
		for(k=0;(p-k*7>=0);k++)
		{
			i=0;
			j=0;
			int z=p-k*7;
			// cout<<p<<endl;
			if(z==0)
			{
				sum=sum+((fact[i+j+k])/(fact[i]*fact[j]*fact[k]));
				
				// cout<<sum<<endl;
				break;
			}
			for(j=0;j<=b;j++)
			{
				i=0;
				int s=z-j*5;
				if(s==0){
					sum=sum+((fact[i+j+k])/(fact[i]*fact[j]*fact[k]));
					
					
					// cout<<sum<<endl;
					break;
				}
				if(s%3==0)
				{
					i=s/3;
					// cout<<fact[i+j+k]<<endl;
					// cout<<fact[i]<<endl;
					// cout<<fact[j]<<endl;
					// cout<<fact[k]<<endl;
					sum=sum+((fact[i+j+k])/(fact[i]*fact[j]*fact[k]));

				// cout<<sum<<endl;
				}
			}
		}
		long long ans=(sum)%(10000001);
		cout<<ans<<endl;
	}
}