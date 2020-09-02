#include<bits/stdc++.h>
#define ll long long int
using namespace std;
class Node
{
public:
	ll data;
	Node*leftchild=NULL;
	Node*rightchild=NULL;
}*t=NULL;
void insert(Node *temp,ll key)
{
	queue<Node*>q;
	q.push(temp);
	while(!q.empty())
	{
		Node*z=q.front();
		q.pop();
		if(z->leftchild==NULL && z->data>key)
		{
			t=new Node();
			t->data=key;
			z->leftchild=t;
			break;
		}
		else if(z->leftchild!=NULL)
		{
			q.push(z->leftchild);
		}
		if(z->rightchild==NULL && z->data<key)
		{
			t=new Node();
			t->data=key;
			z->rightchild=t;
			break;
		}
		else if(z->rightchild!=NULL)
		{
			q.push(z->rightchild);
		}
	}
}
void inorder(Node*temp)
{
	stack<Node*>st;
	Node*t=temp;
	while(t!=NULL || st.empty()==false)
	{
		while(t!=NULL)
		{
			st.push(t);
			t=t->leftchild;
		}
		t=st.top();
		st.pop();
		cout<<t->data<<" ";
		t=t->rightchild;
	}
}
int main()	
{
	ll n,a;cin>>n;//Number of nodes
	vector<ll>v;
	Node*root=NULL;
	for(ll i=0;i<n;i++)
	{
		cin>>a;
		v.push_back(a);
	}
	for(ll i=0;i<n;i++)
	{
	    if(root==NULL)
	    {
	        t=new Node();
	        t->data=v[i];
	        root=t;
	    }
	    else
	    {
	        insert(root,v[i]);
	    }
	}
	inorder(root);
}