#include <iostream>
#include <algorithm>
using namespace std;

void fastint(int& num) {
	int c = getchar();
	num = 0;
	for(; c>47 && c<58; c=getchar()) num = num*10 + c - '0';
}

int main() {
	int cases;
	fastint(cases);
	string out = "";
	while(cases--) {
		int case_num, length;
		fastint(case_num);
		fastint(length);
		int* arr;
		int* arr_sort;
		arr = new int[length];
		arr_sort = new int[length];
		for(int i = 0; i < length; i++) {
			int temp;
			fastint(temp);
			arr[i] = temp;
			arr_sort[i] = temp;
		}
		sort(arr_sort,arr_sort+length);
		int count = 0;
		int sort_idx = 0;
		for(int i = 0; i < length; i++) {
			if(arr[i]==arr_sort[sort_idx]) {
				sort_idx++;
			} else
				count++;
		}	
		out += to_string(case_num) + " " + to_string(count) + "\n";
	}
	cout << out;
	return 0;
}
