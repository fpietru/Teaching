/*
	MST - Prim
	Zadanie: https://cses.fi/problemset/task/1675/
*/
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
#define FR first
#define SD second
#define PB push_back

constexpr int MxN = 1e5+5;
bool vis[MxN];
priority_queue<pii> pq;
vector<pii> G[MxN];

// Wrzucamy wszystkie krawędzie wychodzące z v do jeszcze nie odwiedzonych wierzchołków do kolejki priorytetowej
void process(int v) {
    vis[v] = 1;
    for (auto e : G[v]) {
        int u = e.FR;
        int w = e.SD;
        if (!vis[u])
            pq.push({-w, u}); // Kolejka priorytetowa daje podgląd do największego elementu (default'owo), aby mieć dostęp do najmniejszego możemy wrzucać (-1)*element do kolejki, a potem przy wyjmowaniu znowu mnożyć przez (-1)
    }
}

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	// Wczytujemy graf
    int n, m; cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int a, b, c; cin >> a >> b >> c;
        G[a].PB({b, c});
        G[b].PB({a, c});
    }

    process(1); // Wybieramy dowolny wierzchołek w grafie od którego zaczniemy
    ll suma_wag_mst = 0;
    int krawedzi_w_mst = 0;
    while (!pq.empty()) {
        int u = pq.top().SD;
        int w = -pq.top().FR; // Zmieniamy znak po wyjęciu
        pq.pop();
        if (!vis[u]) {
            krawedzi_w_mst++;
            suma_wag_mst += w;
            process(u);
        }
    }

    if (krawedzi_w_mst != n-1)
        cout << "IMPOSSIBLE\n";
    else cout << suma_wag_mst << "\n";

	return 0;
}
