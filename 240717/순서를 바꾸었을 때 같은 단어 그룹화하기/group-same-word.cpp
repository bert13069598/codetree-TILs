#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> words(n);
    unordered_map<string, int> map;
    for(int i=0;i<n;i++){
        cin>>words[i];
        sort(words[i].begin(),words[i].end());
        map[words[i]]++;
    }
    int answer=0;
    for(auto& pair:map){
        answer=max(answer,pair.second);
    }
    cout << answer;
    return 0;
}