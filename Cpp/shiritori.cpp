#include <bits/stdc++.h>
#include <iostream>
#include <unordered_set>
using namespace std;

const bool PLAYER_1 = true;
const bool PLAYER_2 = false;

int main() {
	int turns;
	cin >> turns;
	string word;
	turns--;
	cin >> word;
	unordered_set<string> seen;	
	seen.insert(word);
	char lastChar = word[word.length()-1];
	bool player = PLAYER_2;
	bool failed = false;
	while (turns--) {
		cin >> word;
		if (seen.count(word) || word[0] != lastChar) {
			failed = true;
			break;
		} else {
			lastChar = word[word.length()-1];
			seen.insert(word);
			player = !player;
		}
	}
	if (failed) {
		cout << (player ? "Player 1 lost" : "Player 2 lost") << endl;
	} else {
		cout << "Fair Game" << endl;
	}
	return 0;
}
