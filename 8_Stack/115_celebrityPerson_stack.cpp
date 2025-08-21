#include<iostream>
#include<vector>
#include<stack>
using namespace std;

bool know(vector<vector<int>>& mat,int a,int b){
    if(mat[a][b]==1){
        return true;
    }else{
        return false;
    }
}

int findCelebrity(vector<vector<int>>& mat){

    int n = mat.size();
    stack<int> s;

    for(int i = 0; i<n; i++){
        s.push(i);
    }

    while(s.size()>1){

        int a = s.top();
        s.pop();

        int b = s.top();
        s.pop();

        if(know(mat,a,b)){
            s.push(b);
        }else{
            s.push(a);
        }
    }
    int candi = s.top();

    // rowcheck
    for(int i = 0; i<n; i++){
        if( i!=candi && mat[candi][i] == 1){
            return -1;
        }
    }

    for(int i = 0; i<n; i++){
        if(i!=candi && mat[i][candi] == 0){
            return -1;
        }
    }

    return candi;
}

int main() {
    // Example matrix:
    // Person 0 knows 1 and 2
    // Person 1 knows 2
    // Person 2 knows no one (candidate)
    vector<vector<int>> mat = {
        {0, 1, 1},
        {0, 0, 1},
        {0, 0, 0}
    };

    int celeb = findCelebrity(mat);
    if (celeb != -1) {
        cout << "Celebrity found at index: " << celeb << endl;
    } else {
        cout << "No celebrity found." << endl;
    }

    return 0;
}
