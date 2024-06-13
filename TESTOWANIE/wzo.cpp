/*
	Zadanie: https://cses.fi/problemset/task/1648/
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int base = (1<<18);
ll Tree[2*base];

void update(int v, ll x) {
	v += base;
	Tree[v] = x;
	while (v) {
		v /= 2;
		Tree[v] = Tree[2*v] + Tree[2*v+1];
	}
}

ll query(int a, int b) {
	ll res = 0;
	a += base - 1;
	b += base + 1;
	while ((a/2) != (b/2)) {
		if (a%2 == 0) res += Tree[a+1];
		if (b%2 == 1) res += Tree[b-1];
		a /= 2;
		b /= 2;
	}
	return res;
}

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n, q; cin >> n >> q;
	for (int i=1; i<=n; i++) {
		int x; cin >> x;
		update(i, x);
	}
	
	while (q--) {
		int op, a, b; cin >> op >> a >> b;
		if (op == 1) {
			update(a, b);
		}
		else cout << query(a, b) << "\n";
	}

	return 0;
}
