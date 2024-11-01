#include<cstdio>
#include<vector>
#include<numeric>
#include<iostream>
using namespace std;
typedef struct node
{
    int lchild;
    int rchild;
}node;
node tree[50];
int num;
int values[50]={0};
vector<int> a;
void add_values(int root, int layer)
{   
    //无子女，则为叶子，计算其带权路径加入
    if(tree[root].lchild==-1 and tree[root].rchild==-1)
    {
        a.push_back(layer*values[root]);
        return;
    }
    //判断是否有左右子女，并计算
    if(tree[root].lchild != -1) add_values(tree[root].lchild, layer+1);
    if(tree[root].rchild != -1) add_values(tree[root].rchild, layer+1);
}

int main()
{
    
    scanf("%d",&num);
    for(int i=0;i<num;i++)
    {
        scanf("%d",&values[i]);
    }
    for(int i=0;i<num;i++)
    {
        scanf("%d %d",&tree[i].lchild,&tree[i].rchild);
    }
    add_values(0,0);
    //这里accumulate的参数为地址，对于vector容器来说是迭代器才行，在numeric库中
    cout<<accumulate(a.begin(),a.end(),0);
}