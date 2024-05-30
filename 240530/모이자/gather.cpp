#include <iostream>
#include <queue>
using namespace std;
int main() {
    int n;
    cin>>n;
    int num[n];
    for(int i=0;i<n;i++)
        cin>>num[i];
    priority_queue<int> pq;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=0;j<n;j++){
            sum+=abs(num[j]*abs(j-i));
        }
        pq.push(-sum);
    }
    cout << -pq.top();   

    return 0;
}