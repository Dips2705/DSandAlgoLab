#include<bits/stdc++.h>

using namespace std; 
  
int CustomCompare(string X, string Y) 
{ 

    string XY = X.append(Y); 
  

    string YX = Y.append(X);  
    if(XY.compare(YX)>0)
        return 1;
    else
        return 0;
} 

void printorder(vector<string> arr) 
{ 

    sort(arr.begin(), arr.end(), CustomCompare); 
  
    for (int i=0; i < arr.size() ; i++ ) 
        cout << arr[i]; 
} 

int main() 
{ 
     
    long long t;
    cin>>t;
    while(t--)
    {
        vector<string> arr;
        long long q;
        cin>>q;
        string s;
        while(q--)
        {
            cin>>s;
            arr.push_back(s);
            
        }
        printorder(arr); 
        cout<<endl;
    }
   return 0; 
} 