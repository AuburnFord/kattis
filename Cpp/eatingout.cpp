#include <iostream>
using namespace std;

int main() {
	int m, a, b ,c;
	cin >> m >> a >> b >> c;
	cout << (2*m-a-b>=c ? "possible" : "impossible") << "\n";
	return 0;
}
