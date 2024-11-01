//数字块问题
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
typedef struct node
{
    int x;
    int y;
}node;
int a[]={0,0,1,-1};
int b[]={1,-1,0,0};
int n,m;
int help[101][101]={0};
int num[101][101];
bool judge(int x, int y)
{
    if(x>=n or y>=m or x<0 or y<0) return false;
    if(help[x][y]==1 or num[x][y]==0) return false;
    return true;
}

void bfs(int x, int y)
{
    queue<node> q;
    node temp;
    temp.x=x;
    temp.y=y;
    help[x][y]=1;
    q.push(temp);
    while(!q.empty())//如果一直走那就是相当于找出路了
    {//我们判断每一个元素可以走到头的层数，给他们全部上标记，那么就是一个块
    //所以要bsf全部的元素才行
        int size=q.size();
        for(int i=0;i<size;i++)//代表一个块的元素
        {
            node front=q.front();
            q.pop();
            for(int j=0;j<4;j++)
            {
                if(judge(front.x+a[j], front.y+b[j]))
                {
                    help[front.x+a[j]][front.y+b[j]]=1;
                    temp.x=front.x+a[j];
                    temp.y=front.y+b[j];
                    q.push(temp);
                }
            }
        }
    }
}

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&num[i][j]);
        }
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(judge(i,j))
            {
                bfs(i,j);
                ans++;
            }
        }
    }
    printf("%d",ans);
}