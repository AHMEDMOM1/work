// question link : https://atcoder.jp/contests/arc075/tasks/arc075_a

int findSmallestAdjustment(const vector<int>& scores) {
	auto it = find_if(scores.begin(), scores.end(), [](int score) { return score % 10 != 0; });
	return (it != scores.end()) ? *it : 0; // Return 0 if no valid score exists
}

bool isMultiOfTen(int totalMark) {
	return totalMark % 10 == 0;
}

int retResult(int totalMarks, int smallestAdjustment, vector<int> marks) {
	if (!isMultiOfTen(totalMarks))
		return totalMarks;

	smallestAdjustment = findSmallestAdjustment(marks);
	if(smallestAdjustment != 0)
	return totalMarks -= smallestAdjustment;	

	return 0;
}

void print(int totalMark, int smlAdj, vector<int> marks) {
	cout << retResult(totalMark, smlAdj, marks);
}

int totMark(const vector <int>& marks) {
	return accumulate(marks.begin(), marks.end(), 0);
}

vector <int> inputNumOfRes() {
	int marks{};
	do {
		cout << "How many marks do you have: ";
		cin >> marks;
	} while (marks <= 0 || marks > 100);

	vector <int> mark(marks);
	for (int& eachMark : mark) {
		do {
			cout << "Enter the score in your Exam: ";
			cin >> eachMark;
		} while (eachMark <= 0 || eachMark > 100);
	}
	sort(mark.begin(), mark.end());
	return mark;
}

int main() {

	vector <int> marks{ inputNumOfRes() };
	int totalMarks{ totMark(marks) };
	int smallestAdjustment{};

	print(totalMarks, smallestAdjustment, marks);


	return 0;
}
