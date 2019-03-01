#include <iostream>
using namespace std;

int main() {
	int kl, l;
	char* a;
	char* b;
	cin >> kl >> l;
	a = new char[l];
	b = new char[l];
	for (int i = 0; i < kl; i++) {
		cin >> a[l-kl+i];
	}
	cin >> b;
	for (int i = l-1; i >= kl; i--) {
		// 0x61 'a'
		// 0x7a 'z'
		//a = b-k	
		//k ( kl + i ) = ai
		a[i-kl] = ((b[i]-0x61)-(a[i]-0x61) >=0 ? (b[i]-0x61)-(a[i]-0x61) : (b[i]-0x61)-(a[i]-0x61)+26) + 0x61;
	}
	cout << a << endl;
	return 0;
}
