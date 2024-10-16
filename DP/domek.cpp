/*
    Zadanie: "Domek z Kart" z II etapu OIG
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MxN = (1<<17);
constexpr int MxK = 21;
ll dp[MxN][MxK];
ll wart[MxN];

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n, K; cin >> n >> K;
    K /= 2;
    int nr = 0;
    for (int p=1; p<=n; p++) {
        for (int i=1; i<=(1<<(p-1)); i++) {
            int a, b; cin >> a >> b;
            wart[++nr] = a + b;
        }
    }

    for (int v=nr; v>=1; v--) {
        if (v >= (1<<(n-1)))
            dp[v][1] = max(0LL, wart[v]);
        else {
            for (int k=1; k<=K; k++) {
                ll mx = 0LL;
                for (int wL=k-1; wL>=0; wL--)
                    mx = max(mx, dp[2*v][wL]+dp[2*v+1][k-wL-1] + wart[v]);
                dp[v][k] = mx;
            }
        }
    }

    ll ans = 0LL;
    for (int k=1; k<=K; k++)
        ans = max(ans, dp[1][k]);
    cout << ans << "\n";

    return 0;
}