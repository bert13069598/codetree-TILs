#include <iostream>

using namespace std;

int n, m;
int a[100];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if(m==1){
        cout<<0;
        return 0;
    }

    bool running=true;
    while(running){
        // for(int i=0;i<n;i++)
        //     cout<<a[i]<<" ";
        // cout<<"\n";

        running=false;
        int num=1;
        for(int i=0;i<n-1;i++){
            if(a[i]==a[i+1])
                num++;
            else{
                if(num>=m){
                    running=true;
                    int j=num;
                    while(j--)
                        a[i-j]=0;
                }
                num=1;
            }
        }
        if(num>=m){
            running=true;
            int j=num;
            while(j--)
                a[n-j-1]=0;
        }

        int temp[n]{},k=0;
        for(int i=0;i<n;i++)
            if(a[i])
                temp[k++]=a[i];
        n=k;
        for(int i=0;i<n;i++)
            a[i]=temp[i];
    }

    cout<<n<<"\n";
    for(int i=0;i<n;i++)
        cout<<a[i]<<"\n";

    return 0;
}
