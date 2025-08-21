#include<iostream>
using namespace std;

void reverse(string &str,int s, int e){

    if(s>e){
        return;
    }
    swap(str[s],str[e]);
    reverse(str,s+1,e-1);
    
}

int main(){

    string name = "Satyam";

    cout<<"Before:"<<name<<endl;
    reverse(name,0,name.length()-1);

    cout<<"After:"<<name;



}