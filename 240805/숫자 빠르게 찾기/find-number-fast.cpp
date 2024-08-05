#include <iostream>
using namespace std;

int main() {
    int n,m,y;
    cin>>n>>m;
    int x[n];
    for(int i=0;i<n;i++)
        cin>>x[i];
    for(int i=0;i<m;i++){
        cin>>y;
        int left=0;
        int right=n-1;
        int idx=-1;
        while(left<=right){
            int mid = (left + right) / 2;
            if(x[mid]==y){
                idx=mid;
                break;
            }
            if (x[mid] > y)
                right=mid-1;
            else
                left=mid+1;
        }
        if(idx==-1)
            cout<<idx<<"\n";
        else
            cout<<idx+1<<"\n";
    }
    return 0;
}