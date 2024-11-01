//数组的树的写法
#include<iostream>
using namespace std;
typedef struct node
{
    int data;
    int l,r;
}node;
node num[51];
void preorder(node root)
{
    if(root.data==-1) return;
    cout<<root.data;
    preorder(num[root.l]);
    preorder(num[root.r]);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        num[i].data=i;
        cin>>num[i].l;
        cin>>num[i].r;
    }
    preorder(num[0]);
    
}