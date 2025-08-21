#include<iostream>
#include<stack>
using namespace std;

int main(){
     string str;
     cout<<"Enter Str:";
     cin >> str;


     stack<char> s;

     for(int i = 0; i<s.size(); i++){
          s.push(str[i]);
     }
     string ans = "";
     while(!s.empty()){
          ans.push_back(s.top());
          s.pop();
     }

     cout<<"Reverse string:"<<ans;

     


     

}