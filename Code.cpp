/*Problem Statement
Iroha is very particular about numbers. There are 
K digits that she dislikes: D1,D 2,...,DK
She is shopping, and now paying at the cashier. Her total is 
N yen (the currency of Japan), thus she has to hand at least 
N yen to the cashier (and possibly receive the change).
However, as mentioned before, she is very particular about numbers. When she hands money to the cashier,
the decimal notation of the amount must not contain any digits that she dislikes. Under this condition,
she will hand the minimum amount of money.
Find the amount of money that she will hand to the cashier.
Constraints
1≦N<10000
1≦K<10
0≦D 
{D1,D2,...,DK} != {1,2,3,4,5,6,7,8,9}
Code |
     v
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printSum(vector <short> total) {
	if (total.at(0) == 0) {
		for (unsigned int i{1}; i < total.size(); i++) {
			cout << total.at(i);
		}

	}
	else {
		for (unsigned short sh : total) {
			cout << sh;
		}
	}
}

vector <short> totaMoney(int total, vector <short>& numbers) {
	int sum{}, totalSize{}, num{};
	bool ok{}, lastNumber{};
	for (unsigned int sz{ 1 }; sz <= total;sz *= 10) { // 1999
		++totalSize;
		
	}
	vector <short> tot(totalSize + 1);
	vector <short>::iterator start{ numbers.begin() };
	

	for (int i = totalSize; i >= 0; i--) {
		num = total % 10;
		tot.at(i) = num;
		total /= 10;
	}

	vector<short>::iterator totStart{ tot.begin() + 1 };

	
	for (; totStart < tot.end();) {
		while (start < numbers.end()) {
			if (*totStart == *start) { //  0000 9
				ok = true;
				totStart++;
				break;
			}
			else {
				start++;
			}
		}
		if (!ok) {
			if (*totStart == 9) {
				++(*(totStart - 1));
				totStart--;
			}
			else {
				++(*totStart);
			}
			lastNumber = true;
		}
		else if(lastNumber){
			while (totStart < tot.end()) {
				*(totStart) = numbers.front();
				totStart++;
			}
		}
		start = numbers.begin();
		ok = false;
	}

	return tot;
}

vector <short>  checkNotHeatNums(int& total, int& K, vector <short>& inptVc) {
	vector <short> numbers{ 0,1,2,3,4,5,6,7,8,9 };


	for (unsigned int i{}; i < inptVc.size(); i++) {
		if (i == inptVc.size() - 1 && inptVc.at(i) == 0) { numbers.erase(numbers.begin()); }

		else {
			numbers.erase(numbers.begin() + (inptVc.at(i) - i));
		}
	}



	return totaMoney(total,numbers);
}

vector <short> inputNumbers() {
	int total{}, K{};

	cout << "How much will you pay: ";
	cin >> total;

	cout << "How many numbers do you hate: ";
	cin >> K;

	vector <short> sht(K);

	for (unsigned int i{}; i < sht.size(); i++) {
		cout << "The " << i + 1 << ". Number is: ";
		cin >> sht.at(i);
	}
	sort(sht.begin(), sht.end());
	return checkNotHeatNums(total, K, sht);
}

int main() {
	printSum(inputNumbers());
	
	return 0;
}
