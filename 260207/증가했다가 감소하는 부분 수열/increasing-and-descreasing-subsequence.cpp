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
    // up max, down max, index
    int um=0,dm=0,ui,di;
    for(int i=0;i<n;i++){
        if(u[i]>um){
            ui=i;
            um=u[i];
        }
        if(d[i]>dm){
            di=i;
            dm=d[i];
        }
    }
    // for(int i=0;i<n;i++)
    //     cout<<u[i]<<" ";
    // cout<<"\n";
    // for(int i=0;i<n;i++)
    //     cout<<d[i]<<" ";
    // cout<<"\n";

    int answer=0;
    if(um==dm){
        // when second down is more long
        dm=0;
        // de:end of down
        int de;
        for(int i=ui+1;i<n;i++){
            if(d[i]>dm){
                de=i;
                dm=d[i];
            }
        }
        // ds:start of down
        int ds=de;
        while(ds>=0){
            if(d[ds]==0)
                break;
            ds--;
        }
        if(ui>=ds)
            answer=um+1+dm+1-1;
        else
            answer=um+1+dm+1; 
        
        // when second up is more long
        // ds:start of down
        ds=di;
        while(ds>=0){
            if(d[ds]==0)
                break;
            ds--;
        }
        // ue:end of up
        um=0;
        int ue=0;
        for(int i=0;i<ds;i++){
            if(u[i]>um){
                ue=i;
                um=u[i];
            }
        }
        if(ue>=ds)
            answer=max(answer,um+1+dm+1-1);
        else
            answer=max(answer,um+1+dm+1);
    }else if(um>dm){
        dm=0;
        // de:end of down
        int de;
        for(int i=ui+1;i<n;i++){
            if(d[i]>dm){
                de=i;
                dm=d[i];
            }
        }
        // ds:start of down
        int ds=de;
        while(ds>=0){
            if(d[ds]==0)
                break;
            ds--;
        }
        if(ui>=ds)
            answer=um+1+dm+1-1;
        else
            answer=um+1+dm+1;
    }else if(um<dm){
        // ds:start of down
        int ds=di;
        while(ds>=0){
            if(d[ds]==0)
                break;
            ds--;
        }
        // ue:end of up
        um=0;
        int ue=0;
        for(int i=0;i<ds;i++){
            if(u[i]>um){
                ue=i;
                um=u[i];
            }
        }
        if(ue>=ds)
            answer=um+1+dm+1-1;
        else
            answer=um+1+dm+1;
    }
    cout<<answer;
    return 0;
}
