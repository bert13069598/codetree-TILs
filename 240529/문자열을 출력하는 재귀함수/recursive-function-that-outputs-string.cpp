#include <iostream>
using namespace std;
void dfs(int d,int n){
    if(d==n)
        return;
    cout << "Coding is my favorite hobby!\n";
    dfs(d+1,n);
}
int main() {
    int n;
    cin >>n;
    dfs(0,n);
    return 0;
}