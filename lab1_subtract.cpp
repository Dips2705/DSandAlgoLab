#include<iostream>
#include<bits/stdc++.h> 
using namespace std; 

int findSmaller(string str1, string str2) 
{ 

    int n1 = str1.length();
    int n2 = str2.length();
  
    if (n1 < n2) 
        return 1; 
    if (n2 > n1) 
        return 0; 
  
    for (int i=0; i<n1; i++) 
    { 
        if (str1[i] < str2[i]) 
            return 1; 
        else if (str1[i] > str2[i]) 
            return 0; 
    } 
    return 0; 
} 

string diff_nos(string str1, string str2) 
{ 

    if (findSmaller(str1, str2)) 
        swap(str1, str2); 
  

    string str = ""; 
  

    int n1 = str1.length();
    intn2 = str2.length(); 
    int diff = n1 - n2; 
  

    int carry = 0; 
  

    for (int i=n2-1; i>=0; i--) 
    { 

        int sub = ((str1[i+diff]-'0') - (str2[i]-'0') - carry); 
        if (sub < 0) 
        { 
            sub = sub+10; 
            carry = 1; 
        } 
        else
            carry = 0; 
  
        str.push_back(sub + '0'); 
    } 
  
    for (int i=n1-n2-1; i>=0; i--) 
    { 
        if (str1[i]=='0' && carry) 
        { 
            str.push_back('9'); 
            continue; 
        } 
        int sub = ((str1[i]-'0') - carry); 
        if (i>0 || sub>0) 
            str.push_back(sub+'0'); 
        carry = 0; 
  
    } 
  

    reverse(str.begin(), str.end()); 
  
    return str; 
} 
  

int main() 
{ 
    string str1 = "",str2="";
    cout<<"Enter two numbers \n";
    cin>>str1>>str2;
    if(findSmaller(str1,str2))
        cout<<"-";
    cout << diff_nos(str1, str2)<<endl; 
    return 0; 
}