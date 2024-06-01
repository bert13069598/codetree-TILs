#include <iostream>
#include <vector>

using namespace std;
int answer = 0;
int ops[3] = {0, 1, 2};

void dfs(int n, int now, int op, vector<int> &map, vector<int> &visit) {
    for (int i = 0; i < n * n; i++) {
        cout << visit[i] << " ";
        if (i % n == n - 1)
            cout << "\n";
    }
    cout << "\n";

    if (n * n - 1 == now) {
        if (answer < visit[now])
            answer = visit[now];
        return;
    }
    for (auto dxy: {1, n}) {
        int next = now + dxy;
        if (next >= n * n)
            continue;
        if (dxy == 1 && now / n != next / n)
            continue;
        if (visit[next] <= visit[now]) {
            if (map[next] == ops[op]) {
                visit[next] = visit[now] + 1;
                dfs(n, next, (op + 1) % 3, map, visit);
            } else {
                visit[next] = visit[now];
                dfs(n, next, op, map, visit);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> map(n * n);
    for (int i = 0; i < n * n; i++)
        cin >> map[i];
    vector<int> visit(n * n, false);
    int op = 0;
    if (map[0] == ops[op]) {
        visit[0]++;
        op++;
    }
    dfs(n, 0, op, map, visit);
    cout << answer;
    return 0;
}