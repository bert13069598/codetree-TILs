#include <iostream>

using namespace std;

int N;

int main() {
    cin >> N;
    if (N<=2){
        cout<<1;
        return 0;
    }
    int dp[3] = {1,1,2};
    for(int i=2;i<N;i++){
        dp[i%3]=dp[(i-1)%3]+dp[(i-2)%3];
    }
    cout<<dp[(N-1)%3];

    return 0;
}
