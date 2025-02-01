/*
Smith Number Problem Statement:

A Smith number is a composite number, the sum of whose digits is the sum of the digits of its prime factors obtained as a result of prime factorization (excluding 1). The first few such numbers are 4, 22, 27, 58, 85, 94, and 121.

Example:
378 = 2 × 3 × 3 × 3 × 7
So, its prime factors are 2, 3, 3, 3, and 7.
The sum of its digits is (3 + 7 + 8) = 18.
The sum of the digits of its factors is (2 + 3 + 3 + 3 + 7) = 18.

Similarly, 4,937,775 is a Smith number.

4,937,775 = 3 × 5 × 5 × 65837, and the sum of its digits is the same as the sum of the digits of its prime factors:
4 + 9 + 3 + 7 + 7 + 7 + 5 = 3 + 5 + 5 + 6 + 5 + 8 + 3 + 7 = 42.

Task:
Write a program to check whether a given integer is a Smith number.

Input Format:
There will be only one line of input: N, the number which needs to be checked.

Constraints:
0 < N < 2,147,483,647 (max value of an integer of the size of 4 bytes)

*/

// Question link :: https://www.hackerrank.com/challenges/identify-smith-numbers/problem

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int isPrime(int devid, int num) {
    for (int i{devid}; i < sqrt(num); i++) {
        if (num % i == 0) {
            return devid;
        }
    }
    return num;
}

short sumDigit(int devid) {
    short sum{};
    while (devid > 0) {
        sum += devid % 10;
        devid /= 10;
    }

    return sum;
}

short sumNumber(int num) {
    int devid{ 2 };
    short sum{};
    while (num > 1) {
        if (num % devid == 0) {
            sum += sumDigit(devid);
            num /= devid;
        }
        else {
            devid++;
            devid = isPrime(devid, num);
        }
    }
    
    return sum;
}

bool isEqual(short sumDevid, short sumDigit) {
    return sumDevid == sumDigit;
}

int inputNum() {
    int num{};
    
    while (!(cin >> num) || (num < 0 || num >= numeric_limits<int>::max())) {
    	cin.clear();
    	cin.ignore();
    }

    return num;
}

int main() {
    int num{ inputNum() };
    cout << isEqual(sumNumber(num), sumDigit(num));

    return 0;
}
