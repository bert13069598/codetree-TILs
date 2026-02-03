#include <iostream>

using namespace std;

int n;
long long num[1000]={2,7};

int main() {
    cin >> n;
    n--;
    if(n<2){
        cout<<num[n];
        return 0;
    }

    for(int i=2;i<=n;i++){
        long long next=2;
        for(int j=0;j<i;j++){
            if(j==i-2)
                next+=3*num[j];
            else
                next+=2*num[j];
        }
        num[i]=next%1000000007;
    }

    cout<<num[n];

    return 0;
}
