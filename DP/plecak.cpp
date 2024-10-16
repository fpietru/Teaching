/*
    Zadanie "Tradycyjny problem plecakowy"
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MxN = 1e4+44, MxK = 505;
int w[MxN], v[MxN];
ll dp[MxN][MxK];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int n, k; cin >> n >> k;
    for (int i=1; i<=n; i++)
        cin >> w[i] >> v[i];
    
    for (int i=1; i<=n; i++)
        for (int j=0; j<=k; j++)
        {
            if (w[i] > j)
                dp[i][j] = dp[i-1][j];
            else /* j >= w[i] */
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + (ll)v[i]);
        }
        
    cout << dp[n][k] << "\n";

    return 0;
}