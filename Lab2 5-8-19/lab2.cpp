#include<bits/stdc++.h>
using namespace std;

struct Point{
	int x,y;
	struct Point* next;
};

struct Point *head=NULL;

void AddFirst(int x,int y)
{
	struct Point *temp=(struct Point*)malloc(sizeof(struct Point));
	if(temp==NULL)
	{
		cout<<-1<<endl;
		return;
	}
	temp->x=x;
	temp->y=y;
	temp->next=head;
	head=temp;
}

void DelFirst()
{
	if(head!=NULL)
	{
		struct Point *temp=head;
		head=head->next;
		free(temp);
	}
	else 
		cout<<-1<<endl;
}

void Del(int x,int y)
{
	struct Point *temp=head,*prev=NULL;
	while(temp!=NULL)
	{
		if(temp->x==x&&temp->y==y)
		{
			if(prev==NULL)
				head=temp->next;
			else 
				prev->next=temp->next;
			free(temp);
			return;
		}
		prev=temp;
		temp=temp->next;
	}
	cout<<-1<<endl;

}

int length()
{
	struct Point *temp=head;
	int c=0;
	while(temp!=NULL)
	{
		c++;
		temp=temp->next;
	}
	return c;
}


bool search(int x,int y)
{
	struct Point *temp=head;
	while(temp!=NULL)
	{
		if(temp->x==x && temp->y==y)
			return true;
		temp=temp->next;
	}
	return false;
}


void search(float d)
{
	struct Point *temp=head;
	int cnt=0;
	if(head==NULL)
		cout<<-1<<endl;
	else
	{
		while(temp!=NULL)
		{
			float f=(temp->x*temp->x + temp->y*temp->y);
			if(f<=d*d)
				cnt++;
			temp=temp->next;
		}
		cout<<cnt<<endl;
	}
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,x,y;
		float d;
		cin>>n;
		switch(n)
		{
			case 1:
			cin>>x>>y;
			AddFirst(x,y);
			break;
			case 2:
			DelFirst();
			break;
			case 3:
			cin>>x>>y;
			Del(x,y);
			break;
			case 4:
			cin>>d;
			search(d);
			break;
			case 5:
			cin>>x>>y;
			if(search(x,y))
			cout<<"True"<<endl;
			if(!(search(x,y)))
			cout<<"False"<<endl;
			break;
			case 6:
			cout<<length()<<endl;
			break;
		}
	}
	return 0;
}
