#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef struct node
{
    vector<int> children;
}node;
node tree[50];
vector<int> res;

void layer(int root)
{
    queue<int> q;
    q.push(root);
    while(!q.empty())
    {
        int front=q.front();
        q.pop();
        res.push_back(front);
        for(int i=0;i<tree[front].children.size();i++)
        {
            q.push(tree[front].children[i]);
        }
    }
}
int main()
{
    int n,k,child;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&k);
        for(int j=0;j<k;j++)
        {
            scanf("%d",&child);
            tree[i].children.push_back(child);
        }
    }
    layer(0);
    for(int i=0;i<res.size();i++)
    {
        if(i>0) printf(" ");
        printf("%d",res[i]);
    }
}