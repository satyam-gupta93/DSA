#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

template<typename T>

class graph{

public:
    unordered_map<T,list<T>> adj;

    void addEdge(T u,T v,bool direction){

        // direction 0 --> undiorected
        // direction 1 --> directed

        adj[u].push_back(v);

        if(!direction){
            adj[v].push_back(u);
        }
    }

    void printList(){

        for( auto i:adj ){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<j<<",";
            }
            cout<<endl;
        }
    }

};


int main(){


    int n;
    cout<<"Enter number of of nodes:";
    cin>>n;

    int m;
    cout<<"Enter the number of edge:";
    cin>>m;
    graph<int> g;
    for(int i = 0; i<m; i++){
        int u;
        int v;
        cin>>u>>v;
        // undirected graph
        g.addEdge(u,v,0);
        
    }

    g.printList();


}