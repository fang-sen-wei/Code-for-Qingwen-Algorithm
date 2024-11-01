//有障碍的中国象棋
#include<iostream>
#include<queue>
using namespace std;
typedef struct node
{
    int x;
    int y;
}node;

int n,m;
int num_barrier;

int help[101][101]={0};
int num[101][101]={0};
int res[101][101];
int a[]={-1,1,-1,1,-2,-2,2,2};//按照上下左右的顺序来写
int b[]={2,2,-2,-2,1,-1,1,-1};//每两个为一组
//用于判断落点是否可行
bool judge(int x,int y){
    if(x>=n or y>=m or x<0 or y<0) return false;//超出边界肯定不行
    if(help[x][y]==1 or num[x][y]==1) return false;//走过了，没必要走，或者目的地有障碍物，不能走
    return true;
}
//用于判断是否有马脚
bool judge_new(int x,int y){
    if(x>=n or y>=m or x<0 or y<0) return false;
    if(num[x][y]==1) return false;//有马脚，就false,不需要考虑是否走过，因为现在位置并不在那里
    return true;
}

void bfs(int x,int y)
{
    int step=0;
    queue<node> q;
    node temp={x,y};
    q.push(temp);
    help[x][y]=1;
    while(!q.empty())
    {
        int size=q.size();
        for(int i=0;i<size;i++)
        {
            node front=q.front();
            q.pop();
            res[front.x][front.y]=step;
            for(int j=0;j<8;j++)
            {
                if(!judge_new(front.x,front.y+1) and (j==0 or j==1)) continue;//上面有棋子挡住
                if(!judge_new(front.x,front.y-1) and (j==2 or j==3)) continue;//下面有棋子挡住
                if(!judge_new(front.x-1,front.y) and (j==4 or j==5)) continue;//左面有棋子挡住
                if(!judge_new(front.x+1,front.y) and (j==6 or j==7)) continue;//右面有棋子挡住
                int newx=front.x+a[j];
                int newy=front.y+b[j];
                if(judge(newx,newy))
                {
                    temp.x=newx;
                    temp.y=newy;
                    q.push(temp);
                    help[newx][newy]=1;
                }
            }
        }
        step++;
    }
}


int main()
{
    scanf("%d %d",&n,&m);
    int x,y;//起点
    scanf("%d %d",&x,&y);
    scanf("%d",&num_barrier);
    for(int i=0;i<num_barrier;i++){
        int x_temp,y_temp;
        scanf("%d %d",&x_temp,&y_temp);
        num[x_temp-1][y_temp-1]=1;//位置与索引相差1
    }
    //结果全部初始化为-1；
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            res[i][j]=-1;
        }
    }

    //初始位置与索引也相差1
    bfs(x-1,y-1);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(j>0) cout<<" ";
            cout<<res[i][j];
        }
        cout<<endl;
    }
}
