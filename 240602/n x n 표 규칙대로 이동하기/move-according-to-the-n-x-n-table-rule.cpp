#include <iostream>
#include <vector>

using namespace std;
int answer = 0;
int ops[3] = {0, 1, 2};

void dfs(int n, int now, int op, int sum, vector<int> &map, vector<bool> &visit) {
    cout << sum << " " << op << "\n";
    for (int i = 0; i < n * n; i++) {
        cout << visit[i] << " ";
        if (i % n == n - 1)
            cout << "\n";
    }
    cout << "\n";
    if (n * n - 1 == now) {
        if (answer < sum)
            answer = sum;
        return;
    }
    for (auto dxy: {1, n}) {
        int next = now + dxy;
        if (next >= n * n)
            continue;
        if (dxy == 1 && now / n != next / n)
            continue;
        if (!visit[next]) {
            visit[next] = true;
            if (map[next] == ops[op])
                dfs(n, next, (op + 1) % 3, sum + 1, map, visit);
            else
                dfs(n, next, op, sum, map, visit);
            visit[next] = false;
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> map(n * n);
    for (int i = 0; i < n * n; i++)
        cin >> map[i];
    vector<bool> visit(n * n, false);
    visit[0] = true;
    int sum = 0, op = 0;
    if (map[0] == ops[op]) {
        sum++;
        op++;
    }
    dfs(n, 0, op, sum, map, visit);
    cout << answer;
    return 0;
}