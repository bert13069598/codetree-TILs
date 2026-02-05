#include <iostream>

using namespace std;

int n;
int arr[1000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int i=0;
    int jump=0;
    for(;i<n-1;i++){
        if(!arr[i+1]){
            int j=0;
            while(j<arr[i]){
                if(arr[i+1+j])
                    break;
                j++;
            }
            if(!arr[i+1+j]){
                break;
            }else{
                cout<<"jump "<<j<<"\n";
                i+=j;
                jump+=j;
            }
        }
    }
    cout<<i<<" "<<jump<<"\n";
    cout<<i-jump;

    return 0;
}
