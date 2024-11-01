//前序中序还原树
//数组的树的写法

#include<iostream>
#include<queue>
using namespace std;
typedef struct node
{
    int l,r;
}node;
//编号就是data，就是num的下标，所以不需要再来一个int data;
node num[51];
int first=0;
int pre[51];//前序序列
int in[51];//中序序列
int create(int preL, int preR, int inL, int inR)
{
    if(preL>preR) return -1;
    int root=pre[preL];//根节点即preL位置的编号
    int k;
    //在中序中遍历找到根
    for(k=inL;k<=inR;k++)
    {
        if(in[k]==pre[preL])//在数字编号的存储里，编号刚好就是data
        {
           break;
        } 
    }
    int number=k-inL;
    num[root].l=create(preL+1,preL+number,inL,inL+number);
    num[root].r=create(preL+1+number,preR,k+1,inR);
    return root;
}
//后序遍历
void after_order(int root)
{
    if(root==-1) return;
    after_order(num[root].l);
    after_order(num[root].r);
    if(first==0) first=1;
    else cout<<" ";
    cout<<root;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>pre[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>in[i];
    }
    int root=create(0,n-1,0,n-1);
    after_order(root);
}