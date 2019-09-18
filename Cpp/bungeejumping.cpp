#include <iostream>
#include <cmath>
using namespace std;

int main() {
	long double k,l,s,w;
	cin >> k >> l >> s >> w;
	string out = "";
	while(k||l||s||w) {
		// vf^2 = v0^2 + 2 * a * d
		// vf = sqrt(2ad)
		// vel at impact
		long double jPE = w * 9.81 * s;	
		long double bPE = 0.5 * k * (s-l>0 ? s-l : 0) * (s-l>0 ? s-l : 0);	
		if(jPE-bPE>w*50) {
			out += "Killed by the impact.\n";
		} else if(bPE > jPE) {
			out += "Stuck in the air.\n";
		} else out += "James Bond survives.\n";
		cin >> k >> l >> s >> w;
	}
	cout << out;
	return 0;
}
