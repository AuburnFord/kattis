#include <iostream>
using namespace std;
int main() {
	int val = 837799;
	int count = 0;
	while (val != 1 && val > 0) {
		if (count % 10 == 0) cout << "\n" << count << ": ";
		count++;
		cout << val << " ";
		if(val%2 == 0) {
			val/=2;
		} else {
			val = val*3 +1;
		}	
	}
	return 0;
}
