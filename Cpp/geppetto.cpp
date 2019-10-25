#include <iostream>
#include <unordered_set>
#include <cmath>

using namespace std;

int main() {
	int n,m;
	cin >> n >> m;
//	cout << n << " " << m << endl;
	unordered_set<int> restrictions;
	for(int i = 0; i < m; i++) {
		int x,y;
		cin >> x >> y;
		restrictions.insert(x>y ? y*100+x : x*100+y);
	}
//	for(auto it = restrictions.begin(); it != restrictions.end(); it++) {
//		cout << *it << " ";	
//	}
//	cout << endl;
	int num = 0;
	int count = 0;
	int upper = (int) pow(2,n);
	while (num < upper) {
		auto it = restrictions.begin();
		while(it!=restrictions.end()) {
			if((num>>(*it/100-1)&1) && (num>>(*it%100-1)&1)) {
//				cout << "Break at: "<< num << endl;
				break;
			}	
			it++;
		}
		if(it==restrictions.end()) {
//			cout << "Add 1 at: " << num << endl;
			count++;
		}
		num++;
	}	
	cout << count << endl;
	return 0;
}
