/*
	Zadanie "Morskie Opowieści" z XX OI, etap II
*/
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define FR first
#define SD second

struct query {
	int ed;
	int d;
	int id;
};

constexpr int MxN = 5e3+5;
constexpr int INF = 1e9+7;
constexpr int MxQ = 1e6+6;
vector<int> G[2*MxN];
vector<query> queries[MxN];
int dst[2*MxN];
bool res[MxQ];

void bfs(int st, int n) {
	for (int i=1; i<=2*n; i++)
		dst[i] = INF;

	queue<pii> Q;
	dst[st] = 0;
	Q.push({st, 0});
	
	while (!Q.empty()) {
		pii v = Q.front();
		Q.pop();
		
		for (auto u : G[v.FR])
			if (dst[u] == INF) {
				dst[u] = v.SD + 1;
				Q.push({u, v.SD+1});
			}
	}
	
	for (auto q : queries[st]) {
		if (G[st].size() == 0) {
			res[q.id] = (q.d == 0);
			return;
		}
		
		if (q.d % 2 == 0)
			res[q.id] = (q.d >= dst[q.ed]);
		else
			res[q.id] = (q.d >= dst[q.ed+n]);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n, m, q; cin >> n >> m >> q;
	for (int i=1; i<=m; i++) {
		int a, b; cin >> a >> b;
		G[a].push_back(b+n);
		G[b+n].push_back(a);
		G[a+n].push_back(b);
		G[b].push_back(a+n);
	}
	
	for (int i=1; i<=q; i++) {
		int a, b, d; cin >> a >> b >> d;
		queries[a].push_back({b, d, i});
	}
	
	for (int i=1; i<=n; i++)
		bfs(i, n);
	
	for (int i=1; i<=q; i++)
		cout << (res[i] ? "TAK\n" : "NIE\n");
	
	return 0;
}
