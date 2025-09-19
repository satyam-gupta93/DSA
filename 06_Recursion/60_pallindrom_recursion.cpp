#include<iostream>
using namespace std;

bool pallindrom(string &str,int s, int e){

    if(s>e){
        return true;
    }
    if(str[s]!=str[e]){
        return 0;
    }else{
        return pallindrom(str,s+1,e-1);
    }
    
   
    
}

int main(){

    string name = "radar";

    bool ans = pallindrom(name,0,name.length()-1);

    cout<<"Ans:"<<ans;



}