#include <bits/stdc++.h>
using namespace std;

int RAND(int a, int b) {
	return a + rand() % (b-a+1);
}

int main (int argc, char *argv[]) {
	srand(stoi(argv[1]));
	
	int n = RAND(200000, 200000);
	int q = RAND(1, 2);
	
	cout << n << " " << q << "\n";
	
	for (int i=1; i<=n; i++)
		cout << RAND(1, 200000) << " ";
	cout << "\n";
	
	for (int i=1; i<=q; i++) {		
		int op = RAND(1, 2);
		if (op == 1) {
			cout << op << " " << RAND(1, n) << " " << RAND(200, 300) << "\n";
		}
		else {
			int a = RAND(1, n); 
			int b = RAND(a, n);
			cout << op << " " << a << " " << b << "\n"; 
		}
	}
	
	return 0; // wszystko działa -> zwróć 0
}
