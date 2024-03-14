/*
	Zadanie "Kolonie"
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct node { int s; int p; ll sumM; int miIQ; int mxIQ; };
constexpr int MxN = 1e6+16;
node nodes[MxN];

void init(int v, int mass, int iq)
{
    nodes[v].s = 1;
    nodes[v].p = v;
    nodes[v].sumM = (ll)mass;
    nodes[v].miIQ = iq;
    nodes[v].mxIQ = iq;
}

int getL(int v)
{
    if (nodes[v].p == v)
        return v;
    return nodes[v].p = getL(nodes[v].p);
}

void join(int a, int b)
{
    a = getL(a), b = getL(b);
    if (a != b)
    {
        if (nodes[a].s < nodes[b].s)
            swap(a, b);
        nodes[a].s += nodes[b].s;
        nodes[b].p = a;
        nodes[a].sumM += nodes[b].sumM;
        nodes[a].miIQ = min(nodes[a].miIQ, nodes[b].miIQ);
        nodes[a].mxIQ = max(nodes[a].mxIQ, nodes[b].mxIQ);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int n; cin >> n;
    for (int i=1; i<=n; i++)
    {
        int a, b; cin >> a >> b;
        init(i, a, b);
    }
    
    string op;
    while (cin >> op)
    {
        if (op == "JOIN")
        {
            int a, b; cin >> a >> b;
            join(a, b);
        }
        else if (op == "IQ_MIN")
        {
            int v; cin >> v;
            cout << nodes[getL(v)].miIQ << "\n";
        }
        else if (op == "IQ_MAX")
        {
            int v; cin >> v;
            cout << nodes[getL(v)].mxIQ << "\n";            
        }
        else
        {
            int v; cin >> v;
            cout << nodes[getL(v)].sumM << "\n";
        }
    }

    return 0;
}
