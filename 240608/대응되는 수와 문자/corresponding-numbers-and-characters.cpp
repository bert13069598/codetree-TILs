#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
    int n,m;
    cin>>n>>m;
    unordered_map<string,int> m1;
    unordered_map<int,string> m2;
    string s;
    for(int i=1;i<=n;i++){
        cin>>s;
        m1[s]=i;
        m2[i]=s;
    }
    for(int i=0;i<m;i++){
        cin>>s;
        if(isdigit(s[0]))
            cout<<m2[stoi(s)]<<"\n";
        else
            cout<<m1[s]<<"\n";
    }

    return 0;
}