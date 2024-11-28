/*
	Sprawdzenie poprawności: https://cses.fi/problemset/task/1688/
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

constexpr int MxN = 2e5+5;
constexpr int LOG = 18;
vector<int> G[MxN];
pii st[2*MxN][LOG+1];
int tin[MxN];
int licznik;
int lg[2*MxN];

void dfs(int v, int p, int d) {
	tin[v] = licznik;
	st[licznik++][0] = {d, v};
	for (auto u : G[v])
		if (u != p) {
			dfs(u, v, d+1);
			st[licznik++][0] = {d, v};
		}
}

pii getmin(int a, int b) {
	int p = lg[b-a+1];
	return min(st[a][p], st[b-(1<<p)+1][p]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	lg[1] = 0;
	for (int i=2; i<2*MxN; i++)
		lg[i] = lg[(i>>1)] + 1;
	
	int n, q; cin >> n >> q;
	for (int i=2; i<=n; i++) {
		int x; cin >> x;
		G[x].PB(i); G[i].PB(x);
	}
	dfs(1, 1, 1);
	int m = 2*n-1;
	for (int k=1; k<=LOG; k++)
		for (int i=0; i+(1<<(k-1))<m; i++)
			st[i][k] = min(st[i][k-1], st[i+(1<<(k-1))][k-1]);
	
	while (q--) {
		int a, b; cin >> a >> b;
		a = tin[a]; b = tin[b];
		if (a > b) swap(a, b);
		cout << getmin(a, b).SD << "\n";
	}

	return 0;
}
