#include <iostream>

using namespace std;

int n;
int arr[100];
bool dp[100001];

int main() {
    cin >> n;
    int sum=0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum+=arr[i];
    }
    if(sum%2){
        cout<<"No";
        return 0;
    }
    int groupa=sum/2;
    dp[0]=true;
    for(int i=0;i<n;i++){
        for(int j=groupa;j>=0;j--){
            if(j-arr[i]>=0 && dp[j-arr[i]]){
                dp[j]=true;
            }
        }
    }
    cout<<(dp[groupa]?"Yes":"No");

    return 0;
}
