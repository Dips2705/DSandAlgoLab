#include<iostream>
#include<bits/stdc++.h>
using namespace std;
string add(string s1, string s2)
{
	int c=0,i,sum;
	if(s1.length()>s2.length())
		swap(s1,s2);
	int n1=s1.length();
	int n2=s2.length();
	string s3="";
	int diff=n2-n1;
	for(i=n2-1;i>=0;i--)
	{
		sum = ((s1[i]-'0') + (s2[i+diff]-'0') + c); 
		s3.push_back(sum%10 + '0'); 
		c = sum/10;
	}
	for (i=n2-n1-1; i>=0; i--) 
	{ 
		sum = ((s2[i]-'0')+c); 
		s3.push_back(sum%10 + '0'); 
		c = sum/10; 
	} 
	if (c) 
		s3.push_back(c+'0'); 
	reverse(s3.begin(), s3.end()); 

	return s3; 
} 

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
	string s1="",s2="",s3="";
	cout<<"Enter two numbers:\n";
	cin>>s1>>s2;
	s3=add(s1,s2);
	cout<<"Sum = "<<s3;
	long long int n;
	cout<<"Enter a number";
	cin>>n;
	int p=prime(n);
	cout<<bool(p);
	return 0;
}


