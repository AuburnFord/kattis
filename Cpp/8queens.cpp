#include <iostream>
using namespace std;

int main() {
	bool col[8] = {};
	bool row[8] = {};
	bool lDiag[15] = {};
	bool rDiag[15] = {};
	int queens = 0;
	int x,y;
	x = y = 0;
	char c;
	while(cin >> c) {
		if(c == '*') {
			queens++;
			if(!col[x] && !row[y] && !lDiag[x+y] && !rDiag[7+x-y]) {
				col[x] = true;
				row[y] = true;
				lDiag[x+y] = true;
				rDiag[7+x-y] = true;
			} else {
				cout << "invalid\n";
				return 0;
			}
		}
		x++;
		if(x==8) {
			y++;
			x = 0;
		}	
	}
	if (queens != 8) cout << "invalid\n";
	else cout << "valid\n";
	return 0;
}
