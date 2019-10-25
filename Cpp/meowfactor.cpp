#include <bits/stdc++.h>
using namespace std;

unsigned long long power(int i, int pow) {
	unsigned long long val, mult;
	mult = i;
	val = 1;
	while (pow--) {
		val *= mult;
	}
	return val;
}

int main() {
	unsigned long long num;
	unsigned long long div;
	cin >> num;	
	for (int i = 128; i > 0; i--) {
		div = power(i,9);
		if (num % div == 0) {
			cout << i << endl;
			break;
		}
	}
	return 0;
}
