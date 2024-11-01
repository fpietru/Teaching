/*
    Zadanie "Piloci" z XVII OI, III etap
*/
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
#define FR first
#define SD second
#define PB push_back

constexpr int MxN = 3e6+6;
int arr[MxN];
deque<int> Q1, Q2;

void dodaj(int i) {
	while (!Q1.empty() && arr[Q1.back()] > arr[i]) Q1.pop_back();
	while (!Q2.empty() && arr[Q2.back()] < arr[i]) Q2.pop_back();
	Q1.push_back(i);
	Q2.push_back(i);
}

void skroc(int i) {
	while (!Q1.empty() && Q1.front() < i) Q1.pop_front();
	while (!Q2.empty() && Q2.front() < i) Q2.pop_front(); 
}

int query(int i, int j) {
	dodaj(j);
	skroc(i);
	return arr[Q2.front()] - arr[Q1.front()];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int tolerancja, n; cin >> tolerancja >> n;
	for (int i=1; i<=n; i++)
		cin >> arr[i];
	
	int pocz = 1, ans = 0;
	dodaj(pocz);
	for (int kon=1; kon<=n; kon++) {
		while (pocz+1 <= n && query(kon, pocz+1) <= tolerancja)
			pocz++;
		ans = max(ans, pocz-kon+1);
	}
	cout << ans << "\n";	

	return 0;
}