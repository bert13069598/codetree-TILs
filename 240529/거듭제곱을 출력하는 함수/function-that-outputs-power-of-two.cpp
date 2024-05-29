#include <iostream>
using namespace std;
int dfs(int d,int tmp,int a,int b){
    if(d==b)
        return tmp;
    return dfs(d+1,tmp*a,a,b);
}
int main() {
    int a,b;
    cin >>a>>b;
    cout << dfs(0,1,a,b);
    return 0;
}