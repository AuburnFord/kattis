#include <iostream>
using namespace std;

int main() {
	int a, b, maxB, minOut;
	cin >> a >> b >> maxB >> minOut;
	int maxR = 0;
	int x,y;
	if (a >= b) {
		x = maxB - 1;
		y = 1;
		maxR = a*x + b*y;	
	} else {
		y = maxB - 1;
		x = 1;
		while (2*x + y < minOut) {
			x++;
			y--;	
		}
		maxR = a*x +b*y;
	}
	cout << maxR << endl;
	return 0;
}
