#include <iostream>
#include <unordered_map>
using namespace std;

string find(string child, unordered_map<string,string>* friends) {
	// find the top parent of the given person, and compress the path
	//base case: child is own parent
	if (child==(*friends)[child]) return child;
	// return the top parent, and update the child's parent
	return (*friends)[child] = find((*friends)[child], friends); 
}

void unionF(string f1, string f2, unordered_map<string,string>* friends, unordered_map<string,int>* nums) {
	// union the two groups and update the num in each
	// check if in the same group, important for keeping track of nums
	if((*friends)[find(f1,friends)]==(*friends)[find(f2,friends)]) return;
	// the friends are in non-overlapping groups, the new size is sum of size of each group
	int num = (*nums)[find(f1,friends)] + (*nums)[find(f2,friends)];
	// we update the top parent, this implementation is setting the top parent of f1 as child of f2
	(*friends)[find(f1,friends)] = (*friends)[find(f2,friends)];
	// at this point f1 and f2 have same top level parent, need to update that parent with new size
	(*nums)[find(f1,friends)] = num;	 
}

int main() {
	int cases;
	cin >> cases;
	while (cases) {
		int numFriend;
		cin >> numFriend;	
		unordered_map<string,string> friends;
		unordered_map<string,int> nums;
		while(numFriend) {
			string f1, f2;	
			cin >> f1 >> f2;
			if(friends.find(f1)==friends.end()) {
				//if they arent in a network, make them their own
				friends[f1]=f1;	
				nums[f1]=1;
			}
			if(friends.find(f2)==friends.end()) {
				//if they arent in a network, make them their own
				friends[f2]=f2;	
				nums[f2]=1;
			}
			unionF(f1,f2,&friends,&nums);
			cout << nums[find(f1,&friends)] << "\n";	

			numFriend--;
		}
		cases--;
	}	
	return 0;
}
