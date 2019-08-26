#include<bits/stdc++.h>

using namespace std;

struct tree 
{
    long long i;
    tree * left,* right,* parent;
};

long long precedence(char c) 
{ 
    if(c == '^') 
    return 3; 
    else if(c == '*' || c == '/') 
    return 2; 
    else if(c == '+' || c == '-') 
    return 1; 
    else if(c=='$')
    return 4;
    else
    return -1; 
} 
int equivalence(char c)
{
    switch(c)
    {
        case '+': return -1;
        case '-': return -2;
        case '*': return -3;
        case '/': return -4;
        case '^': return -5;
        case '$': return -2;
    }
}
int isop(char c)
{
    if(c=='+'||c=='-'||c=='*'||c=='/')
    return 1;
    if(c=='^'||c=='$')
    return 2;
    return 0;
}



vector<long long > postfix(string s)
{
    vector<long long > S;
    stack<long long> ev;
    long long f=0,a;
    ev.push('N');
    for(long long i=0;i<s.length();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            if(f)
            {
                S[S.size()-1]=S[S.size()-1]*10+s[i]-'0';
            }
            else 
            {
                S.push_back(s[i]-'0');
                f=1;
            }
        }

        else 
        {
            f=0;
            if(s[i]=='(')
                ev.push('(');
            else if(s[i]==')')
            {
                while(ev.top()!='N'&&ev.top()!='(')
                {
                    char c=ev.top();
                    ev.pop();
                    S.push_back(equivalence(c));
                }
                if(ev.top()=='(')
                    ev.pop();   
            }
            else if(isop(s[i])==1)
            {
                while(ev.top()!='N'&&ev.top()!='('&&precedence(s[i])<=precedence(ev.top()))
                {
                    char c=ev.top();
                    ev.pop();
                    S.push_back(equivalence(c));
                }
                ev.push(s[i]);
            }
            else if(isop(s[i])==2)
            {
                while(ev.top()!='N'&&ev.top()!='('&&precedence(s[i])<precedence(ev.top()))
                {
                    char c=ev.top();
                    ev.pop();
                    S.push_back(equivalence(c));
                }
                ev.push(s[i]);
            }
        }
    }
    while(ev.top()!='N')
        {
            char c=ev.top();
            ev.pop();
            S.push_back(equivalence(c));
        }
    return S;
}

tree * Node(long long v)
{
    tree * temp=new tree;
    temp->left = NULL;
    temp->right = NULL; 
    temp->i = v; 
    return temp; 
}

tree * exptree(vector<long long > v)
{
    tree *t,*t1,*t2;

    stack<tree *> st;
    for(int i=0;i<v.size();i++)
    {
        if(v[i]>=0)
        {
            t=Node(v[i]);
            st.push(t);
        }
        else
        {
            t=Node(v[i]);
            t1=st.top();
            st.pop();
            t2=st.top();
            st.pop();
            if(1)
            {
                t->right=t1;
                t->left=t2;
            }
            st.push(t);
        }
    }
    return t;
}


long long eval(tree* root)  
{  
    if (!root)  
        return 0;  
    if (!root->left && !root->right)  
        return root->i;  
    long long l_val = eval(root->left);  
    long long r_val = eval(root->right);  
    if (root->i==-1)  
        return l_val+r_val;  
    if (root->i==-2)  
        return l_val-r_val;  
    if (root->i==-3)  
        return l_val*r_val;  
    if(root->i==-4)
        return l_val/r_val;
    return pow(l_val,r_val);  
}   


int main()
{   
    long long q;
    cin>>q;
    while(q--)
    {
        long long T;
        cin>>T;
        while(T--)
        {
            int u=1;
            string s;
            cin>>s;
            for(int i=0;i<s.length();i++)
            {
                if(u&&s[i]=='-')
                {
                    s[i]='$';
                    s.insert(i,"0");
                }
                if(isop(s[i])||s[i]=='(')
                    u=1;
                else 
                    u=0;
            }
            vector <long long > S;

            S=postfix(s);
            tree *p=exptree(S);
            cout<<eval(p)<<endl;
        }
    }
}