#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int k,n;
    cin>>k>>n;
    int map[n];
    for(int i=0;i<pow(k,n);i++){
        int num=i;
        for(int j=n-1;j>=0;j--){
            map[j]=num%k+1;
            num/=k;
        }
        for(int j=0;j<n;j++)
            cout<<map[j]<<" ";
        cout<<"\n";
    }
    return 0;
}