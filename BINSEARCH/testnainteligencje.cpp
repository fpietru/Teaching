/*
	Zadanie "Test na inteligencje" z XVII OI, etap I
	Wyszukiwanie Binarne
*/
#include <bits/stdc++.h>
#define PB push_back
#define FR first
#define SD second
using namespace std;

map<int, vector<int>> mp;

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	for (int i=1; i<=n; i++) {
		int x; cin >> x;
		mp[x].PB(i);
	}
	int q; cin >> q;
	while (q--) {
		int m; cin >> m;
		int ost = 0;
		bool ans = true;
		for (int i=1; i<=m; i++) {
			int x; cin >> x;
			auto upper = upper_bound(mp[x].begin(), mp[x].end(), ost);
			if (upper == mp[x].end())
				ans = false;
			else {
				ost = *upper;
			}
		}
		cout << (ans ? "TAK\n" : "NIE\n");
	}
	
	return 0;
}
