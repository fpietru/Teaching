/*
    Zadanie "Wilcze Doły" z XXII OI, etap III
*/
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
#define FR first
#define SD second
#define PB push_back
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__) // debugging /*
template <typename T> struct tag:reference_wrapper <T>{ using reference_wrapper <T>::reference_wrapper; };
template <typename T1, typename T2> static inline tag <ostream> operator<<(tag <ostream> os, pair<T1, T2> const& p){ return os.get()<<"{"<<p.first<<", "<<p.second<<"}", os;}
template <typename Other> static inline tag <ostream> operator<<(tag <ostream> os, Other const& o){ os.get()<<o; return os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, vector <T> const& v){ os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, set <T> const& s){ vector <T> v; for (auto i: s) v.push_back(i); os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }
template <typename ...Args> void logger(string vars, Args&&... values) { cout<<"[ "<<vars<<" = "; string delim=""; (..., (cout<<delim<<values, delim=", ")); cout <<" ]\n"; }
/**/

constexpr int MxN = 2e6+6;
constexpr ll INF = 1e18+7;
ll p[MxN], arr[MxN], przykryte[MxN];
deque<int> Q;
int n, d;
ll S;

void dodaj(int i) {
	while (!Q.empty() && przykryte[Q.back()] < przykryte[i])
		Q.pop_back();
	Q.push_back(i);
}

void usun(int x) {
	while (!Q.empty() && Q.front() < x)
		Q.pop_front();
}

ll najwieksze() {
	return przykryte[Q.front()];
}

inline ll suma(int a, int b) {
	return p[b] - p[a-1];
}

ll ile(int kon, int pocz) {
	dodaj(pocz);
	usun(kon+d-1);
	if (pocz - kon + 1 <= d) return 0;
	return suma(kon, pocz) - najwieksze();
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> S >> d;
	for (int i=1; i<=n; i++)
		cin >> arr[i];
	
	for (int i=1; i<=n; i++)
		p[i] = p[i-1] + arr[i];
	
	for (int i=d; i<=n; i++)
		przykryte[i] = suma(i-d+1, i);
	
	int pocz = 1;
	dodaj(pocz);
	int ans = 0;
	for (int kon=1; kon<=n; kon++) {
		while (pocz+1 <= n && ile(kon, pocz+1) <= S)
			pocz++;
		ans = max(ans, pocz-kon+1);
	}
	cout << ans << "\n";

	return 0;
}