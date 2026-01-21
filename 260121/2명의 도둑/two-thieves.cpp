#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int n, m, c;
int weight[10*10];
int thief1[5]{};
int thief2[5]{};

int main() {
    cin >> n >> m >> c;

    for (int i = 0; i < n*n; i++) 
        cin >> weight[i];
    
    int answer=0;
    for(int i=0;i<n*n;i++){
        if(i%n>n-m)
            continue;
        for(int j=0;j<m;j++){
            // cout<<i+j<<" ";
            // thief1[j]=i+j;
            thief1[j]=weight[i+j];
        }
        // cout<<"\n";
        
        int w=0,value1=0;
        sort(thief1,thief1+m,greater<int>());
        for(int j=0;j<m;j++){
            if(w+thief1[j]>c)
                continue;
            w+=thief1[j];
            value1+=pow(thief1[j],2);
        }
        // for(int j=0;j<m;j++)
        //     cout<<thief1[j]<<" ";
        // cout<<value1<<" "<<"\n";

        for(int j=i+m;j<n*n;j++){
            if(j%n>n-m)
                continue;
            // cout<<" ";
            for(int k=0;k<m;k++){
                // cout<<j+k<<" ";
                // thief2[k]=j+k;
                thief2[k]=weight[j+k];
            }
            // cout<<"\n";

            w=0;
            int value2=0;
            sort(thief2,thief2+m,greater<int>());
            for(int k=0;k<m;k++){
                if(w+thief2[k]>c)
                    continue;
                w+=thief2[k];
                value2+=pow(thief2[k],2);
            }
            answer=max(answer,value1+value2);
        }
    }

    cout<<answer;

    return 0;
}
