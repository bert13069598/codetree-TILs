#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n, K;
    cin >> n >> K;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = 0;
    unordered_map<int, int> mp;
    mp[a[0]]++;
    for (int j = 1; j < n - 1; j++) {
        for (int k = j + 1; k < n; k++) {
            if (mp.find(K - a[j] - a[k]) != mp.end()) 
                ans += mp[K - a[j] - a[k]];
        }
        mp[a[j]]++;
    }
    cout << ans << '\n';
}