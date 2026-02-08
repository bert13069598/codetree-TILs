#include <iostream>

using namespace std;

int n;
int s[1000], e[1000], p[1000];
int a[1000];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> s[i] >> e[i] >> p[i];
    }

    int answer=0;
    for(int i=0;i<n;i++){
        int cost=p[i];
        for(int j=i+1;j<n;j++){
            if((s[i]<e[j])==(e[i]<s[j])){
                cost+=p[j];
            }
        }
        answer=max(answer,cost);
    }
    cout<<answer;

    return 0;
}
