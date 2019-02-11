#include <iostream>
using namespace std;

int main() {
	int num;
	cin >> num;
	int * arr;
	arr = new int [num+1];
	int lo, hi;
	for (int i = 1; i <num+1; i++) {
		cin >> lo >> hi;
		for (int j = lo; j <=hi; j++) {
			arr[j] = arr[j]+1;
		}
	}	
	int max = -1;
	for (int i = 0; i<num+1; i++) {
		if (i == arr[i]) max = i;
	}
	cout << max << endl;
	return 1;
}
