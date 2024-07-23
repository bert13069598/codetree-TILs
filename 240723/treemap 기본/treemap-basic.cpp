#include <iostream>
#include <map>
using namespace std;

int main() {
    int n,k,v;
    string cmd;
    cin>>n;
    map<int,int> m;
    for(int i=0;i<n;i++){
        cin>>cmd;
        if(cmd=="add"){
            cin>>k>>v;
            m[k]=v;
        }else if(cmd=="remove"){
            cin>>k;
            m.erase(k);
        }else if(cmd=="find"){
            cin>>k;
            if (m.find(k)==m.end())
                cout<<"None\n";
            else
                cout<<m[k]<<"\n";
        }else if(cmd=="print_list"){
            if(m.empty())
                cout<<"None\n";
            else{
                for(auto it=m.begin();it!=m.end();++it)
                    cout <<it->second<<" ";
                cout <<"\n";
            }
        }
    }
    return 0;
}