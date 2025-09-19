#include<iostream>
using namespace std;

int getLength(char name[]){
    // int count = 0;

    // for(int i = 0; name[i] != '\0'; i++){
    //     count++;
    // }

    
    int count  = 0;
    int i = 0;
    while(name[i] != '\0'){
        count++;
        i++;
    }

    return count;
}

int main(){
 
    char name[20];

    cout<<"Enter name:";
    cin>>name;
    cout<<name<<endl;
    cout<<"Length of name is:"<<getLength(name);

}