#include <iostream>

using namespace std;

const int MAX_N = 1000;

int n;
int M[MAX_N];
int u[MAX_N];
int d[MAX_N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> M[i];
    }

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(M[i]==M[j]){
                u[j]=u[i];
                d[j]=d[i];
            }
            else if(M[i]<M[j])
                u[j]=u[i]+1;
            else if(M[i]>M[j])
                d[j]=d[i]+1;
        }
    }
    // up max, down max
    // end of up, end of down
    int um=0,dm=0,ue=0,de=0;
    for(int i=0;i<n;i++){
        if(u[i]>=um){
            ue=i;
            um=u[i];
        }
        if(d[i]>=dm){
            de=i;
            dm=d[i];
        }
    }
    // when ue on the n-1
    if(um>=dm && ue==n-1){
        cout<<um+1;
        return 0;
    }
    int ds=de;
    while(ds>=0){
        if(d[ds]==0)
            break;
        ds--;
    }
    // when ds on the 0
    if(dm>um && ds==0){
        cout<<dm+1;
        return 0;
    }
    int answer=0;
    // case 1. max up -> down
    int dde=ue+1, ddm=0;
    for(int i=dde;i<n;i++){
        if(d[i]>ddm){
            dde=i;
            ddm=d[i];
        }
    }
    int dds=dde;
    while(dds>=0){
        if(d[dds]==0)
            break;
        dds--;
    }
    if(ue>=dds)
        answer=max(answer,um+1+ddm+1-1);
    else
        answer=max(answer,um+1+ddm+1);
    // case 2. up -> max down
    int uue=ds, uum=0;
    for(int i=0;i<uue;i++){
        if(u[i]>uum){
            uue=i;
            uum=d[i];
        }
    }
    if(uue>=ds)
        answer=max(answer,uum+1+dm+1-1);
    else
        answer=max(answer,uum+1+dm+1);
    
    // for(int i=0;i<n;i++)
    //     cout<<u[i]<<" ";
    // cout<<"\n";
    // for(int i=0;i<n;i++)
    //     cout<<d[i]<<" ";
    // cout<<"\n";

    cout<<answer;
    return 0;
}
