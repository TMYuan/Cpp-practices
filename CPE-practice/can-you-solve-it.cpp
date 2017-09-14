#include <iostream>

using namespace std;
int main(){
    int n, i;
    cin>>n;
    i = n;
    while(i--){
        int x1, y1, x2, y2, count=0;
        cin>>x1>>y1>>x2>>y2;
        while(x1 != x2 || y1 != y2){
            if(x1 == 0 && y1 == 0){
                ++y1;
            }
            else if(y1 != 0){
                --y1;
                ++x1;
            }
            else{
                y1 = x1 + 1;
                x1 = 0;
            }
            ++count;
        }
        cout<<"Case "<<n-i<<": "<<count<<endl;
    }
}