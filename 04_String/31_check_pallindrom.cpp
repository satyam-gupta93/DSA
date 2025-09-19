#include<iostream>
using namespace std;

int getLength(char name[]){
    int count = 0;

    for(int i = 0; name[i] != '\0'; i++){
        count++;
    }

    

    return count;
}

bool checkPallindrom(char name[]){

    int length = getLength(name);

    int s = 0;
    int e = length - 1;

    
    while(s<=e){
        if(name[s] != name[e]){
            return false;
            break;
        }
        s++;
        e--;
    }

    return true;
}

int main(){
 
    char name[20];

    cout<<"Enter name:";
    cin>>name;
    cout<<name<<endl;
    if(checkPallindrom(name)){
        cout<<"Name is Pallindrom..";
    }else{
        cout<<"Name is not Pallindrom..";
    }

}