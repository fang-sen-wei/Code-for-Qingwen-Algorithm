//简单计算器
//对中序进行加减乘除，先把中序转后序，再计算
#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<stack>
#include<map>
using namespace std;

typedef struct node
{
    double num;
    char op;
    bool isop;
    //true is op,false is num
}node;

string str;
stack<node> s;
queue<node> q;
map<char,int> mp;

void trans()
{
    node temp;
    double num;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]==' ') continue;
        //if the str[i] is num
        if(str[i]>='0' and str[i]<='9')
        {
            temp.isop=false;
            temp.num=str[i++]-'0';
            //连续的数字
            while(i<str.size() and str[i]<='9' and str[i]>='0')
            {
                temp.num = temp.num*10 + (str[i]-'0');
                i++;  
            }
            q.push(temp);
        }
        else
        {
            temp.isop=true;
            //当前操作符比栈中的操作符号小于等于，就出栈加入中缀表达式
            while(!s.empty() and mp[str[i]]<=mp[s.top().op])
            {
                q.push(s.top());
                s.pop();
            }
            temp.op=str[i];
            s.push(temp);
            i++;
        }
    }
    //数字都弄完了，栈中还剩下操作符的话
    while(!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
}

double cal()
{
    double temp1,temp2;
    node temp,cur;
    while(!q.empty())
    {
        cur=q.front();
        q.pop();
        if(cur.isop==false)
        {
            s.push(cur);
        }
        else
        {
            temp2=s.top().num;
            s.pop();
            temp1=s.top().num;
            s.pop();
            if(cur.op=='+') temp.num=temp1+temp2;
            else if(cur.op=='-') temp.num=temp1-temp2;
            else if(cur.op=='*') temp.num=temp1*temp2;
            else temp.num=temp1/temp2;
            temp.isop=false;
            s.push(temp);
        }
    }
    return s.top().num;
}


int main()
{
    mp['+']=mp['-']=1;
    mp['*']=mp['/']=2;
    getline(cin,str);
    while(!s.empty())
    {
        s.pop();
    }
    trans();
    printf("%.2f",cal());
}