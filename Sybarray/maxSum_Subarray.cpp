#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 7;
    int arr[7] = {3,-4,5,4,-1,7,-8};
    
    int max_sum = INT_MIN;
    
    for(int st=0;st<n;st++){
        int currSum = 0;
        for(int end=st;end<n;end++){
            currSum += arr[end];
            max_sum = max(max_sum,currSum);
        }
    }
        cout << "Maximum Subarray sum: " << max_sum << endl;
        return 0;
}
