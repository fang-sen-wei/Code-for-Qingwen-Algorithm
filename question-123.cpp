//谢尔宾斯基地毯
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

const int maxn=3*3*3*3*3*3*3+2;
//本身的大小是3^n，但是外面还要美观，加上一圈‘+’，所以+2
char res[maxn][maxn];
//定义char数组来存储

//问题关键在于，不加外壳的长度为pow(3,n-1)，总长度还要+2
//子问题的长度为pow(3,n-2),即之间的距离

void bin_mat(int n, int x, int y)
{
    
    if(n==1)
    {
        res[x][y]=' ';
        //n=1时，中间无法填充'X'
    }
    else
    {
        //（n-1）子问题之间的距离为3^(n-2)
        int dis=pow(3,n-2);
        
        //第一行的子问题
        bin_mat(n-1,x,y);
        bin_mat(n-1,x,y+dis);
        bin_mat(n-1,x,y+2*dis);

        //第二行子问题
        bin_mat(n-1,x+dis,y);
        for(int i=x+dis;i<x+2*dis;i++)//在3^n的正方形中间填充'X'
        {
            for(int j=y+dis;j<y+2*dis;j++)
            {
                res[i][j]='X';
            }
        }
        bin_mat(n-1,x+dis,y+2*dis);
        
        bin_mat(n-1,x+2*dis,y);
        bin_mat(n-1,x+2*dis,y+dis);
        bin_mat(n-1,x+2*dis,y+2*dis);

    }
}

int main()
{
    int n;
    scanf("%d",&n);
    fill(res[0],res[0]+maxn*maxn,' ');//char数组全部填充空格
    bin_mat(n,1,1);//从1，1开始处理，外面一圈留给+号

    int k=pow(3,n-1)+2;//总长度
    for(int i=0;i<k;i++)
    {
        res[i][0]='+';//第一列
        res[i][k-1]='+';//最后一列 填充+
    }
    for(int i=0;i<k;i++)
    {
        res[0][i]='+';//第一行
        res[k-1][i]='+';//最后一行 填充+
    }

    for(int i=0;i<k;i++)
    {
        for(int j=0;j<k;j++)
        {
            printf("%c",res[i][j]);
        }
        printf("\n");//打印完一行 换行
    }

}
