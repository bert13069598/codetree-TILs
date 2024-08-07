#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int x[n];
    for(int i=0;i<n;i++)
        cin>>x[i];
    int answer=x[0];
    for(int i=0;i<n-1;i++){
        if(x[i]>0)
            x[i+1]+=x[i];
        answer=max(answer,x[i+1]);
    }
    cout<<answer;
    return 0;
}