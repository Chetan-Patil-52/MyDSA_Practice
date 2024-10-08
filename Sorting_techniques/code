// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

void select(int arr[],int n){
    for(int i=0;i<=n-2;i++){
        int min = i;
        for(int j=i;j<=n-1;j++){
            if(arr[j]<arr[min]){
                min = j;
            }
        }
        // swap()
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

void buble(int arr[],int n){
    for(int i =n-1;i>=0;i--){
        int didswap = 0;
        for(int j = 0;j<=i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                didswap = 1;
            }
        }
        if(didswap==0){
            break;
        }
        cout << "runs\n";
    }
}

void insertion(int arr[],int n){
    for(int i=0;i<=n-1;i++){
        int j = i;
        while(j>0 && arr[j-1]>arr[j]){
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            
            j--;
        }
    }
}

int main() {
    // Write C++ code here
    int arr[]={13,6,14};
    int n = sizeof(arr)/sizeof(arr[0]);
    // select(arr,n);
    // buble(arr,n);
    insertion(arr,n);
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    return 0;
}
