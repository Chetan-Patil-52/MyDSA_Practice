#include <iostream>

int get_treasure(int n) {
    // Write your logic here.
    if(n==1) return 1;
    if(n==2) return 2;

    int dp[n+1];
    dp[1] = 1;
    dp[2] = 2;
    for(int i=3;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int main() {
    int n;
    std::cin >> n;
    
    // Call user logic function and print the output
    int result = get_treasure(n);
    std::cout << result << std::endl;
    
    return 0;
}
