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
    for(int i=0;i<n-2;i++){
        m[arr[i]]--;
        for(int j=i+1;j<n-1;j++){
            m[arr[j]]--;
            // cout << arr[i] << " " << arr[j] << " " << k-arr[i]-arr[j] << " " << m[k-arr[i]-arr[j]]<< "\n";
            answer+=m[k-arr[i]-arr[j]];
        }
        for(int j=i+1;j<n-1;j++)
            m[arr[j]]++;
    }
    cout<<answer;
    return 0;
}