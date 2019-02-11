#include <cstdlib>
#include <cmath>
#include <iostream>
#include <unordered_set>
using namespace std;

int digit2_sum(int val);

int main() {
	int cases;
	int caseNum;
	int candidate;
	cin >> cases;
	for (int i = 1; i <= cases; i++) {
		cin >> caseNum;
		cin >> candidate;
		// check if prime
		bool prime = true;
		if(candidate == 1) prime = false;
		for (int j = 2; j <= sqrt(candidate) && prime; j++) {
		       if (candidate%j == 0) prime = false;	
		}
		// check if happy
		if (prime) {
			int val = candidate;
			unordered_set<int> visited;
			while (val != 1) {
				if (visited.find(val) != visited.end()) {
					prime = false;
					break;
				} 
				visited.insert(val);	
				//next num in sequence
				val = digit2_sum(val);	
			}
		}
		cout << caseNum<<" "<<candidate<<" "<<(prime ? "YES" : "NO")<< endl;
	}
	return 0;
}

int digit2_sum(int val) {
	int sum = 0;
	while (val > 0) {
		sum += pow(val%10, 2);
		val/=10;
	}
	return sum; 
}

