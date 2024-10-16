/*
	Zadanie "Co ma babcia Bajtazara do darmowego kebaba?"
*/
#include <bits/stdc++.h>
using namespace std;

constexpr int MxN = 5e3+3;
int dp[MxN][MxN];
string A, B, ans = "";

void recover(int i, int j)
{
	if (i == 0 || j == 0)
		return;

	if (A[i-1] == B[j-1])
	{
		ans += A[i-1];
		return recover(i-1, j-1);
	}
	
	if (dp[i-1][j] >= dp[i][j-1])
		return recover(i-1, j);
	else
		return recover(i, j-1);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> A >> B;
	int n = A.size();
	int m = B.size();

	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
		{
			if (A[i-1] == B[j-1])
				dp[i][j] = dp[i-1][j-1] + 1;
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}

	recover(n, m);
	reverse(ans.begin(), ans.end());

	cout << dp[n][m] << "\n";
	cout << ans << "\n";
	
	return 0;
}