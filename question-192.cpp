//西西弗斯串
#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
int ans=0;
int digui(string str)
{
    if(str=="123") return 0;
    else
    {
        int a=0,b=0;//奇数个数和偶数个数
        int c=str.size();//总位数
        for(int i=0;i<c;i++)
        {
            if((str[i]-'0') % 2) b++;
            else a++;
        }
        string temp=to_string(a)+to_string(b)+to_string(c);
        //拼接成新的字符串
        return 1+digui(temp);//次数+1
    }
}

int main()
{
    string str;
    cin>>str;
    printf("%d",digui(str));
}