/*
	Zadanie https://cses.fi/problemset/task/1651/
	Podstawa Implementacja Drzewa Przedziałowego Przedział-Punkt (+,sum)
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int base = (1<<18);
ll Tree[2*base];

void update(int a, int b, int x) {
	a += base - 1;
	b += base + 1;
	while ((a/2) != (b/2)) {
		if (a % 2 == 0) Tree[a+1] += x; 
		if (b % 2 == 1) Tree[b-1] += x;
		a /= 2;
		b /= 2;
	}
}

ll query(int v) {
	ll res = 0;
	v += base;
	while (v) {
		res += Tree[v];
		v /= 2;
	}
	return res;
}

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, q; cin >> n >> q;
	for (int i=1; i<=n; i++) {
		int x; cin >> x;
		update(i, i, x);
	}
	while (q--) {
		int op; cin >> op;
		if (op == 1) {
			int a, b, u; cin >> a >> b >> u;
			update(a, b, u);
		}
		else {
			int k; cin >> k;
			cout << query(k) << "\n";
		}
	}

	return 0;
}
