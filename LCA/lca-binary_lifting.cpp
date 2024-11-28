#include <bits/stdc++.h>
using namespace std;

const int MxN = 1e6, LOG = 20; // ceil(log2(10^6)) = 20
vector<int> G[MxN];
int up[MxN][LOG], lvl[MxN];

// Przechodzimy po wszystkich wierzchołkach i ustalamy:
//     - poziom na którym się znajdują (korzeń ma 1, kolejni synowie coraz większy)
//     - ojca danego wierzchołka
void dfs(int v, int p)
{
	lvl[v] = lvl[p] + 1;
	up[v][0] = p;

	for (auto u : G[v])
		if (u != p)
			dfs(u, v);
}

int lca(int a, int b)
{
	// zakładamy, że a jest na większym poziomie (dalej od korzenia / niżej)
	if (lvl[a] < lvl[b])
		swap(a, b);

	// wyrównujemy poziomy a i b
	for (int i=LOG-1; i>=0; i--)
		if (lvl[a] - (1<<i) >= lvl[b])
			a = up[a][i];

	// jeśli a i b są tym samym wierzchołkiem to LCA(a, b) = a
	if (a == b)
		return a;

	// teraz kiedy a i b są na tym samym poziomie, to możemy skakać tak długo, aż ich ojcowie będą różni i przybliżać ich do ojca przodka
	for (int i=LOG-1; i>=0; i--)
		if (up[a][i] != up[b][i])
		{
			a = up[a][i];
			b = up[b][i];
		}

	// zwracamy ojca a, który jest LCA(a, b)
	return up[a][0];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	for (int i=1; i<=n-1; i++)
	{
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	for (int i=1; i<=n; i++)
		if (up[i][0] == 0)
			dfs(i, i);

	// dla każdego wierzchołka obliczamy kolejnych przodków w odegłości 2^k
	for (int k=1; k<LOG; k++)
		for (int x=1; x<=n; x++)
			up[x][k] = up[up[x][k-1]][k-1];

	int q; cin >> q;
	while (q--)
	{
		int a, b;
		cin >> a >> b;
		cout << "LCA(" << a << "," << b << ") = " << lca(a, b) << "\n";
	}

	return 0;
}
