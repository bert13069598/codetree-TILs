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
    for(int i=0;i<n-1;i++){
        m[arr[i]]--;
        for(int j=0;j<i;j++){
            // cout << i << " " << j << " ";
            // cout << arr[i] << " " << arr[j] << " " << k-arr[i]-arr[j] << " " << m[k-arr[i]-arr[j]]<< "\n";
            if(m[k - arr[i] - arr[j]]){
                answer+=m[k-arr[i]-arr[j]];
            }
        }
    }
    cout<<answer;
    return 0;
}