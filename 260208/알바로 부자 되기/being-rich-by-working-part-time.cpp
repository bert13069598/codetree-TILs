#include <iostream>

using namespace std;

int n;
int s[1000], e[1000], p[1000];
int a[1000], b[1000];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> s[i] >> e[i] >> p[i];
    }

    for(int i=0;i<n;i++){
        b[i]=max(b[i],p[i]);
        for(int j=i+1;j<n;j++){
            if((s[i]<e[j])==(e[i]<s[j])){
                a[j]=max(a[j],a[i]+1);
                b[j]=p[j]+b[i];
            }
        }
        // for(int i=0;i<n;i++)
        //     cout<<b[i]<<" ";
        // cout<<"\n";
    }

    int answer=0;
    for(int i=0;i<n;i++)
        answer=max(answer,b[i]);
    cout<<answer;

    return 0;
}
