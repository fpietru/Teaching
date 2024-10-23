/*
    Zadanie "Luk Triumfalny" z XX OI, etap 2
    binsearch po wyniku + dynamik na drzewie
*/
#include <bits/stdc++.h>
using namespace std;

constexpr int LIMIT = 3e5+35;
vector<int> G[LIMIT];
int dp[LIMIT]; 
/*

dp[v] = minimalna, niezbędna liczba wcześniej wybudowanych łuków triumfalnych
        w poddrzewie v, która zapewnia strategię wygrywającą, jeśli król 
        właśnie wchodzi do wierzchołka v mającego już łuk triumfalny

dp[lisc] = 0
dp[v] = max(0, \sum_{i=1}^{s}(dp[u_i] + 1) - k), gdzie u_1, u_2, ... , u_s to synowie v

*/

void dfs(int v, int p, int k) {
    int ile_synow = 0;
    int suma_dp = 0;
    for (auto u : G[v])
        if (u != p) {
            dfs(u, v, k);
            ile_synow++;
            suma_dp += dp[u] + 1; 
        }
    
    if (ile_synow == 0)
        dp[v] = 0;
    else
        dp[v] = max(0, suma_dp - k);
}

bool czy_ok(int k) {
    memset(dp, 0, sizeof(dp));
    dfs(1, 1, k);
    return (dp[1] == 0);
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n; cin >> n;
    for (int i=1; i<=n-1; i++) {
        int a, b; cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    int low = 0;
    int high = n;
    while (low < high) {
        int mid = (low + high) / 2;
        if (czy_ok(mid) == 0)
            low = mid + 1;
        else high = mid;
    }

    cout << low << "\n";

    return 0;
}