#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    long long n;
    cin >> n;
    long long a, b, m = 1000000007;
    cin >> a >> b;
    int leng[n];
    long long sum = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> leng[i];
        sum = sum + leng[i];
    }
    long long int res = 0, ans = 0;
    stack <int> st;
    for(int i = 0; i < n; i++)
    {
        while(st.empty() == false && leng[i] <= leng[st.top()])
        {
            long long int tp = st.top();
            st.pop();
            if(st.empty())
                res=leng[tp]*i;
              else
                res=leng[tp]*(i - st.top() - 1);
            ans = max(ans % m, res);
        }
        st.push(i);
    }
    while(st.empty() == false)
    {
        long long int tp = st.top();
        st.pop();
        if(st.empty())
                res=leng[tp]*n;
              else
                res=leng[tp]*(n - st.top() - 1);
        ans = max(ans % m, res);
    }
    //cout<<ans<<endl;
    cout << ((sum % m - ans % m) % m * a % m * b % m) % m;
}