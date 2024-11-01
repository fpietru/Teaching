/*
    Zadanie "Temperatura" z XVIII OI, II etap
*/
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define FR first
#define SD second

constexpr int LIMIT = 1e6+6;
int x[LIMIT], y[LIMIT];
deque<pii> Q;


void dodaj(int wart, int poz) {
    while (!Q.empty() && Q.back().FR <= wart)
        Q.pop_back();
    Q.push_back({wart, poz});
}

void usun(int poz) {
    while (!Q.empty() && Q.front().SD <= poz)
        Q.pop_front();
}

int getmax() {
    return (Q.empty() ? INT_MIN : Q.front().FR);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n; cin >> n;
    for (int i=1; i<=n; i++)
        cin >> x[i] >> y[i];

    int ans = 1;
    int pocz = 0;
    for (int kon=1; kon<=n; kon++) {
        while (pocz+1 <= n && getmax() <= y[pocz+1]) {
            pocz++;
            dodaj(x[pocz], pocz);
        }
        ans = max(ans, pocz-kon+1);
        usun(kon);
    }

    cout << ans << "\n";

    return 0;
}