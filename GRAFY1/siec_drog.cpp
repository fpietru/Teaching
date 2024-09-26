/*
	Zadanie "Sieć dróg" z V OI, 2 etap
*/
#include <bits/stdc++.h>
using namespace std;

constexpr int MxN = 222;
int G[MxN][MxN];

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			cin >> G[i][j];
			
	vector<pair<int, int>> ans;
	for (int a=1; a<=n-1; a++)
		for (int b=a+1; b<=n; b++) {
			bool sasiedzi = true;
			for (int c=1; c<=n; c++)
				if (c != a && c != b && G[a][c] + G[c][b] == G[a][b]) {
					sasiedzi = false;
					break;
				}
			if (sasiedzi)
				ans.push_back(make_pair(a, b));
		}
	
	sort(ans.begin(), ans.end());
	for (auto p : ans)
		cout << p.first << " " << p.second << "\n";


	return 0;
}
