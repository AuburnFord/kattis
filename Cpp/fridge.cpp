#include <iostream>
using namespace std;

int main() {
	int nums[10] = {};
	char num;
	num = getchar();
	while(num>='0') {
		nums[num-'0'] += 1;	
		num = getchar();
	}
	string out = "";
	int pos = -1;
	int min = 1001;

	for(int i = 1; i < 10; i++) {
		if(nums[i]<min) {
			min = nums[i];
			pos = i;
		}
	} 
	if(nums[pos]>nums[0]) {
		out+='1';
		pos=0;
	}
	for(int i = 0; i <= nums[pos]; i++) {
		out+=(pos+48);
	}
	cout << out << "\n";
	return 0;
}
