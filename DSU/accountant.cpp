/*
	Zadanie "Accountant"
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FR first
#define SD second

constexpr int MxN = 1e6;
constexpr ll INF = 1e18+18;
struct node
{
	int s, p;
	ll val, diff;
};
node nodes[MxN+10];

void init(int v)
{
	nodes[v].s = 1;
	nodes[v].p = v;
	nodes[v].val = -INF;
	nodes[v].diff = 0LL;
}

// bez kompresji ścieżek, aby dało się zliczać total_diff
// total_diff = suma diffów na ścieżce z wierzchołka do korzenia/lidera drzewa
// total_diff[lider] = 0 zawsze
pair<int, ll> getL(int v)
{
	ll total_diff = nodes[v].diff;
	while (nodes[v].p != v)
	{
		v = nodes[v].p;
		total_diff += nodes[v].diff;
	}
	
	return {v, total_diff};
}

void join(int a, int b, ll r)
{
	if (nodes[a].s < nodes[b].s)
	{
		swap(a, b);
		r *= -1;
	}
	nodes[a].s += nodes[b].s;
	nodes[b].p = a;
	nodes[b].diff = -r;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	for (int i=1; i<=MxN; i++)
		init(i);

	int q; cin >> q;
	for (int i=1; i<=q; i++)
	{
		char op; cin >> op;
		if (op == 'd')
		{
			int a, b; ll r;
			cin >> a >> b >> r;
			
			pair<int, ll> La = getL(a);
			pair<int, ll> Lb = getL(b);
			
			// ten sam lider, ale total_diffy się nie zgadzają
			if (La.FR == Lb.FR && (La.SD - Lb.SD != r))
				cout << i << "\n";
			else if (La.FR != Lb.FR)
			{
				// obaj liderzy mają wartość
				if (nodes[La.FR].val != -INF && nodes[Lb.FR].val != -INF)
				{
					ll vala = nodes[La.FR].val + La.SD;
					ll valb = nodes[Lb.FR].val + Lb.SD;
					// wartości a i b się nie zgadzają
					if (vala - valb != r)
					{
						cout << i << "\n";
						continue;
					}
				}
				
				// łączenie drzew, ustawianie diffa dla jednego z liderów
				join(La.FR, Lb.FR, r - La.SD + Lb.SD);
			}
			
		}
		else if (op == 'v')
		{
			int v; ll x;
			cin >> v >> x;
			pair<int, ll> L = getL(v);
			
			// lider nie ma wartości => trzeba mu ją nadać
			if (nodes[L.FR].val == -INF)
				nodes[L.FR].val = x - L.SD;
			else if (nodes[L.FR].val + L.SD != x) // wartość v się nie zgadza
				cout << i << "\n";
		}
	}
	
	return 0;
}
