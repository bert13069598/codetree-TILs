#include <iostream>

using namespace std;

int n;
int M[1000];
int a[1000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> M[i];
    }

    a[0]=1;
    for(int i=0;i<n-1;i++){
        int j=i;
        int cnt=1;
        while(j>=0){
            if(M[i+1]==M[j])
                cnt=max(cnt,a[j]);
            else if(M[i+1]>M[j])
                cnt=max(cnt,a[j]+1);
            j--;
        }
        a[i+1]=cnt;        
    }
    int answer=0;
    for(int i=0;i<n;i++)
        answer=max(answer,a[i]);
    cout<<answer;

    return 0;
}
