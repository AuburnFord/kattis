#include <iostream>
using namespace std;

int main() {
	int cases;
	cin >> cases;
	while (cases > 0) {
		cases--;
		int pilots, cities;
		cin >> cities >> pilots;
		int a, b;
		for (int i = 0; i < pilots; i++) {
			cin >> a >> b;	
		}
		cout << cities-1 << endl;
	}	
	return 0;
}
