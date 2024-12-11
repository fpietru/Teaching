#include <bits/stdc++.h>
using namespace std;

constexpr int MxN = 2e5+5;
int tab[MxN];

int main () {
	int n, q; cin >> n >> q;
	for (int i=1; i<=n; i++)
		cin >> tab[i];
	
	for (int i=1; i<=q; i++) {
		int op, a, b; cin >> op >> a >> b;
		if (op == 1) {
			tab[a] = b;
		}
		else {
			long long suma = 0;
			for (int j=a; j<=b; j++)
				suma += tab[i];
			cout << suma << "\n";
		}
	}

	return 0;
}
