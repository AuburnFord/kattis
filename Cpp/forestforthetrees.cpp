#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	long x,y;
	cin >> x >> y;
	// num of trees in between
	long div = __gcd(x,y);
	long x1,y1,x2,y2;
	cin >> x1 >> y1 >> x2 >> y2;
	if(div==1) {
		cout << "Yes\n";
		return 0;
	}
	
	long long x_mul = x/div;
	long long y_mul = y/div;

	// line hits left side
	long left = -1;
	if(y_mul * x1 >= y1 * x_mul && y_mul * x1 <= y2 * x_mul) {
		left = x1/x_mul;
		if(x1%x_mul==0) {//crit point on border
			left--;
		}
	}
	if(y_mul * x2 >= y1 * x_mul && y_mul * x1 < y1 * x_mul) {
		left = y1/y_mul;
		if(y1%y_mul==0)
			left--;
	}
	// calc exit
	long right = left;
	if(y_mul * x1 <= y2 * x_mul && y_mul * x2 >= y2 * x_mul) {
		right = y2/y_mul;
	}
	if(y_mul * x2 >= y1 * x_mul && y_mul * x2 < y2 * x_mul) {
		right = x2/x_mul;
	}
//	cout << "Debug:\nx_mul: " << x_mul << " y_mul: " << y_mul << endl;
//	cout << "left: " << left << " right: " << right << endl;
//	cout << "div: " << div << endl;
	if(left == 0) {
		if(div - 1 <= right)
			cout << "Yes\n";
		else
			cout << "No\n" << x_mul * (right+1) << " " << y_mul * (right+1) << "\n";
	} else
		cout << "No\n" << x_mul << " " << y_mul << "\n";
	return 0;
}
