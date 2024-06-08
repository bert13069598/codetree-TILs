#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
    int n,k;
    cin>>n>>k;
    int arr[n];
    unordered_map<int,int> m;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        m[arr[i]]++;
    }
    int answer=0;
    for(auto a:arr){
        if(m[k-a]){
            m[a]--;
            answer+=m[k-a];
        }
    }
    cout<<answer;
    return 0;
}