#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a,int b){
    if(stoi(to_string(a)+to_string(b))>stoi(to_string(b)+to_string(a)))
        return true;
    else
        return false;
}

int main() {
    int n,x;
    cin>>n;
    vector<int> num;
    for(int i=0;i<n;i++){
        cin>>x;
        num.push_back(x);
    }
    sort(num.begin(),num.end(),cmp);
    string answer="";
    for(int i=0;i<n;i++){
        answer+=to_string(num[i]);
    }
    cout<<answer;
    return 0;
}