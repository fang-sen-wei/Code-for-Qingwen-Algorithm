//盒分形问题
//n为输入，那么盒分形总长度为3^(n-1),每一个子问题的长度为3^(n-2)
//每个盒分形就是分为左上，右上，中间，左下，右下 五个部位的子图形构成
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
const int a=3*3*3*3*3*3*3;
char res[a][a];
void hezi(int n, int x, int y)
{
    if(n==1) res[x][y]='X';
    else
    {
        int dis=pow(3,n-2);       //n时的每个子图形之间的距离为3^(n-2)
        hezi(n-1,x,y);            //左上角的子图形
        hezi(n-1,x,y+2*dis);      //右上角的子图形
        hezi(n-1,x+dis,y+dis);    //中间的子图形
        hezi(n-1,x+2*dis,y);      //左下角的子图形
        hezi(n-1,x+2*dis,y+2*dis);//右下角的子图形
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    
    fill(res[0],res[0]+a*a,' ');  //填充字符数组，使得全部为‘ ’;
    //fill函数在algorithm中，fill（开始地址，结束地址+1，填充内容）
    
    hezi(n,0,0);
    
    int length=pow(3,n-1);
    for(int i=0;i<length;i++)
    {
        for(int j=0;j<length;j++)
        {
            printf("%c",res[i][j]);
        }
        printf("\n");//每行输出结束，换行
    }
}