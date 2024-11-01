//迷宫最短路径
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
int help[101][101]={0};//是否经过
int num[101][101];//权重或者数字
node pre[101][101];//前驱节点！
bool judge(int x, int y)//是否有效的节点
{
    if(x>=n or y>=m or x<0 or y<0) return false;
    if(help[x][y]==1 or num[x][y]==1) return false;
    return true;
}

int bfs(int x, int y)
{
    int step=0;//步数，初始为0
    queue<node> q;
    node temp;
    temp.x=x;
    temp.y=y;
    help[x][y]=1;//起始点占用
    pre[x][y]={-1,-1};//起始点的前驱为-1，-1
    q.push(temp);//入队

    while(!q.empty())//没有元素说明没有下一层的元素（相邻）节点符合！
    {
        int size=q.size();//本层元素的个数
        for(int i=0;i<size;i++)//遍历本层元素
        {
            node front=q.front();//取出队头
            q.pop();

            if(front.x==n-1 and front.y==m-1)//队头符合条件即返回！结束bfs，且一定是最短的路径
            {
               return step; 
            } 
            //队头向相邻节点（下一层元素）探索，若符合条件，则入队，且设为占有
            for(int j=0;j<4;j++)
            {
                if(judge(front.x+a[j], front.y+b[j]))
                {
                    help[front.x+a[j]][front.y+b[j]]=1;
                    pre[front.x+a[j]][front.y+b[j]]=front;//他们的前驱节点为front
                    temp.x=front.x+a[j];
                    temp.y=front.y+b[j];
                    q.push(temp);
                }
            }
        }
        step++;//每一层代表一步，步数+1
    }
    return -1;//没有元素符合出口（抵达不了出口），返回-1
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
    
    int step=bfs(0,0);

    vector<node> result;
    int x=n-1;
    int y=m-1;
    while(true)
    {
        result.insert(result.begin(),pre[x][y]);
        int newx=pre[x][y].x;//一定要新建一个int对象，否则会改变内容
        int newy=pre[x][y].y;//要保证新的x，y用的都是旧的x和y才对
        x=newx;
        y=newy;
        if(newx==0 and newy==0) break;
    }
    for(int i=0;i<result.size();i++)
    {
        cout<<result[i].x+1<<" "<<result[i].y+1<<endl;
    }
    cout<<n<<" "<<m;
}