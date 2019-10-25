#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

void fastint(int& num) {
	int c = getchar();
	num = 0;
	for(; c > 47 && c < 58; c = getchar()) num = num * 10 + c - '0';
}

int main() {
	int fishies, buyers;
	fastint(fishies);
	fastint(buyers);
	vector<int> fish(fishies,0);
	for(int x = 0; x < fishies; x++) {
		fastint(fish[x]);
	}
	map<int, int> buyer;
	for(int x = 0; x < buyers; x++) {
		int quan, price;
		fastint(quan);
		fastint(price);
		buyer[price] += quan;
	}
	sort(fish.begin(), fish.end(), greater<int>());
	int idx = 0;
	long price = 0;
	auto it = buyer.rbegin();
	while(idx < fishies && buyer.rend() != it) {
		price += (long)it->first * fish[idx];
//		cout << it->first << " " << fish[idx] << endl;
		it->second--;
		idx++;
		if(it->second==0) it++;
	}
	cout << price << endl;
//	printf("%.0lf\n",price);
}
