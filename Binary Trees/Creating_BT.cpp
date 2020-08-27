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
void inorder(Node* temp) 
{ 
    if (!temp) 
        return; 
  
    inorder(temp->leftchild); 
    cout << temp->data<< " "; 
    inorder(temp->rightchild); 
} 
int main()
{
	ll n,a;cin>>n;
	vector<ll>v;
	for(ll i=0;i<n;i++)
	{
		cin>>a;	
		v.push_back(a);
	}
	Node*root=NULL;
	for(ll i=0;i<n;i++)
	{
		if(root==NULL)
		{
			t=new Node();
			t->data=v[i];
			root=t;
		}
		else insert(root,v[i]);
	}
	inorder(root);
}