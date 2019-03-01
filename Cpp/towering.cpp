#include <iostream>
#include <set>
using namespace std;

int main() {
	int box[6];
	bool boxs[6];
	for (int i = 0; i < 6; i++) {
		cin >> box[i];
		boxs[i] =true;	
	}
	int h1, h2;
	
	cin >> h1 >> h2;
	for (int i = 0; i < 4; i++) {
		for (int j = i+1; j < 5; j++) {
			for (int k = j + 1; k < 6; k++) {
				if (h1 == box[i] + box[j] + box[k]) {
					set<int> ids;
					set<int> b1;
					set<int> b2;
					ids.insert(i);
					b1.insert(box[i]);
					ids.insert(j);
					b1.insert(box[j]);
					ids.insert(k);
					b1.insert(box[k]);
					int other =0;
					for (int l = 0; l < 6; l++) {
						if(ids.find(l)==ids.end()) {
							other += box[l];
							b2.insert(box[l]);
						}
					}
					if (other == h2) {
						for (set<int>::reverse_iterator it = b1.rbegin(); it!=b1.rend(); it++) {
							cout << *it << " "; 
						}
						for (set<int>::reverse_iterator it = b2.rbegin(); it!=b2.rend(); it++) {
							cout << *it << " "; 
						}
						cout << endl;
					}
				}
			}
		}
	}					 
	return 0;
}
