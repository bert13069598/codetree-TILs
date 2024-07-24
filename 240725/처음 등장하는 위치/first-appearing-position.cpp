#include <iostream>
#include <map>
using namespace std;

int main() {
    int n,x;
    cin>>n;
    map<int,int> m;
    for(int i=0;i<n;i++){
        cin>>x;
        if(m.find(x)==m.end())
            m[x]=i+1;
    }
    for(auto it=m.begin();it!=m.end();++it)
        cout<<it->first<<" "<<it->second<<"\n";
    return 0;
}