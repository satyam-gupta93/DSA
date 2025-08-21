

// Problem Statement:

// Aapke paas n stalls (gaulein) hain jo ek number line par diye gaye hain (matlab har stall ka ek position hai). Aapko k cows ko in stalls mein is tarah se rakhna hai ki do cows ke beech ki minimum distance sabse zyada ho.

// Aapka kaam:
// Yeh find karna hai ki maximum possible minimum distance kya ho sakti hai jisme aap k cows ko rakh sakte ho.

#include <bits/stdc++.h>
using namespace std;


bool isPossible(vector<int> arr,int mid,int k){

    int cowCount = 1;
    int lastPos = arr[0];

    for(int i=0; i<arr.size(); i++){

        if( arr[i] - lastPos >= mid){
            cowCount++;
            if(cowCount == k){
                return true;
            }
            lastPos = arr[i];

        }
    }

    return false;
}

int aggressiveCows(vector<int> stalls,int k){

    int s = 0;
    int maxi = -1;
    for(int i = 0; i < stalls.size(); i++){
        if(maxi<stalls[i]){
            maxi = stalls[i];
        }
    }
    int e = maxi;
    int ans = -1;

    while(s<=e){

        int mid = s + (e-s)/2;

        if(isPossible(stalls,mid,k)){
            ans  = mid;
            s = mid + 1;
        }else{
            e = mid - 1;
        }
    }

    return ans;
}

int main(){

    vector<int> stalls = {1, 2, 8, 4, 9}; // Sample stall positions
    int k = 2; // Number of cows to place

    int result = aggressiveCows(stalls, k);
    cout << "Maximum minimum distance between cows = " << result << endl;
}