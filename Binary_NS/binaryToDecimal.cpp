#include<bits/stdc++.h>
using namespace std;

int binaryToDecimal(int num){
    int ans=0,pow=1;
    while(num>0){
        int rem = num % 10; // MOD for 100 = 0;
        num /= 10;
        ans += (pow*rem);
        pow *= 2;
    }
    return ans;
}

int main(){
    int num = 1010;
    cout << binaryToDecimal(num) << endl;
}
