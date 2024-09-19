/*
	Zadanie "Krążki" z XIII OI, etap I
	Koszt Zamortyzowany
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
	
	int ans = 0;
	int poprzedni = n + 1;
	for (int i=1; i<=m; i++) {
		int d; cin >> d;
		
		int poziom = poprzedni - 1;
		while (poziom > 0 && rurka[poziom] < d)
			poziom--;
			
		poprzedni = poziom;
		ans = poziom;
		
		if (poziom == 0)
			break;
	}
	cout << ans << "\n";
	
	return 0;
}
