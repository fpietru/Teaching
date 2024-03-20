/*
	Zadanie: "Żywopłot"
	https://szkopul.edu.pl/problemset/problem/dABzva_j1-BvzKMsyxkuRoue/site/?key=statement
*/
#include <bits/stdc++.h>
using namespace std;

struct edge { int x, y, t; };
struct node { int p, s; };
const int MxNM = 1e6+66, MxN = 1e3+33;
vector<edge> edges[2];
node nodes[MxNM];
bool ans[2][MxN][MxN];

void mkset(int v)
{
	nodes[v].p = v;
	nodes[v].s = 1;
}

int getL(int v)
{
	while (nodes[v].p == v)
		return v;
	return nodes[v].p = getL(nodes[v].p);
}

void join(int a, int b)
{
	a = getL(a), b = getL(b);
	if (a == b) return;
	if (nodes[a].s < nodes[b].s)
		swap(a, b);
	nodes[b].p = a;
	nodes[a].s += nodes[b].s;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int rows, cols, cisy=0, tuje=0;
	cin >> rows >> cols;

	for (int i=0; i<rows; i++)
		for (int j=0; j<cols-1; j++)
		{
			char k; cin >> k;
			bool w = (k == 'C');
			cisy += w;
			tuje += !w;
			edges[w].push_back({j,i, 0});
		}

	for (int i=0; i<rows-1; i++)
		for (int j=0; j<cols; j++)
		{
			char k; cin >> k;
			bool w = (k == 'C');
			cisy += w;
			tuje += !w;
			edges[w].push_back({j,i, 1});
		}

	for (int i=0; i<rows*cols; i++)
		mkset(i);
	
	for (int k=0; k<2; k++)
		for (auto e : edges[k])
		{
			int x = e.x, y = e.y, t = e.t;
			if (!t && getL(y*cols+x) != getL(y*cols+(x+1)))
			{
				ans[0][y][x] = 1;
				if (!k) tuje--;
				else cisy--;
				join(y*cols+x, y*cols+(x+1));
			}
			else if (t && getL(y*cols+x) != getL((y+1)*cols+x))
			{
				ans[1][y][x] = 1;
				if (!k) tuje--;
				else cisy--;
				join(y*cols+x, (y+1)*cols+x);
			}
		}

	cout << tuje+cisy << " " << cisy << "\n";
	
	for (int i=0; i<2; i++)
		for (int j=0; j<rows-i; j++)
		{
			for (int k=0; k<cols-(i==0); k++)
				cout << (ans[i][j][k] ? "." : "Z");
			cout << "\n";
		}

	return 0;
}
