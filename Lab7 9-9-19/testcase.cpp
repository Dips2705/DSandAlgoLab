#include<bits/stdc++.h>
using namespace std;
int main()
{
	srand(time(NULL));
	long long t;
	cin>>t;
	cout<<t<<endl;
	while(t--)
	{
		long long q;
		cin>>q;
		cout<<q<<endl;
		while(q--)
		{
			int d;
			d = rand() % 30 + 1;
			cout<<rand()%9 +1;
			d--;
			while(d--)
				cout<<rand()%10;
			cout<<endl;
		}
	}
}