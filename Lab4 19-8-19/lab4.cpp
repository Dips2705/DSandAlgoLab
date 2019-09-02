#include<bits/stdc++.h>

using namespace std;

struct tree 
{
    int i;
    tree * left,* right,* parent;
};

int precedence(char c) 
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



vector<int > postfix(string s)
{
    vector<int > S;
    stack<int> ev;
    int f=0,a;
    ev.push('N');
    for(int i=0;i<s.length();i++)
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

tree * Node(int v)
{
    tree * temp=new tree;
    temp->left = NULL;
    temp->right = NULL; 
    temp->i = v; 
    return temp; 
}

tree * exptree(vector<int > v)
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


int eval(tree* root)  
{  
    if (!root)  
        return 0;  
    if (!root->left && !root->right)  
        return root->i;  
    int l_val = eval(root->left);  
    int r_val = eval(root->right);  
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

int value(string s)
{
    vector <int > S;
    S=postfix(s);
    tree *p=exptree(S);
    return eval(p);
}

void evaluate(string s,unordered_map<string,int> *M)
{
    string s1="";
    vector<int> dl;
    int u=1;
    dl.push_back(-1);
    for(int i=0;i<s.length();i++)
    {
        if(u&&s[i]=='-')
        {
            s[i]='$';
            s.insert(i,"0");
        }
        if(isop(s[i])||s[i]=='(')
            u=1;
        else u=0;
        if(isop(s[i])||s[i]=='('||s[i]==')'||s[i]=='=')
        {
            dl.push_back(i);
        }
    }
    dl.push_back(s.length());

    string t,v="";
    if(s[dl[1]]=='=')
    {
        v=s.substr(dl[0]+1,dl[1]-dl[0]-1);
        dl[0]=dl[1];
        dl.erase(dl.begin()+1);
    }
    for(int i=0;i<dl.size()-1;i++) 
    {
        t=s.substr(dl[i]+1,dl[i+1]-dl[i]-1);
        if(!t.size())
            {
                s1+=s[dl[i+1]];
                continue;
            }
        if(isdigit(t[0]))
        {
            s1+=t;
        }
        else
        {
            auto itr=M->find(t);
            if(itr==M->end())
            {
                cout<<"CANT BE EVALUATED"<<endl;
                return;
            }
            else
            {
                s1+=to_string(itr->second);
            }
        }
        if(i+1<dl.size())
        {
            s1+=s[dl[i+1]];
        }
    }
    if(v.length())
    {
        auto itr=M->find(v);
        if(itr==M->end())
        {
            M->insert({v,value(s1)});
        }
        else itr->second=value(s1);
    }
    else
    {
        cout<<value(s1)<<endl;
    }
    
}

int main()
{   
    int q;
    cin>>q;
    while(q--)
    {
        int T;
        cin>>T;
        unordered_map<string,int> M;
        while(T--)
        {
            int u=1;
            string s;
            cin>>s;
            evaluate(s,&M);
        }
    }
}