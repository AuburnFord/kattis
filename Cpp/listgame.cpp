#include <iostream>
using namespace std;

int main() {
	int num;
	cin >> num;
	int count = 0; //number of prime factors
	int n = 2;
	//dont count 1 as factor
	while(n*n <= num) {
		if(num%n==0) {
			count++;
			num/=n;
		} else n++;
	}
	count++;
	cout << count << "\n";
	return 0;
}
