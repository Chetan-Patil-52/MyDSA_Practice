// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int decimalToBinary(int Decimal){
    int ans=0,pow=1;
    
    while(Decimal>0){
        int rem = Decimal % 2;
        Decimal /=2;
        ans += (rem*pow);
        pow *=10;
    }
    return ans;
}

int main() {
    // Write C++ code here
    // std::cout << "Try programiz.pro";
    int num = 10;
    // cout << decimalToBinary(num) << endl;
    for(int i=1;i<=10;i++){
        cout << decimalToBinary(i) << endl;
    }
    return 0;
}
