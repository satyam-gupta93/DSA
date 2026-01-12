#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmall( vector<int>& arr,int n ){

    vector<int> ans(n);

    stack<int> s;
    s.push(-1);

    for(int i = n-1; i>=0; i--){
        int curr = arr[i];

        while( s.top()!=-1 && arr[s.top()]>=curr){
            s.pop();
        }
        ans[i] = s.top();

        s.push(i);
    }

    return ans;
}

vector<int> prevSmall( vector<int>& arr,int n ){

    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for(int i = 0; i<n; i++){
         int curr = arr[i];
         while(  s.top()!=-1 && curr <= arr[s.top()]){
            s.pop();
         }
        ans[i] = s.top();

        s.push(i);



    }

     return ans;
}


int largestRectangleArea(vector<int>& heights,int m) {
    
       int n = m;
       vector<int> next(n);
       next = nextSmall(heights,n);

       vector<int> prev(n);
       prev = prevSmall(heights,n);

      int area = INT_MIN;
       for(int i = 0 ; i<n; i++){
            int l = heights[i];
            if(next[i] == -1){
                next[i] = n;
            }
            int b = next[i]-prev[i]-1;

            int newArea = l*b;

            area = max(area,newArea);

       }
       return area; 
}


    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> heights(m, 0);
        int area = 0;

        for(int i = 0; i<n; i++){
            for(int j = 0; j < m; j++){
                if (matrix[i][j] == '1') {
                    heights[j] += 1;
                } else {
                    heights[j] = 0;
                }
               
            }
            area = max(area,largestRectangleArea(heights,m));

        }
        return area;
        
        
}

int main() {

    vector<vector<char>> matrix = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };

    
    cout << "Maximum Rectangle Area = "<< maximalRectangle(matrix) << endl;

    return 0;
}
