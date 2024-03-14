/*
	Zadanie "Tunele"
*/
#include <bits/stdc++.h>
using namespace std;
#define FR first
#define SD second

struct node { int p, s; };
const int MxN = 1e5+55;
const int MxM = 2e5+55;
node nodes[MxN];
pair<int, int> ques[MxM];

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

	int n, m, k; cin >> n >> m >> k;
	
	for (int i=2; i<=m+1; i++)
	{
		int a, b; cin >> a >> b;
		ques[i] = {a, b};
	}

	for (int i=1; i<=n; i++)
		mkset(i);

	int comps = n, ans=1;
	for (int i=m+1; i>=1; i--)
	{		
		int a = ques[i].FR;
		int b = ques[i].SD;
		// cout << i << " | " << comps << " [" << a << "," << b << "]\n";
		if (comps == k) ans = i;

		if (getL(a) != getL(b))
			comps--, join(a, b);
	}

	cout << ans << "\n";

	return 0;
}
