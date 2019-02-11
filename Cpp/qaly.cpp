#include <iostream>
using namespace std;

int main() {
	int cases;
	double sum;
	cin >> cases;
	while(cases>0) {
		double q,y;
		cin >> q >> y;
		sum+=(q*y);
		cases--;
	}
	cout << sum<< endl;
	return 0;
}
