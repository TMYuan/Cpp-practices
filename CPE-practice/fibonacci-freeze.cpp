#include <iostream>

using namespace std;

int f[5001][3000] = {0};
int main(){
    f[0][0] = 0;
    f[1][0] = f[2][0] = 1;
    for(int i=3; i<=5000; ++i){
        for(int j=0; j<3000; ++j){
            f[i][j] += f[i-1][j] + f[i-2][j];
            if(f[i][j] >= 10){
                f[i][j] -= 10;
                f[i][j+1]++; 
            }
        }
    }
    int n;
    while(cin>>n){
        cout<<"The Fibonacci number for "<<n<<" is ";
        if(n==0) cout<<"0"<<endl;
        int p = 2999;
        while(f[n][p] == 0){
            p--;
        }
        for(p; p>=0; p--){
            cout<<f[n][p];
        }
        cout<<endl;
    }
    return 0;
}

// #include <stdio.h>
// int Fib[5001][3000]={0};
// int main()
// {
//     Fib[0][0] = 0, Fib[1][0] = Fib[2][0] = 1;
//     for(int i = 3; i <= 5000; i++){
//         for(int j = 0; j < 3000; j++){
//             Fib[i][j] += Fib[i-1][j]+Fib[i-2][j];
//             if(Fib[i][j] >= 10){
//                 Fib[i][j] -= 10;
//                 Fib[i][j+1]++;
//             }
//         }
//     }
//     int n;
//     while(scanf("%d", &n) == 1){
//         printf("The Fibonacci number for %d is ", n);
//         if(n == 0)  printf("0");
//         int p = 2999;
//         while(Fib[n][p] == 0)   p--;
//         for(p; p >= 0; p--)
//             printf("%d", Fib[n][p]);
//         puts("");
//     }
//     return 0;
// }