#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int hashFunc(const string& c) {
    char a = c[0];
    for(int i = 1; i < c.size(); i++) {
        a ^= c[i];
    }
    return int(a);
}

int main() {
    int cases;
    cin >> cases;
	getchar();
    string out = "";
    while(cases) {
		unordered_map<string,int> mem;	
		unordered_map<string,int> hashed;	
		while(cases--) {
			string temp;
			getline(cin,temp);
			mem[temp]++;
			hashed[temp] = hashFunc(temp);	
		}
		int collisions = 0;
		for(unordered_map<string,int>::iterator it = mem.begin(); it!=mem.end(); it++) {
			for(unordered_map<string,int>::iterator itI = it; itI!=mem.end(); itI++) {
				if(itI==it) continue;
				if(hashed[it->first] == hashed[itI->first]) {
					collisions += it->second*itI->second;
				}
			}
		}
//		for(unordered_map<string,int>::iterator it = mem.begin(); it!=mem.end(); it++)
//			cout << it->first << " " << it->second << endl;
		out+= to_string(mem.size()) + " " + to_string(collisions) + "\n";
        cin >> cases;
		getchar();
    }
    cout << out;
    return 0;
}
