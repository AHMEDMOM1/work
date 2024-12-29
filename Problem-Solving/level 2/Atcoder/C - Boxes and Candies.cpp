/*
Problem Statement
There are N boxes arranged in a row. Initially, the i-th box from the left contains aicandies.
Snuke can perform the following operation any number of times:
Choose a box containing at least one candy, and eat one of the candies in the chosen box.
His objective is as follows:

Any two neighboring boxes contain at most x candies in total.
Find the minimum number of operations required to achieve the objective.

Constraints
2≤N≤10^5
0≤ai≤10^9
0≤x≤10^9
 
Input
The input is given from Standard Input in the following format:

N x
a1 a2 .. aN​
 
Output
Print the minimum number of operations required to achieve the objective.
*/

// ***Link of question*** : https://atcoder.jp/contests/arc064/tasks/arc064_a



/////     ******************************    \\\\\\




void prntSmEtngAple(int totalApple, vector <int>& applesInbox) {
	cout << "Still apple in boxes is: { ";
	for (size_t i{}; i < applesInbox.size(); i++) {	
		cout << applesInbox.at(i);
		if (i != applesInbox.size() - 1) {
			cout << ", ";
		}
	}cout << " }" << endl;
	cout << "Your eating apple is: " << totalApple << endl;
}

int totalMaxtAmountApple(vector <int>& applesInbox, int& x) {
	int amntOfsub{}, subRes{}, totalApple{};
	for (size_t i{}; i < applesInbox.size() - 1; i++) {
		amntOfsub = max((applesInbox.at(i) + applesInbox.at(i + 1)) - x, 0);
		totalApple += amntOfsub;
		subRes = max(applesInbox.at(i) - x, 0);
		applesInbox.at(i) -= subRes;
		amntOfsub -= subRes;
		applesInbox.at(i + 1) -= amntOfsub;
	}

	return totalApple;
}

/* // Solve in another way
int totalMaxtAmountApple(vector <int> applesInbox, int& x) {
	int result{};
	for (int sh : applesInbox) {
		result += sh;
	}
	return result -= x * ceil((double)applesInbox.size() / 2);
}
*/

vector <int> inputAppleNumber(int& N, int& x) {
	do {
		cout << "N: ";
		cin >> N;
	} while (N < 2 || N > pow(10, 5));

	do {
		cout << "X : ";
		cin >> x;
	} while (x < 0 || x > pow(10, 9));
	vector <int> applesInbox(N);
	for (size_t i{}; i < applesInbox.size(); i++) {
		cout << "[" << i + 1 << "]: ";
		do {
			cin >> applesInbox.at(i);
		} while (applesInbox.at(i) < 0 || applesInbox.at(i) > pow(10, 9));
	/* // Add it with the other solution
 	if (applesInbox.at(i) == 0) {
	    applesInbox.erase(applesInbox.begin() + i);
	    --i;
  	}
 	*/
	}
	return applesInbox;

}

int main() {
	int N{}, x{};
	vector <int> applesInbox{ inputAppleNumber(N, x) };
	prntSmEtngAple(totalMaxtAmountApple(applesInbox, x), applesInbox);


	return 0;
}
