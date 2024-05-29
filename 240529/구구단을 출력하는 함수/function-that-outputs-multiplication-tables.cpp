#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
    vector<int> num(3);
    cin >>num[0]>>num[1]>>num[2];
    sort(num.begin(),num.end());
    for(int i=num[0];i<=num[2];i++){
        if(i==num[1])
            continue;
        for(int j=1;j<10;j++){
            cout << i<<" * "<<j<<" = "<<i*j<<"\n";
        }
    }


    return 0;
}