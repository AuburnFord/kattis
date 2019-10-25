#include <iostream>
using namespace std;

void fastint(int& num) {
	int c = getchar();
	num = 0;
	for(; c>47 && c<58; c= getchar()) num = num * 10 + c - '0';
}

int findF(int x, int* arr) {
	if(arr[x] == x)
		return x;
	arr[x] = findF(arr[x],arr);
	return arr[x];
}

void unionF(int x, int y, int* arr) {
	arr[findF(x,arr)] = findF(y,arr);
}

int main() {
	int len, con;
	fastint(len);
	fastint(con);
	int* arr = new int[len+1];
	for(int i = 1; i < len+1; i++)
		arr[i] = i;	
	for(int i = 0; i < con; i++) {
		int x,y;
		fastint(x);
		fastint(y);
		unionF(x,y,arr);
	}
	int a = 1, b = len;
	bool flag = true;
	while(a < b && flag) {
		if(findF(a,arr) != findF(b,arr))
			flag = false;
		a += 1;
		b -= 1;
	}
	if(flag)
		cout << "Yes\n";
	else
		cout << "No\n";	
	
	return 0;
}
