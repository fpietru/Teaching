/*
	Zadanie "Bajtocja"
	https://szkopul.edu.pl/problemset/problem/zdiC31EMJqdJtvrpCJgFlQD_/site/?key=statement
*/
#include <bits/stdc++.h>
using namespace std;
#define FR first
#define SD second

const int MxN = 7e3+3, MxM = 3e5+5;
struct edge { int v, u, id; };
struct node { int p, s; };
map<int, vector<edge>> mp;
node nodes[MxN];
bool ans[MxM];

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

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, m; cin >> n >> m;
	for (int i=0; i<m; i++)
	{
		int a, b, c; cin >> a >> b >> c;
		mp[c].push_back({a, b, i});
	}

	for (int i=1; i<=n; i++)
		mkset(i);

	for (auto p : mp)
	{
		int sz = p.SD.size();
		vector<edge> edges = p.SD;
		vector<bool> valid(sz);
		
		for (int i=0; i<sz; i++)
			if (getL(edges[i].v) != getL(edges[i].u))
				valid[i] = 1;
		
		for (int i=0; i<sz; i++)
			if (valid[i])
			{
				ans[edges[i].id] = 1;
				join(edges[i].v, edges[i].u);
			}
	
	}

	for (int i=0; i<m; i++)
		cout << (ans[i] ? "TAK\n" : "NIE\n");

	return 0;
}
