#include <bits/stdc++.h>
using namespace std;

constexpr int LIMIT_N = 250000 + 25;
constexpr int base = (1 << 19);
vector<int> G[LIMIT_N];
int level[LIMIT_N];
int pre[LIMIT_N];
int post[LIMIT_N];
int Tree[2*base];
int czas = 0;

void dfs(int v, int p) {
    pre[v] = ++czas;
    level[v] = level[p] + 1;
    for (auto u : G[v])
        if (u != p)
            dfs(u, v);
    post[v] = ++czas;
}

void update(int a, int b, int wart) {
    a += base - 1;
    b += base + 1;
    while (a / 2 != b / 2) {
        if (a % 2 == 0) Tree[a+1] += wart;
        if (b % 2 == 1) Tree[b-1] += wart;
        a /= 2;
        b /= 2;
    }
}

int query(int v) {
    v += base;
    int res = 0;
    while (v) {
        res += Tree[v];
        v /= 2;
    }
    return res;
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n; cin >> n;
    for (int i=1; i<=n-1; i++) {
        int a, b; cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    level[1] = -1;
    dfs(1, 1);

    int m; cin >> m;
    for (int i=1; i<=n+m-1; i++) {
        char op; cin >> op;
        if (op == 'A') {
            int a, b; cin >> a >> b;
            if (level[a] < level[b])
                swap(a, b);
            update(pre[a], post[a], 1);
        }
        else {
            int a; cin >> a;
            cout << level[a] - query(pre[a]) << "\n";
        }
    }

    return 0;
}