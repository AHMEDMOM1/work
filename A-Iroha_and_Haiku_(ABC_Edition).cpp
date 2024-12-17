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

Sample Input 2
7 7 5

Sample Output 2
NO

*/

#include <iostream>

using namespace std;

void printyesOrNo(bool isThereHaiku) {
	cout << (isThereHaiku ? "YES" : "NO");
}

bool isHaiku(short phrase[]) {
	short Haiku[]{ 5,7,5 };
	bool ok[3]{};
	for (int i{}; i < 3; i++) {
		for (int j{}; j < 3; j++) {
			if (!ok[j]) {
				if ( Haiku[j] == phrase[i] ) {
					ok[j] = true; break;
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
	short A{}, B{}, C{};
	do{
	  cin >> A >> B >> C;
	} while(( A < 1 || A > 10) || (B < 1 || B > 10) || C < 1 || C > 10);
	
	short phrase[3]{A,B,C};

	printyesOrNo(isHaiku(phrase));
}

int main() {
	inputPhrase();
	

	return 0;
}
