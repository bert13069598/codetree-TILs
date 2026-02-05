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
        if(M[i+1]>M[i]){
            int next=a[i]+1;
            int j=i;
            while(j){
                if(M[i+1]==M[j])
                    next=max(next,a[j]);
                else if(M[i+1]>M[j])
                    next=max(next,a[j]+1);
                j--;
            }
            a[i+1]=next;
        }else{
            int j=i;
            while(j){
                if(M[i+1]>=M[j])
                    break;
                j--;
            }
            if(j){
                if(M[i+1]>M[j])
                    a[i+1]=a[j]+1;
                else
                    a[i+1]=a[j];
            }else
                a[i+1]=a[i];
        }
    }
    int answer=0;
    for(int i=0;i<n;i++){
        // cout<<a[i]<<" ";
        answer=max(answer,a[i]);
    }
    cout<<answer;

    return 0;
}
