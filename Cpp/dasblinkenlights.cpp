#include <iostream>
using namespace std;

int main() {
	int p,q,t;
	bool pass = false;
	cin >> p >> q >> t;
	for (int i = 1; i <= t; i++) {
		if (i%p == 0 && i%q == 0) {
			cout << "yes" << endl;
			pass = true;
			break;
		}	
	}
	if (!pass) cout << "no" << endl;
	return 0;
}
