// 矩阵最大权值及其路径
#include<iostream>
#include<vector>
using namespace std;

typedef struct node
{
    int x;
    int y;
}node;

int a[]={0,0,1,-1};
int b[]={1,-1,0,0};
vector<node> temp;
vector<vector<node>> res;
int n,m;
int num[6][6];
int help[6][6]={0};

bool judge(int x,int y)
{
    if(x>=n or y>=m or x<0 or y<0) return false;
    if(help[x][y]==1) return false;
    return true;
}

int maxsum=-101;
void dfs(int x, int y,int sum)
{
    if(judge(x,y)==false) return;//边界情况退出
    node t;//临时节点
    t.x=x;
    t.y=y;
    temp.push_back(t);
    help[x][y]=1;
    sum=sum+num[x][y];
    if(x==n-1 and y==m-1)
    {
        if(sum>maxsum)
        {
           maxsum=sum; 
           if(res.size()>0) res.pop_back();
           res.push_back(temp);
        } 
        
    }
    else
    {
        for(int i=0;i<4;i++)
        {
            if(judge(x+a[i],y+b[i]))
            {
                dfs(x+a[i],y+b[i],sum);
            }
        }
    }
    //回溯
    temp.pop_back();
    help[x][y]=0;
    sum-=num[x][y];
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

    dfs(0,0,0);
    for(int i=0;i<res[0].size();i++)
    {
        //真实矩阵与索引相差1.得加回去
        printf("%d %d\n",res[0][i].x+1, res[0][i].y+1);
    }
    
}