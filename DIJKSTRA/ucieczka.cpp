/*
	Zadanie "Wielka ucieczka traktorem" z KI
*/
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define FR first
#define SD second

const int MxN = 1e5+5;
int d[MxN];
vector<int> p[MxN];
vector<pii> G[MxN];
set<int> st;

void dfs(int v, int anc)
{
	st.insert(v);

	for (auto u : p[v])
		if (u != anc)
			dfs(u, v);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m, a, b, c;

	cin >> n >> m;
	for (int i=1; i<=m; i++)
	{
		cin >> a >> b >> c;
		G[a].push_back({b, c});
		G[b].push_back({a, c});
	}

	for (int i=1; i<=n; i++)
		d[i] = 1e9+7;

	priority_queue<pii, vector<pii>, greater<pii>> qu;

	d[1] = 0;
	qu.push({0, 1});

	while (!qu.empty())
	{
		int v = qu.top().SD;
		int w = qu.top().FR;
		qu.pop();

		if (w != d[v])
			continue;

		for (auto e : G[v])
		{
			int u = e.FR;
			int w = e.SD;

			if (d[v] + w < d[u])
			{
				d[u] = d[v] + w;
				p[u].clear();
				p[u].push_back(v);
				qu.push({d[u], u});
			}
			else if (d[v] + w == d[u])
				p[u].push_back(v);
		}
	}

	dfs(n, n);
	for (auto v : st)
		cout << v << "\n";

	return 0;
}
