/*
	MST - Prim
	Zadanie: https://cses.fi/problemset/task/1675/
*/
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
#define FR first
#define SD second
#define PB push_back

constexpr int MxN = 1e5+5;
bool vis[MxN];
priority_queue<pii> pq;
vector<pii> G[MxN];

void process(int v) {
    vis[v] = 1;
    for (auto e : G[v]) {
        int u = e.FR;
        int w = e.SD;
        if (!vis[u])
            pq.push({-w, -u});
    }
}

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int n, m; cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int a, b, c; cin >> a >> b >> c;
        G[a].PB({b, c});
        G[b].PB({a, c});
    }

    process(1);
    ll mst_suma = 0;
    int krawedzi_w_mst = 0;
    while (!pq.empty()) {
        int u = -pq.top().SD;
        int w = -pq.top().FR;
        pq.pop();
        if (!vis[u]) {
            krawedzi_w_mst++;
            mst_suma += w;
            process(u);
        }
    }

    if (krawedzi_w_mst != n-1)
        cout << "IMPOSSIBLE\n";
    else cout << mst_suma << "\n";

	return 0;
}