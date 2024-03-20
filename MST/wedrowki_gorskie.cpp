/*
	Zadanie "Wędrówki Górskie"
	https://szkopul.edu.pl/problemset/problem/obkMkh9R_fQ3R6s_TVJ42uwS/site/?key=statement
*/
#include <bits/stdc++.h>
using namespace std;

struct edge { int v, u, w, id; };
struct node { int p, s; };
const int MxN = 1e5+5, MxM = 3e5+5;
node nodes[MxN];
edge edges[MxM];
vector<int> ans;

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

bool cmp(edge A, edge B)
{
	return A.w > B.w;
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
	}

	sort(edges, edges+m, cmp);

	for (int i=0; i<m; i++)
	{
		int v = edges[i].v;
		int u = edges[i].u;
		int id = edges[i].id;

		if (getL(v) != getL(u))
			join(v, u);
		else
			ans.push_back(id+1);
	}

	cout << ans.size() << "\n";
	for (auto a : ans)
		cout << a << "\n";

	return 0;
}
