#include <iostream>
#include <unordered_set>
using namespace std;

int find(int loc, int* unions) {
	if (loc == unions[loc]) return loc; // The road is its own parent
	unions[loc] = find(unions[loc], unions); // Recursively find the parent, and update (path compression)
	return unions[loc];
}

void unions(int loc1, int loc2, int* unions) {
	unions[find(loc2, unions)] = find(loc1, unions); // Set loc2's parent as child of loc1's parent
}	

int main() {
	int cases;
	cin >> cases;
	int* unionArray;	
	int numEndp;
	int roads;
	while (cases > 0) {
		unordered_set<int> groups;
		cin >> numEndp;
		unionArray = new int[numEndp];
		for (int i = 0; i < numEndp; i++) {
			unionArray[i] = i;
		}
		cin >> roads;
		for (int i =0; i < roads; i++) {
			int a, b;
			cin >> a >> b;
			unions(a,b,unionArray);	
		}
		for (int i = 0; i < numEndp; i++) {
			find(i, unionArray);
			groups.insert(unionArray[i]);
		}
		cout << groups.size() - 1 << endl;
		delete [] unionArray;
		unionArray = NULL;
		cases--;
	}
	return 0;
}
