#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;

int main() {
	int cases;
	cin >> cases;
	for (int i = 0; i < cases; i++) {
		int sum;
		int difference;
		bool found = false;
		cin >> sum;
		cin >> difference;
		if (sum < difference) {
			cout << "impossible" << endl;
			continue;
		}
		for (int j = ceil(sum/2.0); j >= 0; j--) {
			int k = sum - j;
			if (abs(j - k) == difference) {
				cout << (k > j ? k : j) <<  " " << (k < j ? k : j) << endl; 
				found = true;
				break;
			}
		}
	 	if (!found) cout << "impossible" << endl;	
	}
}
