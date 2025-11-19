#include <iostream>

using namespace std;

int n;
int blocks[100];
int temp[100];
int s1, e1;
int s2, e2;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> blocks[i];
    }
    cin >> s1 >> e1;
    cin >> s2 >> e2;
    s1--;
    e1--;
    s2--;
    e2--;

    int j=0;
    for(int i=0;i<n;i++){
        if(i<s1 || i>e1){
            temp[j]=blocks[i];
            j++;
        }
    }
    for(int i=0;i<n-(e1-s1+1);i++)
        blocks[i]=temp[i];
    
    j=0;
    for(int i=0;i<n-(e1-s1+1);i++){
        if(i<s2 || i>e2){
            temp[j]=blocks[i];
            j++;
        }
    }
    for(int i=0;i<n-(e1-s1+1);i++)
        blocks[i]=temp[i];

    j=n-(e1-s1+1)-(e2-s2+1);
    cout << j << "\n";
    for(int i=0;i<j;i++)
        cout <<blocks[i] << "\n";

    return 0;
}
