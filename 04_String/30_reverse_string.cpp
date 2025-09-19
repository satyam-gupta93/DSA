#include<iostream>
using namespace std;

int getLength(char name[]){
    int count = 0;

    for(int i = 0; name[i] != '\0'; i++){
        count++;
    }

    return count;
}

void reverseString(char ch[]){

    int length = getLength(ch);
    int s = 0;
    int e = length - 1;
    while(s<=e){
        swap(ch[s],ch[e]);
        s++;
        e--;
    }
}
int main(){
 
    char name[20];

    cout<<"Enter name:";
    cin>>name;
    cout<<name<<endl;
    reverseString(name);
    cout<<"Reverse Name:"<<name;
    

}