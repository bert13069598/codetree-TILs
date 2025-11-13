#include <iostream>
#include <queue>

using namespace std;

int n, m;
int grid[5][5];

int cumsum(int i,int j,int h,int w,int visit[5][5],int v){
    int sum=0;
    for(int t1=i;t1<h;t1++){
        for(int t2=j;t2<w;t2++){
            visit[t1][t2]=v;
            sum+=grid[t1][t2];
        }
    }
    return sum;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int answer=-25*1e3;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i+j==n+m-2)
                continue;
            for(int h1=1;h1<=n-i;h1++){
                for(int w1=1;w1<=m-j;w1++){
                    if(i+h1==n && j+w1==m)
                        continue;
                    int visit1[5][5]{};
                    int sum1=cumsum(i,j,i+h1,j+w1,visit1,1);
                    
                    int sum2=-25*1e3;
                    for(int k=0;k<n;k++){
                        for(int l=0;l<m;l++){
                            if(k<=i && l<=j)
                                continue;
                            if(visit1[k][l]==0){
                                for(int h2=1;h2<=n-k;h2++){
                                    for(int w2=1;w2<=m-l;w2++){
                                        if((k<i && k+h2>i) || (l<j && l+w2>j))
                                            continue;
                                        int visit2[5][5]{};
                                        int sum=cumsum(k,l,k+h2,l+w2,visit2,2);
                                        sum2=max(sum2,sum);

                                        // for(int t1=0;t1<n;t1++){
                                        //     for(int t2=0;t2<m;t2++)
                                        //         cout<<visit1[t1][t2]+visit2[t1][t2]<<" ";
                                        //     cout<<"\n";
                                        // };
                                        // cout<<"\n";
                                    }
                                }
                            }
                        }
                    }
                    answer=max(answer,sum1+sum2);
                }
            }
        }
    }

    cout<<answer;

    return 0;
}

