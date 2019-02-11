#include <cmath>
#include <iostream>
using namespace std;

int main() {
	long long val;
	long long div;
	cin >> val;
	for (int i = /*int(ceil(pow(val,1/9.0)))*/128; i > 0; i--) {
		div = pow(i,9);
		if (val % div == 0) {
			cout << i << endl;
			break;
		}
	}
	return 0;
}
