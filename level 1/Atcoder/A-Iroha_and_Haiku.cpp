/*
Problem Statement
Iroha loves Haiku. Haiku is a short form of Japanese poetry. A Haiku consists of three phrases with 5, 7 and 5 syllables, in this order.

To create a Haiku, Iroha has come up with three different phrases. These phrases have A, B and C syllables, respectively. 
Determine whether she can construct a Haiku by using each of the phrases once, in some order.

Constraints
1≦A,B,C≦10

Input
The input is given from Standard Input in the following format:
A B C

Output
If it is possible to construct a Haiku by using each of the phrases once, print YES (case-sensitive). Otherwise, print NO.

Sample Input 1
5 5 7

Sample Output 1
YES
Using three phrases of length 5, 5 and 7, it is possible to construct a Haiku.

*/

void printyesOrNo(bool isThereHaiku) {
	cout << (isThereHaiku ? "Yes" : "No");
}

bool isHaiku(vector <short> phrase) {
	vector<short>haiku{ 5, 7, 5 };
	vector <bool> ok(haiku.size());
	for (int i{}; i < phrase.size(); i++) {
		for (int j{}; j < haiku.size(); j++) {
			if (!ok.at(j)) {
				if ( haiku.at(j) == phrase.at(i) ) {
					ok.at(j) = true; break;
				}
			}
		}
	}
	for (bool checkFalse : ok) {
		if (checkFalse == false) { return 0; };
	}

	return 1;
}

void inputPhrase() {
	vector<short>syllable(3);
	
	for (size_t i{}; i < syllable.size(); i++) {
		do {
			cout << "Enter " << i + 1 << ".Syllable: ";
			cin >> syllable.at(i);
		} while (syllable.at(i) < 1 || syllable.at(i) > 9);
	}
	printyesOrNo(isHaiku(syllable));
}

int main() {
	inputPhrase();
	

	return 0;
}

