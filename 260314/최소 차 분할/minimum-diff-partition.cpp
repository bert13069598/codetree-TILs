#include <iostream>

using namespace std;

int n;
int arr[100];
bool dp[100001];
int sum=0;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum+=arr[i];
    }
    dp[0]=true;
    int groupa=sum/2;
    for(int i=0;i<n;i++){
        for(int j=groupa;j>=0;j--){
            if(j-arr[i]>=0 && dp[j-arr[i]]){
                dp[j]=true;
            }
        }
    }


    int suma=0;
    for(int i=1;i<=groupa;i++)
        if(dp[i])
            suma=max(suma,i);
    int sumb=sum-suma;
    cout<<abs(suma-sumb);

    return 0;
}
