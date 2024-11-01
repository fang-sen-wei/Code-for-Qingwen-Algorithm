#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef struct node
{
    int lchild;
    int rchild;
    int layer;
}node;

int n;
node tree[50];
vector<int> result;
//层序遍历,将每层第一个元素加入vector
void print_left(int root)
{
    queue<int> q;
    q.push(root);
    tree[0].layer=0;
    int ind=0;
    while(!q.empty())
    {
        int front=q.front();
        q.pop();
        if(tree[front].layer==ind)
        {
           result.push_back(front); 
           ind++;
        } 
        if(tree[front].lchild != -1)
        {
           q.push(tree[front].lchild); 
           tree[tree[front].lchild].layer=tree[front].layer+1;
        } 
        if(tree[front].rchild != -1)
        {
           q.push(tree[front].rchild); 
           tree[tree[front].rchild].layer=tree[front].layer+1;
        } 
    }
    
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int lchild,rchild;
        scanf("%d %d",&lchild, &rchild);
        tree[i].lchild=lchild;
        tree[i].rchild=rchild;
    }
    print_left(0);
    for(int i=0;i<result.size();i++)
    {
        if(i>0) printf(" ");
        printf("%d",result[i]);
    }
}