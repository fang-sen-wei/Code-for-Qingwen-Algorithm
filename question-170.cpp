//方程求根
#include<cstdio>
#include<cmath>
const double eps=1e-5;

double f(double a)
{
    double l,r,mid;
    l=-10;
    r=10;
    while((r-l)>eps)
    {
        mid=(l+r)/2;
        double temp=pow(mid,3)+pow(mid,2)+mid;
        if(temp>a)
        {
            r=mid;
        }
        else
        {
            l=mid;
        }
    }
    return mid;
}

int main()
{
    double a;
    scanf("%lf",&a);
    printf("%.2f",f(a));
}