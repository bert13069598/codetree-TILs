#include <iostream>
using namespace std;

void dfs(int n, int tmp){
    if(n<tmp)
        return;
    cout << tmp << " ";
    dfs(n, tmp+2);
}
int main() {
    int n;
    cin>>n;
    if(n%2)
        dfs(n,1);
    else
        dfs(n,2);
    return 0;
}