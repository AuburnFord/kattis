#include <iostream>
using namespace std;

int main() {
	int cases,beats;
	double sec;
	cin >> cases;
	while(cases--) {
		cin >> beats >> sec;
		printf("%f %f %f\n", 60*beats/sec-60/sec, 60*beats/sec, 60*beats/sec+60/sec);	
	}		
	return 0;
}
