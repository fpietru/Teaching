/*
	Drzewo Przedziałowe Przedział-Przedział (ustaw, max) 
	Zadanie: https://szkopul.edu.pl/problemset/problem/-0A1PC3fNc2RK-qvoUQKGGLl/site/?key=statement
*/
#include <bits/stdc++.h>
using namespace std;

constexpr int base = (1<<20), INF = 1e9;
int Tree[2*base+10], Lazy[2*base+10];

void lazypush(int v)
{
	if (Lazy[v] != 0)
	{
		Tree[2*v] = Lazy[v];
		Lazy[2*v] = Lazy[v];
		Tree[2*v+1] = Lazy[v];
		Lazy[2*v+1] = Lazy[v];
	}
	Lazy[v] = 0;
}

void insert(int v, int lw, int rw, int L, int R, int val)
{
	if (rw < L || R < lw)
		return;
	else if (L <= lw && rw <= R)
	{
		Tree[v] = val;
		Lazy[v] = val;
	}
	else
	{
		lazypush(v);
		int mid = (lw + rw) / 2;
		insert(2*v, lw, mid, L, R, val);
		insert(2*v+1, mid+1, rw, L, R, val);
		Tree[v] = max(Tree[2*v], Tree[2*v+1]);
	}
}

int query(int v, int lw, int rw, int L, int R)
{
	if (rw < L || R < lw)
		return -INF;
	else if (L <= lw && rw <= R)
		return Tree[v];
	else
	{
		lazypush(v);
		int mid = (lw + rw) / 2;
		int Lson = query(2*v, lw, mid, L, R);
		int Rson = query(2*v+1, mid+1, rw, L, R);
		return max(Lson, Rson);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0), cin.tie(0);
	
	int d, n; cin >> d >> n;
	for (int i=0; i<n; i++)
	{
		int l, x; cin >> l >> x;
		int mx_h = query(1, 0, base-1, x, x+l-1);
		insert(1, 0, base-1, x, x+l-1, mx_h+1); 
	}
	
	cout << query(1, 0, base-1, 0, d) << "\n";
	
	return 0;
}
