
#include<bits/stdc++.h> 
using namespace std; 

string multiply(string num1, string num2) 
{ 
	int len1 = num1.size(); 
	int len2 = num2.size(); 
	if (len1 == 0 || len2 == 0) 
	return "0"; 


	vector<int> res(len1 + len2, 0); 

	int i_n1 = 0; 
	int i_n2 = 0; 
	

	for (int i=len1-1; i>=0; i--) 
	{ 
		int c = 0; 
		int n1 = num1[i] - 48; 

		i_n2 = 0; 
		
		 
		for (int j=len2-1; j>=0; j--) 
		{ 

			int n2 = num2[j] - '0'; 

			int sum = n1*n2 + res[i_n1 + i_n2] + c; 


			c = sum/10; 


			res[i_n1 + i_n2] = sum % 10; 

			i_n2++; 
		} 


		if (c > 0) 
			res[i_n1 + i_n2] += c; 

		i_n1++; 
	} 

	int i = res.size() - 1; 
	while (i>=0 && res[i] == 0) 
	i--; 

	if (i == -1) 
	return "0"; 

	string s = ""; 
	
	while (i >= 0) 
		s += std::to_string(res[i--]); 

	return s; 
} 

int main() 
{   
	int n,i;
    cin>>n;
    string no1[n];
    string no2[n];
    for(i=0;i<n;i++)
    {
        cin>>no1[i];
        cin>>no2[i];   
    }
    for(i=0;i<n;i++)
	{
		if((no1[i].at(0) == '-' || no2[i].at(0) == '-') && (no1[i].at(0) != '-' || no2[i].at(0) != '-' )) 
			cout<<"-"; 


		if(no1[i].at(0) == '-' && no2[i].at(0)!='-') 
			{ 
				no1[i] = no1[i].substr(1); 
			} 
			else if(no1[i].at(0) != '-' && no2[i].at(0) == '-') 
			{ 
				no2[i] = no2[i].substr(1); 
			} 
			else if(no1[i].at(0) == '-' && no2[i].at(0) == '-') 
			{ 
				no1[i] = no1[i].substr(1); 
				no2[i] = no2[i].substr(1); 
			} 
		cout << multiply(no1[i], no2[i])<<endl; 
	}
	return 0; 
} 
