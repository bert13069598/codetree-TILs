#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int main() {
    vector<pair<double,int>> num(3);
    for(int i=0;i<3;i++){
        cin >> num[i].first;
        num[i].second=i;
    }
    sort(num.begin(),num.end());
    num[0].first = int(num[0].first)+1;
    num[1].first = round(num[1].first);
    num[2].first = int(num[2].first);
    sort(num.begin(),num.end(), [](pair<double,int> &a,pair<double,int> &b){return a.second < b.second;});
    cout << num[0].first <<" "<< num[1].first<<" "<<num[2].first;
    return 0;
}