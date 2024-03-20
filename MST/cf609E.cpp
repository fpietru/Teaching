/*
	Zadanie: "E. Minimum spanning tree for each edge"
	https://codeforces.com/problemset/problem/609/E
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FR first
#define SD second

struct edge { int v, u, w, id; };
struct node { int p, s; };
const int MxNM = 2e5+5, LOG = 18;
vector<pair<int, int>> G[MxNM];
edge edges[MxNM], unsorted[MxNM];
node nodes[MxNM];
ll MSTsum = 0;
int up[MxNM][LOG], mx[MxNM][LOG];
int lvl[MxNM];

void mkset(int v)
{
	nodes[v].p = v;
	nodes[v].s = 1;
}

int getL(int v)
{
	if (nodes[v].p == v)
		return v;
	return nodes[v].p = getL(nodes[v].p);
}

void join(int a, int b)
{
	a = getL(a), b = getL(b);
	if (a == b) return;
	if (nodes[a].s < nodes[b].s)
		swap(a, b);
	nodes[b].p = a;
	nodes[a].s += nodes[b].s;
}

bool cmp(edge A, edge B) { return A.w < B.w; }

void dfs(int v, int p)
{
	lvl[v] = lvl[p] + 1;
	up[v][0] = p;

	for (auto u : G[v])
		if (u.FR != p)
		{
			mx[u.FR][0] = u.SD;
			dfs(u.FR, v);
		}
}

int lca(int a, int b)
{
	if (a == b) return 0;
	if (lvl[a] < lvl[b])
		swap(a, b);

	int res = -1e9-7;

	for (int i=LOG-1; i>=0; i--)
		if (lvl[a] - (1<<i) >= lvl[b])
		{
			res = max(res, mx[a][i]);
			a = up[a][i];
		}

	while (a != b)
	{
		int log = 32 - __builtin_clz(lvl[a]) - 1;
		while (log > 0 && up[a][log] == up[b][log])
			log--;

		res = max({res, mx[a][log], mx[b][log]});
		a = up[a][log];
		b = up[b][log];
	}

	return res;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, m; cin >> n >> m;
	for (int i=1; i<=n; i++)
		mkset(i);

	for (int i=0; i<m; i++)
	{
		int a, b, c; cin >> a >> b >> c;
		edges[i] = {a, b, c, i};
		unsorted[i] = {a, b, c, 0};
	}

	sort(edges, edges+m, cmp);

	for (int i=0; i<m; i++)
	{
		int v = edges[i].v;
		int u = edges[i].u;
		int w = edges[i].w;
		int id = edges[i].id;

		if (getL(v) != getL(u))
		{
			G[v].push_back({u, w});
			G[u].push_back({v, w});
			join(v, u);
			unsorted[id].id = 1;
			MSTsum += (ll)w;
		}
	}

	for (int i=1; i<=n; i++)
		if (!up[i][0]) dfs(i, i);

	for (int k=1; k<LOG; k++)
		for (int x=1; x<=n; x++)
		{
			up[x][k] = up[up[x][k-1]][k-1];
			mx[x][k] = max(mx[x][k-1], mx[up[x][k-1]][k-1]);
		}

	for (int i=0; i<m; i++)
	{
		int v = unsorted[i].v;
		int u = unsorted[i].u;
		int w = unsorted[i].w;

		if (unsorted[i].id)
			cout << MSTsum << "\n";
		else
		{
			ll ans = MSTsum + (ll)w - (ll)lca(v, u);
			cout << ans << "\n";
		}
	}

	return 0;
}
