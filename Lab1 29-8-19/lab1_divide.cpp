#include <bits/stdc++.h>
using namespace std;



int findMin(string a,string b){
	int n1=a.size(),n2=b.size();
	if(n1<n2) return 1;
	if(n1>n2) return 0;
	for(int i=0;i<n1;i++)
	{
		if(a[i]<b[i]) 
			return 1;
		else if(a[i]>b[i]) 
			return 0;
	}
	return 0;
}
int small(string a,string b){
	int n1=a.size(),n2=b.size();
	if(n1<n2) return 1;
	if(n1>n2) return 0;
	for(int i=0;i<n1;i++){
		if(a[i]<b[i]) return 1;
		else if(a[i]>b[i]) return 0;
	}
	return 1;	
}
string subtract(string a,string b)
{
	string ans="";
	if(findMin(a,b)) {swap(a,b);}
	int n1=a.size(),n2=b.size();
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	int carry=0;
	for(int i=0;i<n2;i++)
	{
		int sub=(a[i]-'0')-(b[i]-'0')-carry;
		if (sub < 0){  
			sub+=10; 
            carry = 1; 
        } 
        else 
        	carry = 0; 
        ans.push_back(sub + '0'); 
	}
	for(int i=n2;i<n1;i++)
	{
		int sub = ((a[i]-'0') - carry);
        if (sub < 0){ 
        	sub = sub + 10; 
            carry = 1; 
        } 
        else 
        	carry = 0;
        ans.push_back(sub + '0'); 
    } 
    reverse(ans.begin(),ans.end()); 
    return ans; 
}
string divide(string &a , string &b){
	string ans="";
	string zero="0";
	if(findMin(a,b)) return zero;
	string r=a.substr(0,b.size());
	if(findMin(r,b)) r+=a[b.size()];
	int sz=r.size();
	while(small(b,r)){
		int i=0;
		while(small(b,r)){
			r=subtract(b,r);
			int count=0;
			for(int j=0;j<r.size();j++){
				if(r[j]!='0') break;
				else count++;
			}
			if(count<r.size()) r=r.substr(count,r.size()-count);
			else r="";
			i++;
		}
		ans+=(i+'0');
		if(sz>=a.size()) break;
		r+=a[sz];
		sz++;
		int count=0;
    	for(int j=0;j<r.size();j++){
			if(r[j]!='0') break;
			else count++;
		}
		if(count<r.size()) r=r.substr(count,r.size()-count);
		else r="";
		while(findMin(r,b)&&sz<a.size()){
			r+=a[sz];
			sz++;
			ans+='0';
			int count=0;
			for(int j=0;j<r.size();j++)
			{
				if(r[j]!='0') break;
				else count++;
			}
			if(count<r.size()) r=r.substr(count,r.size()-count);
			else r="";
		}
	}
	b=r;
	if(b.size()==0) b="0";
	return ans;
}
int main()
{
ios_base::sync_with_stdio(false); 
cin.tie(NULL); 
cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		string a,b;
		cin>>a>>b;
		cout<<divide(a,b)<<endl<<b<<endl;
	}
	return 0;
}