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
	long long int n;
	cout<<"Enter a number:\n";
	cin>>n;
	int p=prime(n);
	if(p)
		cout<<"Prime\n";
	else
		cout<<"Not Prime\n";
	return 0;
}


