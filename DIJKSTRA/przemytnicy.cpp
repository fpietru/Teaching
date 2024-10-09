/*
	Zadanie "Przemytnicy" z X OI, etap I
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FR first
#define SD second

const int MxN = 5e3+3;
int border[MxN];
ll d[2*MxN];
vector<pair<int, int>> G[2*MxN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, m, a, b, c;

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> border[i];

	cin >> m;
	for (int i=1; i<=m; i++)
	{
		cin >> a >> b >> c;
		G[a].push_back({b, c});
		G[a+n].push_back({b+n, c});
	}

	for (int i=1; i<=n; i++)
		G[i].push_back({i+n, border[i]/2});

	for (int i=1; i<=2*n; i++)
		d[i] = 1e18;

	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> qu;

	d[1] = 0;
	qu.push({0, 1});

	while (!qu.empty())
	{
		int v = qu.top().SD;
		ll dv = qu.top().FR;
		qu.pop();

		if (dv != d[v])
			continue;

		for (auto e : G[v])
		{
			int u = e.FR;
			ll w = e.SD;

			if (d[v] + w < d[u])
			{
				d[u] = d[v] + w;
				qu.push({d[u], u});
			} 
		}
	}

	cout << d[1+n] << "\n";

	return 0;
}
