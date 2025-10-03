#include<iostream>
#include<vector>
using namespace std;


int main(){

    int v = 3; // vertex
    vector<vector<int>> adj(v,vector<int>(v,0));

    // directed graph
    adj[0][1] = 1;
    adj[1][2] = 1;
    adj[2][0] = 1;

    // print
    cout<<"Adjacency Matrix:"<<endl;
    for(int i = 0; i<v; i++){
        for(int j = 0; j<v; j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }


}
