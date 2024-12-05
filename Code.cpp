#include <iostream>  
#include <vector>  

using namespace std;

void printSum(vector <short> total) {
    if (total.at(0) == 0) {
        for (int i{1}; i < total.size(); i++) {
            cout << total.at(i);
        }

    }
    else {
        for (short sh : total) {
            cout << sh;
        }
    }
}

vector <short> totaMoney(int total, vector <short>& numbers) {
    int sum{}, totalSize{}, num{};
    bool ok{};
    for (int sz{ 1 }; sz <= total;) { // 1999
        totalSize++;
        sz *= 10;
    }
    vector <short> tot(totalSize + 1);
    vector <short>::iterator start{ numbers.begin() };

    int result{ total };

    for (int i{ totalSize }; i >= 0; i--) {
        num = total % 10;
        tot.at(i) = num;
        total /= 10;
    }


    for (int i{1}; i < tot.size();) { // 09999 9837 8999 9101 9000 9111
        while (start < numbers.end()) { // 012345678
            if (tot.at(i) == 9) {
                ++tot.at(i - 1);
                while (i < tot.size()) { tot.at(i) = 0; i++; }
                return tot;
            }
            else if (tot.at(i) == *start) {
                tot.at(i) = *start;
                ok = true;
                i++;
                break;
            }
            else {
                start++;
            }
        }
        if (!ok) { tot.at(i)++; }
        start = numbers.begin();
        ok = false;
    } 

    return tot;
}

vector <short>  checkNotHeatNums(int& total, int& K, vector <short>& inptVc) {
    vector <short> numbers{ 0,1,2,3,4,5,6,7,8,9 }; 


    for (int i{}; i < inptVc.size(); i++) { 
        if (i == inptVc.size() - 1 && inptVc.at(i) == 0) { numbers.erase(numbers.begin()); cout << "testif" << i << endl; }

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

    for (int i{}; i < sht.size(); i++) {
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