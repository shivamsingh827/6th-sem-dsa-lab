#include<bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{
char a='a';
char b='b';

string s="AbBa";
int i=0;
int j=3;

while(i<=j){
    if(s[i]!=s[j] && s[i]!=s[j]+32 && s[i]+32!=s[j]){
        cout<<"No"<<endl;
        break;
    }
    i++;
    j--;
}











cout<<char(9)+char(5);

for (int i = 0; i < 100; i++)
{
    /* code */
    cout<<char(i);
}

return 0;
}