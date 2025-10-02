#include<iostream>
#include<unordered_map>
#include<map>
using namespace std;



int main(){


    unordered_map<string,int> mp;

    //  insertion 

    // 1 ---> 
    mp.insert({"Satyam",1});
    mp.insert({"Sundaram",1});

    // 2 --->
    mp.insert(make_pair("Shivam",2));

    // 3
    mp["Satyam"] = 3; // updation


    // Seraching 
    cout<<mp["Satyam"]<<endl;
    cout<<mp.at("Shivam")<<endl;


   // cout<<mp.at("S")<<endl; // Error not found ;
    cout<<mp["S"]<<endl; // new entry create with value = 0;

    // Size
    cout<<"Size:"<<mp.size()<<endl;


    // to check presence 
    cout<<"Check:"<<mp.count("Satyam")<<endl;
    cout<<"Check:"<<mp.count("Sundaram")<<endl;


    // Delete
    mp.erase("S");
    cout<<"Size:"<<mp.size()<<endl;

    // Traversal
    for(auto i:mp){
        cout<<i.first<<"->"<<i.second<<endl;
    }

    //iterator 
    unordered_map<string,int> :: iterator it = mp.begin();
    cout<<"Iterator:-->"<<endl;
    while(it!=mp.end()){
        cout<<it->first<<"->"<<it->second<<endl;
        it++;
    }


    // if we create map -> your output on value sorted order;

    map<int,int> m;

    m.insert({1,3});
    m.insert({2,1});
    m.insert({6,5});
    m.insert({4,4});


    // orderned map
    for(auto i:m){
        cout<<i.first<<"->"<<i.second<<endl;
    }


     // if we create map -> your output on key sorted order in asecending order ; 
    cout<<"M2"<<endl;
    map<string,int> m1;

    m1.insert({"Catyam",3});
    m1.insert({"Bhivam",1});
    m1.insert({"Aundaram",5});
    m1.insert({"Ram",4});


    // orderned map
    for(auto i:m1){
        cout<<i.first<<"->"<<i.second<<endl;
    }


    // map with descending order
    map<int, string, greater<int>> m2;

    m2[1] = "One";
    m2[3] = "Three";
    m2[2] = "Two";

    for (auto &p : m2) {
        cout << p.first << " -> " << p.second << endl;

    }

    


}