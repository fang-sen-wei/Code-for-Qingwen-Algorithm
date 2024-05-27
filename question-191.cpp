//鸡兔同笼问题
#include<cstdio>
int main()
{
    int a,b;
    //a头，b脚
    scanf("%d %d",&a,&b);
    for(int i=0;i<=a;i++)//i表示鸡的头的数目
    {   //遍历解方程即可
        if((2*i+4*(a-i))==b)
        {
            printf("%d %d",i,a-i);
            break;
        }
    }
}