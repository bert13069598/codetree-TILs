#include <iostream>
#include <vector>

using namespace std;

void dfs(int n, vector<int> &vec){
    vec.push_back(n);
    if(n<3)
        return;
    dfs(n/3, vec);
}
int main() {
    int n;
    cin>>n;
    vector<int> vec;
    dfs(n,vec);
    for(int i=vec.size()-1;i>=0;i--)
        cout << vec[i] << " ";
    return 0;
}