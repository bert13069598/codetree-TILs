#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> x(n);
    for(int i=0;i<n;i++)
        cin>>x[i];
    int answer=1e8;
    do{
        int sum=0,tmp=x[0];
        for(int i=1;i<x.size();i++){
            tmp+=x[i];
            sum+=tmp;
        }
        answer=min(answer,sum);
    }while(next_permutation(x.begin(),x.end()));
    cout<<answer;
    return 0;
}