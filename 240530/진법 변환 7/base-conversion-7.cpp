#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    double num;
    cin >> num;
    int a = int(num);
    double b = num-a;
    vector<char> bin;
    while(true){
        if(!a%2)
            bin.push_back('1');
        else
            bin.push_back('0');
        a/=2;
        if(a==1){
            bin.push_back('1');
            break;
        }
    }
    reverse(bin.begin(),bin.end());
    bin.push_back('.');
    int cnt = 4;
    while(cnt--){
        b*=2;
        if(b>1){
            bin.push_back('1');
            b--;
        }else
            bin.push_back('0');
    }
    for(auto b:bin)
        cout << b;

    return 0;
}