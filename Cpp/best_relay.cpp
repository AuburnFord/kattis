#include <iostream>
#include <map>

using namespace std;

map<string, double>l1;
map<string, double>l2;

int main() {
	int n;
	cin >> n;
	string name;
	double first;
	double second;
	double bestT = 90;
	pair<string,double> best[4];	
	pair<string, double> times[4];
	while(n-->0) {
		cin >> name >> first >> second;
		l1[name] = first;
		l2[name] = second;	
	}
	map<string,double>::iterator i,j;
	i = l1.begin();
	while (i!=l1.end()) {
		times[3].second = 20;
		times[2].second = 20;
		times[1].second = 20;
		times[0]=*i;
		j = l2.begin();
		while(j!=l2.end()) {
			if(j->first != i->first) {
				if(j->second < times[1].second) {
					times[3]=times[2];
					times[2]=times[1];
					times[1]=*j;
				} else if(j->second < times[2].second) {
					times[3]=times[2];
					times[2]=*j;
				} else if(j->second < times[3].second) {
					times[3]=*j;
				}
			}
			j++;
		}
		if(times[0].second+times[1].second+times[2].second+times[3].second < bestT) {
			best[0]=times[0];
			best[1]=times[1];	
			best[2]=times[2];
			best[3]=times[3];	
			bestT = best[0].second+best[1].second+best[2].second+best[3].second;
		}
		i++;
		
	}
	cout << bestT << endl << best[0].first << endl << best[1].first << endl << best[2].first << endl << best[3].first << endl;
	return 0;
}
