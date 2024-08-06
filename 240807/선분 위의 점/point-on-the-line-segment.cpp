#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int bs(vector<long> &x,long y,int left,int right, bool a){
    while(left<=right){
        int mid=(left+right)/2;
        if(y==x[mid]){
            if (a)
                mid++;
            return mid;
        }else if(x[mid]>y)
            right=mid-1;
        else
            left=mid+1;
    }
    if(x[right]<y)
        return right+1;
    else
        return left;
}
int main() {
    int n,m;
    long p,q;
    cin>>n>>m;
    vector<long> x(n);
    for(int i=0;i<n;i++)
        cin>>x[i];
    sort(x.begin(),x.end());
    for(int i=0;i<m;i++){
        cin>>p>>q;
        int left=0;
        int right=n-1;
        cout<<bs(x,q,left,right,1)-bs(x,p,left,right,0)<<"\n";
    }
    return 0;
}