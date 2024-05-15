//拼接最小数
#include<cstdio>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;

bool cmp(string a, string b)
{
    return a+b < b+a;
}

int main()
{
    //解放cin和cout的读取速度
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    string list[n];
    for(int i=0;i<n;i++)
    {
        cin>>list[i];
    }

    sort(list,list+n,cmp);//按照拼接较小的代价排序
    list[0]=to_string(stoi(list[0]));//去掉排序完第一个元素的前导0
    
    int count=0;
    for(int i=0;i<n;i++)
    {  
        if(stoi(list[i])==0) count++;
    }//看看字符串数组中有几个全0的字符串
    if(count==n) cout<<0;//专门处理全部为0的情况
    else{//正常输出
        for(int i=0;i<n;i++)
        {
            cout<<list[i];
        }
    }
    
}