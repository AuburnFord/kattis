#include <iostream>
using namespace std;

int main(){
	int cases;
	cin >> cases;
	int count = 0, temp;
	while(cases>0){
		cin >> temp;
		if(temp < 0) count++;
		cases--;
	}
	cout << count << endl;
	return 0;
}
