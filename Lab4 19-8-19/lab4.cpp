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
    else
    return -1; 
} 

bool isop(char c)
{
    if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^')
    return true;
    return false;
}

int equivalence(char c)
{
    if(c=='+')
        return -1;
    else if(c=='-')
        return -2;
    else if(c=='*')
        return -3;
    else if(c=='/')
        return -4;
    else if(c=='^')
        return -5;
}

stack<int> postfix(char *s)
{
    stack<int> S,ev;
    int f=0,a;
    ev.push('N');
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            if(f)
            {
                a=S.top();
                S.pop();
                S.push(a*10+s[i]-'0');
            }
            else 
            {
                S.push(s[i]-'0');
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
                    S.push(equivalence(c));
                }
                if(ev.top()=='(')
                    ev.pop();   
            }
            else if(isop(s[i])&&s[i]!='^')
            {
                while(ev.top()!='N'&&ev.top()!='('&&precedence(s[i])<=precedence(ev.top()))
                {
                    char c=ev.top();
                    ev.pop();
                    S.push(equivalence(c));
                }
                ev.push(s[i]);
            }
            else if(s[i]=='^')
            {
                while(ev.top()!='N'&&ev.top()!='('&&precedence(s[i])<precedence(ev.top()))
                {
                    char c=ev.top();
                    ev.pop();
                    S.push(equivalence(c));
                }
                ev.push(s[i]);
            }
        }
    }
    while(ev.top()!='N')
        {
            char c=ev.top();
            ev.pop();
            S.push(equivalence(c));
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

tree * exptree(stack<int> s)
{
    tree *t,*t1,*t2;

    stack<tree *> st;
    while(!s.empty())
    {
        if(s.top()>=0)
        {
            t=Node(s.top());
            s.pop();
            st.push(t);
        }
        else
        {
            t=Node(s.top());
            t1=st.top();
            st.pop();
            t2=st.top();
            st.pop();

            if(1)
            {t->right=t1;
            t->left=t2;}

            st.push(t);
            s.pop();
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


int main()
{   
    int q;
    cin>>q;
    while(q--)
    {
        int T;
        cin>>T;
        while(T--)
        {
            char s[10000];
            cin>>s;
            stack <int> S,s1;
            S=postfix(s);
            while(!S.empty())
            {
                s1.push(S.top());
                S.pop();
            }
            
            tree *p=exptree(s1);
            cout<<eval(p)<<endl;

        }
    }
}