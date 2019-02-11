#include <iostream>
#include <vector>

using namespace std;

void mkPath(vector<int>*& vec, int val);

int main() {
	int a, b, val;
	a = 837799;
	b = 1;
	vector<int>* aV;
	vector<int>* bV;
	while (a!=0 && b!=0) {
		aV = new vector<int>;
		bV = new vector<int>;
		mkPath(aV, a);
		mkPath(bV, b);
		while (!aV->empty() && !bV->empty() && aV->back() == bV->back()) {
			val = aV->back();
			aV->pop_back();
			bV->pop_back();
		}
		cout << a << " needs " << aV->size() << " steps, " << b << " needs " << bV->size() << " steps, they meet at " << val << endl;
		delete aV;
		delete bV;
		aV = NULL;
		bV = NULL;
	}
	return 0;
}

void mkPath(vector<int>*& vec, int val) {
	while(val > 1) {
		vec->push_back(val);
		if (val % 2 == 0) {
			val /= 2;
		} else {
			val = 3 * val + 1;
		}
	}
	vec->push_back(1);
}
