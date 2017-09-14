#include <iostream>
#include <cmath>

using namespace std;
int main(){
    int n=0, c=0;
    long long int arr[49] = {0};
    arr[1] = 1;
    for(int i=2; i<=48; ++i){
        arr[i] = arr[i-1] + arr[i-2];
    }
    while(cin>>n){
        ++c;
        cout<<"case "<<c<<":"<<endl;
        if(n>=48){
            cout<<"overflow"<<endl;
        }
        else if(arr[n] > pow(2, 32) - 1){
            cout<<"overflow"<<endl;
        }
        else{
            cout<<arr[n]<<endl;
        }
        cout<<endl;
    }
}