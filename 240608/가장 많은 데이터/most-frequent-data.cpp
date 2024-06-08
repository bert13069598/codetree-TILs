#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
    int n;
    cin>>n;
    string s[n];
    unordered_map<string,int> m;
    for(int i=0;i<n;i++){
        cin>>s[i];
        m[s[i]]++;
    }
    int answer=0;
    for(auto item:s)
        answer=max(answer,m[item]);
    cout<<answer;
    return 0;
}