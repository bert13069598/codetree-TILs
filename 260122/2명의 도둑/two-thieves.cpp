#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int n, m, c;
int weight[10*10];
int thief1[5]{};
int thief2[5]{};

int dfs(int now, int thief[5]){
    if(now==m){
        int w=0;
        for(int i=0;i<m;i++)
            w+=thief[i];
        if(w>c)
            return 0;
        int value=0;
        for(int i=0;i<m;i++)
            value+=pow(thief[i],2);
        return value;
    }
    int answer=0;
    int tmp=thief[now];
    thief[now]=0;
    answer=max(answer,dfs(now+1,thief));
    thief[now]=tmp;
    answer=max(answer,dfs(now+1,thief));
    return answer;
}

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
        
        int value1=dfs(0,thief1);
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

            int value2=dfs(0,thief2);
            answer=max(answer,value1+value2);
        }
    }

    cout<<answer;

    return 0;
}

