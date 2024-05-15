//最大组合整数
#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
int main()
{
    int list[10];
    for(int i=0;i<10;i++)
    {
        scanf("%d",&list[i]);
    }
    string res="";
    for(int i=9;i>=0;i--)//从大到小选
    {
        if(list[i])
        {
            for(int j=0;j<list[i];j++)
            {
                res.push_back(i+'0');
            }
        }
    }
    if(res[0]!='0') cout<<res;
    else cout<<0;
    
    

}