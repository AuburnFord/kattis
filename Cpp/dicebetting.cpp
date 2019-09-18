#include <iostream>
using namespace std;
// possible distribution to lower calcs?
double compute(int throws, int needed, int seen, int sides, double ** mem) {
	if (needed == seen) {
		return 1;
	}
	if ((needed-seen)>throws) {
		return 0;
	}
	if (mem[throws][seen] != -1) {
		return mem[throws][seen];
	}
	double chance = 0;
	chance += compute(throws-1,needed,seen+1,sides,mem) * (sides-seen) /  sides;
	chance += compute(throws-1,needed,seen, sides,mem) * seen /  sides;
	
	mem[throws][seen] = chance;
	return chance;
}

int main() {
	int n,s,k;
	cin >> n >> s >> k;
	cout.precision(10);
	double ** mem = new double*[n+1];
	for (int i = 1; i <= n; i++) {
		mem[i] = new double[k+1];
		for (int j = 0; j <= k; j++) {
			mem[i][j] = -1;
		}
	}
	cout << compute(n,k,0,s,mem) << endl;
	return 0;
}
