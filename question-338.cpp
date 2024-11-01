#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;
typedef struct node{
    int l,r;
}node;
node tree[51];

vector<int> layer;
vector<int> in;
int first=0;
void pre_order(int root)
{
    if(root==-1) return;
    if(first==1) first=1;
    else cout<<" ";
    cout<<root;
    pre_order(tree[root].l);
    pre_order(tree[root].r);
}

int biuld_tree(vector<int> layer, int inL, int inR)
{
    if(layer.empty()) return -1;
    int root=layer[0];
    int k;
    map<int,bool> isleft;
    for(k=inL;k<=inR;k++)
    {
        if(in[k]==root) break;
        else isleft[in[k]]=true;
    }
    vector<int> leftlayer;
    vector<int> rightlayer;
    //layer[0]是根节点，然后从根节点往后找。
    for(int i=1;i<layer.size();i++)
    {
        if(isleft[layer[i]]) leftlayer.push_back(layer[i]);
        else rightlayer.push_back(layer[i]);
    }
    tree[root].l=biuld_tree(leftlayer,inL,k-1);
    tree[root].r=biuld_tree(rightlayer,k+1,inR);
    return root;
}
int main()
{
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        layer.push_back(x);
    }
    for(int i=0;i<n;i++)
    {
        cin>>x;
        in.push_back(x);
    }
    int root=biuld_tree(layer,0,n-1);
    pre_order(root);

}