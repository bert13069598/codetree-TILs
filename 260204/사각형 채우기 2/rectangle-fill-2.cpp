#include <iostream>

using namespace std;

int n;
int num[3]={1,3};

int main() {
    cin >> n;
    n--;
    if(n<2){
        cout<<num[n];
        return 0;
    }
    for(int i=2;i<=n;i++)
        num[i%3]=(num[(i-1)%3]+2*num[(i-2)%3])%10007;
    cout<<num[n%3];

    return 0;
}
