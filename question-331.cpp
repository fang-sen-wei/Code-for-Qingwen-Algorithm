//树的层序遍历 ，即bfs
//数组的树的写法
#include<iostream>
#include<queue>
using namespace std;
typedef struct node
{
    int data;
    int l,r;
}node;
node num[51];
int first=0;

void order(int root)
{
    queue<int> q;
    q.push(root);//根节点入队
    while(!q.empty())
    {
        int size=q.size();//本层元素的个数
        for(int i=0;i<size;i++)
        {
            int front=q.front();//队头元素
            q.pop();//出队
            if(num[front].data!=-1)//打印
            {
                if(first==0) first=1;
                else cout<<" ";
                cout<<num[front].data;
            }
            //左右子树入队哈哈哈哈
            if(num[front].l!= -1) q.push(num[front].l);
            if(num[front].r!= -1) q.push(num[front].r);
        }
    }
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
    order(0);
    
}