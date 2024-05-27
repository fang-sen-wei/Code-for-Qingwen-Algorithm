//分数加减乘除法
#include<cstdio>
#include<algorithm>
using namespace std;
//最小公倍数
int min_bei(int a, int b)
{
    int m=max(a,b);
    int ans;
    for(int i=m;i<=a*b;i++)
    {
        if(i%a==0 and i%b==0)
        {
            ans=i;
            break; 
        }
    }
    return ans;
}
//最大公约数
int max_yue(int a, int b)
{
    int m=min(a,b);
    int ans;
    for(int i=m;i>=1;i--)
    {
        if(a%i==0 and b%i==0)
        {
            ans=i;
            break;
        }
    }
    return ans;
}

void yuefen(int a,int b)
{
    int aa=abs(a);//分子
    int bb=abs(b);//分母
    int temp=max_yue(aa,bb);//最大公约数
    if(a==0) printf("0");
    else if(temp==bb) printf("%d",a/b);
    else if((a^b)<0) printf("%d %d",-aa/temp,bb/temp);
    else printf("%d %d",aa/temp,bb/temp);
    //!!!!重点学习，a，b两个数是否同号，用^异或去判断符号位，（a^b）<0则为异号
    //用a*b,容易爆掉，溢出
    
}

int main()
{
    int a1,b1;
    int a2,b2;
    scanf("%d %d %d %d",&a1,&b1,&a2,&b2);
    int b3=min_bei(abs(b1),abs(b2));
    int aa1,aa2;

    if(a1*b1<0) aa1=-abs(a1)*b3/abs(b1);
    else aa1=abs(a1)*b3/abs(b1);

    if(a2*b2<0) aa2=-abs(a2)*b3/abs(b2);
    else aa2=abs(a2)*b3/abs(b2);
   
    //printf("%d %d %d\n",aa1,aa2,b3);
    yuefen(aa1+aa2,b3);
    
}