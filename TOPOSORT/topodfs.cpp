/*
    Toposort with DFS
    https://cses.fi/problemset/task/1679/
*/
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
#define FR first
#define SD second
#define PB push_back
 
constexpr int MxN = 1e5+5;
vector<int> G[MxN];
vector<int> toposorted;
int nr[MxN];
bool vis[MxN];
 
void dfs(int v) {
    vis[v] = true;
    for (auto u : G[v])
        if (!vis[u]) dfs(u);
    toposorted.PB(v);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
 
	int n, m; cin >> n >> m;
	for (int i=1; i<=m; i++) {
		int a, b; cin >> a >> b;
		G[a].PB(b);
	}

    for (int v=1; v<=n; v++)
        if (!vis[v]) dfs(v);
    reverse(toposorted.begin(), toposorted.end());

    for (int i=1; i<=n; i++)
        nr[toposorted[i-1]] = i;
    
    bool ok = true;
    for (int v=1; v<=n; v++)
        for (auto u : G[v])
            if (nr[u] < nr[v])
                ok = false;

	if (!ok)
		cout << "IMPOSSIBLE\n";
	else {
		for (auto v : toposorted)
			cout << v << " ";
		cout << "\n";
	}
 
	return 0;
}