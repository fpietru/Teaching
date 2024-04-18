/*
    Sortowanie Topologiczne + dp
    Zadanie: https://cses.fi/problemset/task/1681/
*/
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
#define FR first
#define SD second
#define PB push_back
 
constexpr int MxN = 1e5+5;
constexpr int MOD = 1e9+7;
vector<int> G[MxN];
vector<int> tG[MxN];
vector<int> toposorted;
queue<int> Q;
int deg[MxN];
int dp[MxN];
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n, m; cin >> n >> m;
	for (int i=1; i<=m; i++) {
		int a, b; cin >> a >> b;
		G[a].PB(b);
		tG[b].PB(a);
		deg[b]++;
	}
	for (int i=1; i<=n; i++)
		if (deg[i] == 0) Q.push(i);
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
	dp[1] = 1;
	for (auto v : toposorted) {
		for (auto u : tG[v])
			dp[v] = ((ll)dp[v] + dp[u]) % MOD;
	}
	cout << dp[n] << "\n";
 
	return 0;
}