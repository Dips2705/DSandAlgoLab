#include<bits/stdc++.h>

using namespace std;

vector<vector<string>> radixsort(vector<vector<string>> v,int n)
{
	vector<vector<string>> v1(20);
	for(int k=0;k<20;k++)
	{
		for(int i=0;i<v[k].size();i++)
		{
			if(v[k][i].length()<n)
				v1[(v[k][i][0]-'0')*2].push_back(v[k][i]);
			else v1[(v[k][i][n-1]-'0')*2+1].push_back(v[k][i]);
		}
	}
	if(n==1)
		return v1;
	else return radixsort(v1,n-1);
}

int main()
{
	long long t;
	cin>>t;
	while(t--)
	{
		long long q;
		string s;
		cin>>q;
		vector<vector<string>> v(20),v1;
		for(int i=0;i<q;i++)
		{
			cin>>s;
			v[s[0]-'0'].push_back(s);
		}
		// for(int k=0;k<11;k++)
		// {
		// 	for(int i=0;i<v[k].size();i++)
		// 		cout<<v[k][i]<<' ';
		// 	cout<<endl;
		// }
		v1=radixsort(v,41);
		for(int i=19;i>=0;i--)
		{
			for(int k=v1[i].size()-1;k>=0;k--)
				cout<<v1[i][k];
		}
		// for(int k=0;k<11;k++)
		// {
		// 	for(int i=0;i<v1[k].size();i++)
		// 		cout<<v1[k][i]<<' ';
		// 	cout<<endl;
		// }
		cout<<endl;
	}
	return 0;
}