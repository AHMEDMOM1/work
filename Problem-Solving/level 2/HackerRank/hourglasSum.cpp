/*Function Description
Complete the function hourglassSum in the editor below.
hourglassSum has the following parameter(s):

int arr[6][6]: an array of integers.
Returns

int: the maximum hourglass sum.
Input Format
Each of the 6 lines of inputs arr[i] contains 6 space-separated integers arr[i][j].

Constraints

−9 ≤ arr[i][j] ≤ 9
0 ≤ i, j ≤ 5
Output Format
Print the largest (maximum) hourglass sum found in arr.

Sample Input
1 1 1 0 0 0  
0 1 0 0 0 0  
1 1 1 0 0 0  
0 0 2 4 4 0  
0 0 0 2 0 0  
0 0 1 2 4 0  

Sample Output
19

// Question link : https://www.hackerrank.com/challenges/2d-array/problem

*/

#include <iostream>
#include <limits.h> 
using namespace std;


int findMaxHourglassSum(int matrix[][100], int numRows, int numCols) {
    int maxSum = INT_MIN; 
    int currentSum = 0;   

    for (int startRow = 0; startRow < numRows - 2; startRow++) {
        for (int startCol = 0; startCol < numCols - 2; startCol++) {
            for (int row = startRow; row < (startRow + 3); row++) {
                for (int col = startCol; col < (startCol + 3); col++) {
                    
                    if (row == startRow + 1) { 
                        col = startCol + 1; 
                        currentSum += matrix[row][col]; 
                        break; 
                    } 
                    else { 
                        currentSum += matrix[row][col]; 
                    }
                }
            }
            
            if (currentSum > maxSum) { 
                maxSum = currentSum; 
            }
            currentSum = 0; 
        }
    }

    return maxSum;
}


void inputMatrix(int matrix[][100], int& numRows, int& numCols) {
    cout << "Enter number of rows: ";
    cin >> numRows;

    cout << "Enter number of columns: ";
    cin >> numCols;

    for (int row = 0; row < numRows; row++) {
        for (int col = 0; col < numCols; col++) {
            cout << "[" << row + 1 << "," << col + 1 << "]: ";
            cin >> matrix[row][col];
        }
    }
}

int main() {
    int matrix[100][100] = {}; 
    int numRows, numCols;

    inputMatrix(matrix, numRows, numCols); 
    int maxHourglassSum = findMaxHourglassSum(matrix, numRows, numCols); 

   
    cout << "The largest hourglass sum is: " << maxHourglassSum << endl;

    return 0;
}
