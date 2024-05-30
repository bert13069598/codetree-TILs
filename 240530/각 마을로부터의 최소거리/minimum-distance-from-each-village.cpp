#include <iostream>
using namespace std;
int main() {
    int n;
    cin >>n;
    long x[n],a[n];
    for(int i=0;i<n;i++)
        cin>>x[i]>>a[i];
    int answer;
    long tmp=1e10;
    for(int i=0;i<n;i++){
        long sum=0;
        for(int j=0;j<n;j++)
            sum+=abs(x[i]-x[j])*a[j];
        if(sum<tmp){
            tmp=sum;
            answer=x[i];
        }
    }
    cout << answer;
    return 0;
}