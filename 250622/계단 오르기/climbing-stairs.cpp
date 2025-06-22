#include <iostream>

using namespace std;

int n;

int dfs(int k){
    if(k==0||k==1)
        return 1;
    return k*dfs(k-1);
}

int main() {
    cin >> n;
    int answer=0;
    for(int x=0;x<=n/2;x++)
        for(int y=0;y<=n/3;y++)
            if(2*x+3*y==n)
                answer+=dfs(x+y)/dfs(x)/dfs(y);

    cout<<answer%10007;

    return 0;
}