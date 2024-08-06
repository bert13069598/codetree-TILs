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
        int cnt=0;
        while(left<=right){
            int mid=(left+right)/2;
            if(x[mid]==y){
                cnt++;
                int tmp=mid+1;
                while(x[tmp++]==y)
                    cnt++;
                tmp=mid-1;
                while(x[tmp--]==y)
                    cnt++;
                break;
            }else if(x[mid]>y)
                right=mid-1;
            else
                left=mid+1;
        }
        cout<<cnt<<"\n";
    }
    return 0;
}