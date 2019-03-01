#include <iostream>
#include <bits/stdc++.h>
//#include <vector>
//#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int cases;
	//vector<int>orig;
	//vector<int>sorted;
	cin >> cases;
	while(cases) {
		int nums;
		cin >> nums;
		int next;
		int target = 1;
		int count=0;
		for (int i = 0; i < nums; i++) {
			cin >> next;
			if(next!=target) count++;
			else target++;	
		}
//		int temp;
//		for(int i = 0; i <nums; i++) {
//			cin >> temp;
//			orig.push_back(temp);
//			sorted.push_back(temp);
//		}
//		sort(sorted.begin(),sorted.end());
//		int count = 0;
//		int j =0;
//		for(int i = 0; i <nums; i++) {
//			if(orig[i]!=sorted[j]) count++;
//			else j++;	
//		}	
		cout << count << "\n";	
//		orig.clear();
//		sorted.clear();
		cases--;
	}
	return 0;
}
