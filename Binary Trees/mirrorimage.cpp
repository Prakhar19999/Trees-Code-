#include<bits/stdc++.h>
#define ll long long int
using namespace std;
struct Node {
    ll data;
    Node* lchild;
    Node* rchild;
    Node* parent;
    Node(ll x) {
        data=x;
        lchild=NULL;
        rchild=NULL;
        parent=NULL;
    }
};

ll mirrorelement(Node*root,Node*temp)
{
    if(root==temp)return(temp->data);
    stack<char>st;
    while(temp->parent!=NULL)
    {
        if(temp->parent->rchild==temp)
        {
            st.push('L');
        }
        else 
        {
            st.push('R');
        }
        temp=temp->parent;
    }
    while(!st.empty())
    {
        char ch=st.top();
        st.pop();
        if(ch == 'L' && root->lchild!=NULL)
            root = root->lchild;
        else if(ch == 'L')
            return (-1);
        else if( root->rchild!= NULL )   
            root = root->rchild;
        else
            return (-1);
    }
    return root->data;
}

int main()
{
    ll n,q;cin>>n>>q;
    Node*a[n+1];
    for(ll i=0;i<n+1;i++)a[i]=new Node(i);
    ll u,v;
    char c;
    for(ll i=0;i<n-1;i++)
    {
        cin>>u>>v>>c;
        if(c=='R')a[u]->rchild=a[v];
        else a[u]->lchild=a[v];

        a[v]->parent=a[u];
    }
    
    Node*root=a[1];
    while(q--)
    {
        cin>>u;
        cout<<mirrorelement(root,a[u])<<endl;
    }
}