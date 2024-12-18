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

void printResult(bool isHaikuValid) {
    cout << (isHaikuValid ? "Yes" : "No");
}

bool isHaikuPattern(short syllableCounts[]) {
    short haikuPattern[]{5, 7, 5};
    bool isMatched[3]{};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (!isMatched[j]) {
                if (haikuPattern[j] == syllableCounts[i]) {
                    isMatched[j] = true;
                    break;
                }
            }
        }
    }
    for (bool match : isMatched) {
        if (!match) {
            return false;
        }
    }
    return true;
}

void inputSyllables(short syllableCounts[]) {
    for (int i = 0; i < 3; i++) {
        do {
            cout << "Enter the number of syllables for phrase " << i + 1 << ": ";
            cin >> syllableCounts[i];
        } while (syllableCounts[i] > 9 || syllableCounts[i] < 1);
    }
}

int main() {
    short syllableCounts[3]{};
    inputSyllables(syllableCounts);
    printResult(isHaikuPattern(syllableCounts));
    return 0;
}
