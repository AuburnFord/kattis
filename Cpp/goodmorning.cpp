#include <iostream>
#include <string>
using namespace std;

bool poss(string d, bool cases[]) {
	if (d.length() == 1) return true;
	bool flag = true;
	for (int i = 0; i < d.length()-1 && flag; i++) {
		flag = cases[(d[i]&0xF) * 10 + (d[i+1]&0xF)]; // Bitwise operations happen after arithmetic
	}
	return flag;
}

int best(int d, bool cases[]) {
	if (poss(to_string(d), cases)) return d;	
	for (int i = 1; i > 0; i++) {
		if(poss(to_string(d+i), cases)) return d+i; 
		if(poss(to_string(d-i), cases)) return d-i; 
	}
	return 0;
}

int main() {
	int cases;
	cin >> cases;
	bool nums[100] = {
		true ,false,false,false,false,false,false,false,false,false,
		true ,true ,true ,true ,true ,true ,true ,true ,true ,true,
		true ,false,true ,true ,false,true ,true ,false,true ,true,
		false,false,false,true ,false,false,true ,false,false,true,
		true ,false,false,false,true ,true ,true ,true ,true ,true, 
		true ,false,false,false,false,true ,true ,false,true ,true,
		false,false,false,false,false,false,true ,false,false,true,
		true ,false,false,false,false,false,false,true ,true ,true,
		true ,false,false,false,false,false,false,false,true ,true,
		false,false,false,false,false,false,false,false,false,true};
	while (cases > 0) {
		int desired;
		cin >> desired;
		cout << best(desired, nums) << endl;	
		cases--;
	}
	return 0;
}
