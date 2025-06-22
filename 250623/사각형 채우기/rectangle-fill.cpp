#include <iostream>

using namespace std;

int n;

int main() {
    cin >> n;

    int dp[3]={1,2,3};
    for(int i=3;i<n;i++)
        dp[i%3]=(dp[(i-1)%3]+dp[(i-2)%3])%10007;
    
    cout<<dp[(n-1)%3];

    return 0;
}
