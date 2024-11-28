#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n,m;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    cin>>m;
    vector<int> b(m);
    for(int i=0;i<m;i++)
        cin>>b[i];
    sort(b.begin(),b.end());
    vector<int> answer;
    for(int i=0;i<n-m+1;i++){
        vector<int> beauty(m);
        for(int j=0;j<m;j++)
            beauty[j]=a[i+j];
        sort(beauty.begin(),beauty.end());
        int gap=beauty[0]-b[0];

        bool isbeauty=true;
        for(int j=0;j<m;j++)
            if(beauty[j]-gap != b[j])
                isbeauty=false;
        if(isbeauty)
            answer.push_back(i+1);
    }
    cout<<answer.size()<<"\n";
    for(int i=0;i<answer.size();i++)
        cout<<answer[i]<<"\n";
    return 0;
}
