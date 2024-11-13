#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int p = 31;
constexpr int m = 1e9+7;
constexpr int LIMIT = 1e6+6;

int ppow[LIMIT];
int inv[LIMIT];

void precompute_powers(int n) {
    ppow[0] = 1;
    for (int i=1; i<=n; i++)
        ppow[i] = (1LL * ppow[i-1] * p) % m;
}

int fast_pow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = (1LL * res * a) % m;
        a = (1LL * a * a) % m;
        b /= 2;
    }
    return res;
}

void precompute_inverses(int n) {
    inv[0] = 1;
    int inverse = fast_pow(p, m-2);
    inv[1] = inverse;
    for (int i=2; i<=n; i++)
        inv[i] = (1LL * inv[i-1] * inverse) % m;
}

int h(const string &s) {
    int res = 0;
    for (int i=0; i<s.size(); i++)
        res = (res + 1LL * (s[i]-'a'+1) * ppow[i]) % m;
    return res;
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie();

    precompute_powers(LIMIT-1);
    precompute_inverses(LIMIT-1);

    string a = "abak";
    string b = "abbk";
    cout << h(a) << " " << h(b) << "\n";

    return 0;
}