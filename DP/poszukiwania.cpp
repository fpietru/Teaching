/*
    Zadanie "Poszukiwania"
*/
#include <bits/stdc++.h>
using namespace std;

constexpr int MxN = 1e3 + 13;
int dp[MxN][MxN];

int main ()
{
  ios_base::sync_with_stdio (0);
  cin.tie (0), cout.tie (0);

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
    {
	    int x; cin >> x;
	    dp[i][j] = max (dp[i - 1][j], dp[i][j - 1]) + x;
    }

  cout << dp[n][n] << "\n";

  return 0;
}