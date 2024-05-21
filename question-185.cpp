//01对
#include<cstdio>
#include<string>
#include<iostream>
using namespace std;

int main()
{   //解锁cin和cout
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    int list[n]={0};
    int sum=0;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;//输入0或1
        //每次遇到0就在前面一个数的基础上+1
        if(i>0)
        {
            list[i]=list[i-1];
        }
        if(a==0)
        {
            list[i]++;
        }
        else if(a==1)
        {
            sum+=list[i];
        }
    }
    printf("%d",sum);

}