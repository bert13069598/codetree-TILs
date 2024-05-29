#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int main() {
    vector<double> num(3);
    for(int i=0;i<3;i++){
        cin >> num[i];
    }
    sort(num.begin(),num.end());
    num[0]=int(num[0]);
    num[1]=round(num[1]);
    num[2]=int(num[2])+1;
    cout << num[2] <<" " <<num[0]<<" "<<num[1];
    return 0;
}