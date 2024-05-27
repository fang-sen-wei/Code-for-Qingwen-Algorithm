//1元2次方程
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    double delta=b*b-4*a*c;
    if(delta<0) printf("No Solution");
    else if(delta==0)
    {
        double ans=(-b)/2.0/a;
        printf("%.2f",ans);
    }
    else//简单的求根公式
    {
        double a1=(-b-sqrt(delta))/2.0/a;
        double a2=(-b+sqrt(delta))/2.0/a;
        printf("%.2f %.2f",a1,a2);
    }
}
