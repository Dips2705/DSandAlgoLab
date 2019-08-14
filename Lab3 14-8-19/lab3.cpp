#include<bits/stdc++.h>
using namespace std;


bool bracketsMatch(string exp)
{
	stack<char> s;
	char c;
	for (int i=0; i<exp.length(); i++) 
	{ 
		if (exp[i]=='('||exp[i]=='['||exp[i]=='{'||exp[i]=='<'||exp[i]=='|') 
		{ 
			s.push(exp[i]); 
			continue; 
		} 
		if (s.empty()) 
			return false; 

		switch (exp[i]) 
		{ 
			case ')': 

			c = s.top(); 
			s.pop(); 
			if (c=='{' || c=='[' || c=='<') 
				return false; 
			else if(c=='|')
			{	
				int cnt=1;
				while(s.empty()!=true&&s.top()=='|')
				{
					cnt++;
					s.pop();
				}
				if(cnt%2==1)
					return false;
				else if(!s.empty())
				{
					c=s.top();
					s.pop();
					if (c=='{' || c=='[' || c=='<') 
						return false; 
				}
				else if(s.empty())
					return false;
			}

			break; 

			case '}': 

			c = s.top(); 
			s.pop(); 
			if (c=='(' || c=='[' || c=='<') 
				return false; 
			else if(c=='|')
			{	
				int cnt=1;
				while(s.empty()!=true&&s.top()=='|')
				{
					cnt++;
					s.pop();
				}
				if(cnt%2==1)
					return false;
				else if(!s.empty())
				{
					c=s.top();
					s.pop();
					if (c=='(' || c=='[' || c=='<') 
						return false; 
				}
				else if(s.empty())
					return false;
			}
			break; 

			case ']': 

			c = s.top(); 
			s.pop(); 
			if (c =='(' || c == '{' || c=='<') 
				return false;
			else if(c=='|')
			{	
				int cnt=1;
				while(s.empty()!=true&&s.top()=='|')
				{
					cnt++;
					s.pop();
				}
				if(cnt%2==1)
					return false;
				else if(!s.empty())
				{
					c=s.top();
					s.pop();
					if (c=='{' || c=='(' || c=='<') 
						return false; 
				}
				else if(s.empty())
					return false;
			} 
			break; 

			case '>':

			c = s.top(); 
			s.pop(); 
			if (c =='(' || c == '{' || c=='[') 
				return false; 
			else if(c=='|')
			{	
				int cnt=1;
				while(s.empty()!=true&&s.top()=='|')
				{
					cnt++;
					s.pop();
				}
				if(cnt%2==1)
					return false;
				else if(!s.empty())
				{
					c=s.top();
					s.pop();
					if (c=='{' || c=='[' || c=='(') 
						return false; 
				}
				else if(s.empty())
					return false;
			}

			break;

		} 
	}
	if(s.empty())
		return true; 
	else
	{	

		int cnt=0;
		while(s.empty()!=true&& s.top()=='|')
		{
			s.pop();
			cnt++;
		}

		if(cnt%2==0)
			return true;
		else
			return false;
	} 
}

int main() 
{ 	
	int t;
	cin>>t;
	while(t--)
	{
		string exp;
		cin>>exp;

		if (bracketsMatch(exp)) 
			cout << "YES"<<endl; 
		else
			cout << "NO"<<endl;
	} 
	return 0; 
}