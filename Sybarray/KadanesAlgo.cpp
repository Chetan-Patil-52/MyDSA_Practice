#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 7;
    int arr[n] = {3,-4,5,4,-1,7,-8};
    
    // Solved using Kadan's Algorithm 
    // Time complexity O(n)
    
    int max_sum = INT_MIN;
    
    int curr_sum = 0;
    for(int i = 0 ;i<n;i++){
        curr_sum += arr[i];
        max_sum = max(curr_sum,max_sum);
        
        if(curr_sum<0){
            curr_sum = 0;
        }
    }
    cout << "MAX :" << max_sum ;
    
    
    
    return 0;
}
