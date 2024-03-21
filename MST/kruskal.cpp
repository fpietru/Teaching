/*
	MST - Kruskal
	Zadanie: https://cses.fi/problemset/task/1675/
*/
#include <bits/stdc++.h>
using namespace std;
/*
	Zamiast męczyć się z piseniem long long, first, second, itd
	możemy utworzyć skrócone nazwy i oszczędzić czas i palce (mniej klepania)
*/
using pii = pair<int, int>;
using ll = long long;
#define FR first
#define SD second
#define PB push_back 

struct node { int p, s; };
constexpr int MxN = 1e5+5;
node nodes[MxN];

// DSU
void init(int v) {
	nodes[v].p = v;
	nodes[v].s = 1;
}

int find(int v) {
	return (nodes[v].p == v ? v : nodes[v].p = find(nodes[v].p));
}

void join(int a, int b) {
	a = find(a); b = find(b);
	if (a == b) return;
	if (nodes[a].s < nodes[b].s)
		swap(a, b);
	nodes[a].s += nodes[b].s;
	nodes[b].p = a;
}

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	vector<pair<int, pii>> krawedzie;

	// Wczytujemy krawędzie
	int n, m; cin >> n >> m;
	for (int i=1; i<=m; i++) {
		int a, b, c; cin >> a >> b >> c;
		krawedzie.PB({c, {a, b}});
	}
	
	// Sortujemy krawędzie po wagach
	sort(krawedzie.begin(), krawedzie.end());

	// Inicjujemy każdy wierzchołek jako oddzielną spójną
	for (int i=1; i<=n; i++)
		init(i);

	// Idziemy po krawędziach i jeśli łączą dwie różne spójne to bierzemy krawędż do MST
	int krawedzi_w_mst = 0;
	ll suma_wag_mst = 0;
	for (auto e : krawedzie) {
		int v = e.SD.FR;
		int u = e.SD.SD;
		int w = e.FR;
		if (find(v) != find(u)) {
			krawedzi_w_mst++;
			suma_wag_mst += w;
			join(v, u);
		}
	}

	if (krawedzi_w_mst != n-1)
		cout << "IMPOSSIBLE\n";
	else cout << suma_wag_mst << "\n";

	return 0;
}
