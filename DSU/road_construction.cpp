/*
	DSU
	Zadanie: https://cses.fi/problemset/task/1676
*/
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
#define FR first
#define SD second
#define PB push_back
 
struct node { int p, s; };
struct edge { int v, u, w; };
constexpr int MxN = 1e5+5;
constexpr int MxM = 2e5+5;
node nodes[MxN];
 
int components;
int mx;
 
void init(int v) {
	nodes[v].p = v;
	nodes[v].s = 1;
}

int getL(int v) {
	if (nodes[v].p == v)
		return v;
	return nodes[v].p = getL(nodes[v].p);
}

void join(int a, int b) {
	a = getL(a), b = getL(b);
	if (a == b) return;
	if (nodes[a].s < nodes[b].s) swap(a, b);
	nodes[a].s += nodes[b].s;
	nodes[b].p = a;
	components--;
	mx = max(mx, nodes[a].s);
}
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
 
 	int n, m; cin >> n >> m;
 	for (int i=1; i<=n; i++)
 		init(i);
 	components = n;
 	mx = 1;
 	
 	for (int i=1; i<=m; i++) {
 		int a, b; cin >> a >> b;
 		join(a, b);
 		cout << components << " " << mx << "\n";
 	}
 
	return 0;
}
