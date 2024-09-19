/*
	Zadanie "Krążki" z XIII OI, etap I
	Wyszukiwanie Binarne
*/
#include <bits/stdc++.h>

using namespace std;

constexpr int MxN = 3e5+5;
int rurka[MxN];

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n, m; cin >> n >> m;
	
	int mi = 1e9+7;
	for (int i=1; i<=n; i++) {
		int d; cin >> d;
		mi = min(mi, d);
		rurka[i] = mi;
	}
	
	rurka[n+1] = 0; // dodaje wartownika na koniec
	
	int low = 1;
	int high = n+1;
	int ans;
	
	while (m--) {
		int d; cin >> d;
		
		while (low < high) {
			int mid = (low + high) / 2;
			if (rurka[mid] >= d)
				low = mid+1;
			else high = mid;
		}
		low--;
		ans = low;
		high = low;
		low = 1;
	}
	cout << ans << "\n";
	
	return 0;
}
