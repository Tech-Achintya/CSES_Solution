#include <bits/stdc++.h>
using namespace std;

vector<int> parent;
vector<int> level;
vector<vector<int>> table;
int MAX = 20;
vector<vector<int>> child;

void build(int n) {
    table.assign(MAX, vector<int>(n + 1, 0));

    for (int i = 2; i <= n; i++) {
        table[0][i] = parent[i];
    }

    for (int i = 1; i < MAX; i++) {
        for (int j = 2; j <= n; j++) {
            int par = table[i - 1][j];

            if (par == 0) {
                table[i][j] = 0;
            } else {
                table[i][j] = table[i - 1][par];
            }
        }
    }
}

int lca(int a, int b) {
    if (level[a] > level[b]) {
        return lca(b, a);
    }

    while (level[a] != level[b]) {
        b = parent[b];
    }

    if (a == b) {
        return a;
    }

    while (a != b) {
        a = parent[a];
        b = parent[b];
    }

    return a;
}

int lcaOptimized(int a, int b) {
    if (level[a] > level[b]) {
        swap(a, b);
    }

    int k = level[b] - level[a];

    for (int i = 0; i < MAX; i++) {
        int mask = 1 << i;

        if ((k & mask) > 0) {
            b = table[i][b];
        }
    }

    if (a == b) {
        return a;
    }

    for (int i = MAX - 1; i >= 0; i--) {
        int ap = table[i][a];
        int bp = table[i][b];

        if (ap != bp) {
            a = ap;
            b = bp;
        }
    }

    return table[0][a];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    child.assign(n + 1, vector<int>());

    for (int i = 2; i <= n; i++) {
        int par;
        cin >> par;
        child[par].push_back(i);
    }

    parent.assign(n + 1, 0);
    level.assign(n + 1, 0);

    queue<int> queue;
    queue.push(1);
    level[1] = 1;

    while (!queue.empty()) {
        int node = queue.front();
        queue.pop();

        for (int adj : child[node]) {
            parent[adj] = node;
            level[adj] = level[node] + 1;
            queue.push(adj);
        }
    }

    build(n);

    vector<int> ans(q);

    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        ans[i] = lcaOptimized(u, v);
    }

    for (int x : ans) {
        cout << x << '\n';
    }

    return 0;
}