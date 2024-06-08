#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
    int n;
    unordered_map<int,int> m;
    for(int i=0;i<n;i++){
        string s;
        int k,v;
        cin>>s;
        if(s=="add"){
            cin>>k>>v;
            m[k]=v;
        }
        else if(s=="find"){
            cin>>k;
            if(m.find(k)!=m.end())
                cout<<m[k]<<"\n";
            else
                cout<<"None";
        }else if(s=="remove"){
            cin>>k;            
            m.erase(k);
        }
    }
    return 0;
}