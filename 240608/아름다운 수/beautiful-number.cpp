#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin>>n;
    int map[n];
    int answer=0;
    for(int i=0;i<pow(4,n);i++){
        int num=i;
        for(int j=n-1;j>=0;j--){
            map[j]=num%4+1;
            num/=4;
        }
        int cnt = 0;
        bool isbeaty = true;
        for (int j = 0; j < n; j++) {
            if (!cnt) {
                cnt = map[j] - 1;
            } else {
                if (map[j - 1] != map[j]) {
                    isbeaty = false;
                    break;
                }
                cnt--;
            }
        }
        if(isbeaty&&!cnt)
            answer++;
        
        // for(int j=0;j<n;j++)
        //     cout<<map[j];
        // cout<<"\n";
    }
    cout<<answer;
    return 0;
}