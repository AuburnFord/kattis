#include <iostream>
#include <math.h>
using namespace std;

double dist(int x1, int y1, int x2, int y2) {
	return sqrt(pow(x1-x2,2) + pow(y1-y2,2)); 
}

int main() {
	int gx,gy,x1,y1,x2,y2;
	cin >> gx >> gy >> x1 >> y1 >> x2 >> y2;
	if (gx < x1) { // left of house
		if (gy < y1) { // under house
			cout << dist(gx,gy,x1,y1) << endl;	
		} else if (gy > y2) { // above house
			cout << dist(gx,gy,x1,y2) << endl;	
		} else { // in line with house
			cout << x1-gx << endl;	
		}
	} else if (gx > x2) { // right of house
		if (gy < y1) { // under house
			cout << dist(gx,gy,x2,y1) << endl;	
		} else if (gy > y2) { // above house
			cout << dist(gx,gy,x2,y2) << endl;	
		} else { // in line with house
			cout << gx-x2 << endl;	
		}
	} else { // btw x1 and x2
		if (gy < y1) { // under house
			cout << y1-gy << endl;	
		} else { // above house
			cout << gy-y2 << endl;	
		}	
	}
	return 0;
}
