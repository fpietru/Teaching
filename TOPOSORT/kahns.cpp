/*
    Kahn's Algorithm
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
int deg[MxN];
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
 
	int n, m; cin >> n >> m;
	for (int i=1; i<=m; i++) {
		int a, b; cin >> a >> b;
		G[a].PB(b);
		deg[b]++;
	}
	queue<int> Q;
	for (int i=1; i<=n; i++)
		if (deg[i] == 0) Q.push(i);
	vector<int> toposorted;
	while (!Q.empty()) {
		int v = Q.front();
		Q.pop();
		toposorted.PB(v);
		for (auto u : G[v]) {
			deg[u]--;
			if (deg[u] == 0)
				Q.push(u);
		}
	}
	if ((int)toposorted.size() < n)
		cout << "IMPOSSIBLE\n";
	else {
		for (auto v : toposorted)
			cout << v << " ";
		cout << "\n";
	}
 
	return 0;
}