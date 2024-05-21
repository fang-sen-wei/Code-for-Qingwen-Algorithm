//装水问题-1
#include<cstdio>
#include<cmath>
using namespace std;
const double pi=acos(-1);//这是需要学习的地方
const double eps=1e-10;
double R;
double f(double a)
{
    double l,r,mid;
    l=0;
    r=R;
    double s1,s2;
    double ans;
    //若是正常的l<r
    while(l<r)
    {
        mid=(l+r)/2;
        s2=pi*R*R/2;
        s1=s2-(R-mid)*sqrt(R*R-(R-mid)*(R-mid))-pi*R*R*asin((R-mid)/R)/pi;
        //数学推导所得
        if(abs((s1/s2)-a) < eps)//当目标值相差eps也是可以的
        {
            ans=mid;
            break;
        } 
        else if(s1/s2 > a) r=mid;
        else l=mid;
    }
    //调试printf("%f %f\n",s1,s2);
    return ans;
}

int main()
{
    
    double a;
    scanf("%lf %lf",&R,&a);
    printf("%.2f",f(a));
}