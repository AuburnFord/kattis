#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
	int courses, cats;
	while (cin >> courses >> cats) {
		vector<int> reg;
		bool pass = true;
		for (int i = 0; i < courses; i++) {
			int temp;
			cin >> temp;
			reg.push_back(temp);	
		}
		for (int i = 0; i < cats; i++) {
			set<int> need;
			int req;
			int num;
			cin >> num >> req;	
			for (int j = 0; j < num; j++) {
				int temp;
				cin >> temp;
				need.insert(temp);
			}
			for (int j = 0; pass && j < courses; j++) {
				if(need.find(reg[j])!=need.end()) req--;
			}
			if(req > 0) pass = false;
		}
		if(pass) cout << "yes" << endl;
		else cout << "no" << endl;
	}
	return 0;
}
