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
vector<int> G[MxN];
vector<int> tG[MxN];
vector<int> toposorted;
vector<int> sciezka;
queue<int> Q;
int deg[MxN];
int przed[MxN];
int dp[MxN];
int od[MxN];
 
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
	for (auto v : toposorted) {
		int mx = 0, kto = -1;
		for (auto u : tG[v])
			if (dp[u] >= mx && od[u] == 1) {
				mx = dp[u];
				kto = u;
			}
		dp[v] = mx + 1;
		przed[v] = kto;
		if (kto != -1) od[v] = od[kto];
		else           od[v] = v;
	}
	for (int v=n; v!=-1; v=przed[v])
		sciezka.PB(v);
	reverse(sciezka.begin(), sciezka.end());
	if (od[n] != 1)
		cout << "IMPOSSIBLE\n";
	else {
		cout << sciezka.size() << "\n";
		for (auto v : sciezka)
			cout << v << " ";
		cout << "\n";
	}	
 
	return 0;
}