#include <bits/stdc++.h>
using namespace std;

int longestBitonicSequence(int n, vector<int> &nums) {

        vector<int> dp1(n,1);
        vector<int> dp2(n,1);
        
       
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<i; j++){
                if( nums[i] > nums[j] && dp1[i] < 1 + dp1[j] ){
                    dp1[i] = 1 + dp1[j];
                }
            }
           
        }
        
        for(int i = n -1; i>=0; i--){
            for(int j = n - 1; j>i; j--){
                if( nums[i] > nums[j] && dp2[i] < 1 + dp2[j] ){
                    dp2[i] = 1 + dp2[j];
                }
            }
          
        }
        
        
        int maxi = 0;
        
        for(int i = 0; i<n;i++){
            if(dp1[i] > 1 && dp2[i]>1){
                maxi = max(maxi,dp1[i] + dp2[i] - 1);
            }
            
        }
        
        return maxi;
}

int main() {

    vector<int> nums = {1 ,2, 5, 3 ,2};
    int n = nums.size();
    int ans = longestBitonicSequence(n,nums);
    cout << "Length of Longest Biotonic Sequence:"<<ans << endl;

    

    return 0;
}
