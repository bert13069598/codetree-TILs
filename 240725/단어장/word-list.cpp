#include <iostream>
#include <map>
using namespace std;

int main() {
    int n;
    string s;
    cin>>n;
    map<string,int> m;
    for(int i=0;i<n;i++){
        cin>>s;
        m[s]++;
    }
    for(auto it=m.begin();it!=m.end();++it)
        cout<<it->first<<" "<<it->second<<"\n";

    return 0;
}