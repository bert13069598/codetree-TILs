#include <iostream>
using namespace std;
int main() {
    int a,b;
    cin>>a>>b;
    if(b==1){
        for(int i=0;i<a;i++){
            for(int j=0;j<=i;j++)
                cout << "*";
            cout <<"\n";
        }
    }else if(b==2){
        for(int i=0;i<a;i++){
            for(int j=0;j<a-i;j++)
                cout << "*";
            cout <<"\n";
        }
    }else{
        for(int i=0;i<a;i++){
            for(int j=0;j<2*a-1;j++){
                if(j>=a-1-i&&j<=a-1+i)
                    cout <<"*";
                else
                    cout <<" ";
            }
            cout <<"\n";
        }
    }
    return 0;
}