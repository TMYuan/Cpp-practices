#include <iostream>
#include <algorithm>

using namespace std;
int main(){
    int count[26] = {0}, total=0;
    char c;
    while(cin>>c){
        if(c >= 'a' && c <= 'z'){
            ++count[c - 'a'];
            ++total;
        }
        else if(c >= 'A' && c <= 'Z'){
            ++count[c - 'A'];
            ++total;
        }
        // if(c == '/'){
        //     break;
        // }
    }
    for(int i=total; i>0; --i){
        for(int j=0; j<26; ++j){
            if(count[j] == i){
                cout<<char('A' + j)<<" "<<count[j]<<endl;
            }
        }
    }
}