#include <bits/stdc++.h>
using namespace std;

constexpr int LIMIT = 1e6+6;
int p[LIMIT];

int main () {

    string s; cin >> s;
    int n = s.size();
    p[0] = 0; // wczesniej zainicjalizowalem tablice
    for (int i=0; i<n-1; i++) {
        int j = p[i];
        while (j > 0 && s[j] != s[i+1]) {
            j = p[j-1];
        }
        if (s[j] == s[i+1]) {
            j++;
        }
        p[i+1] = j;
    }

    for (int i=0; i<n; i++)
        cout << p[i] << " ";
    cout << "\n";

    return 0;
}