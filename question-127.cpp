//递归调试
#include<cstdio>
int fibo(int n,int depth)
{//每次输出n之前，要输出（深度-1）*4的空格
    for(int i=0;i<4*(depth-1);i++)
    {
        printf(" ");
    }
    printf("n=%d\n",n);
    if(n<=2) return 1;
    else
    {
        return fibo(n-1,depth+1)+fibo(n-2,depth+1);
    } 
}
int main()
{
    int n;
    scanf("%d",&n);
    fibo(n,1);
}