#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int prime(long long int n)
{
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0)
			return 0;
	}
	return 1;
}

int main()
{
	int t,i;
	cin>>t;
	long long int n[t];
	for(i=0;i<t;i++)
	{
		cin>>n[i];
	}
	for(i=0;i<t;i++)
	{
		int p=prime(n[i]);
		if(p)
			cout<<"Prime\n";
		else
			cout<<"Not Prime\n";
	}

	return 0;
}


