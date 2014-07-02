// lab #6

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
	// open file and check that it opens
	ifstream infile;
	infile.open("student_test_scores.txt");
	
	if (!infile)
	{
		cout << "Error opening file.";
		system("pause");
		return 0;
	}

	// declarations & initialization
	const int n = 5;
	int i = 0;  // for loop index
	int tests[n]; // array of student grades
	int test_sum = 0;
	float avg = 0.0, w_avg = 0.0, final_avg = 0.0; // average, weighted average, and final average
	const float w1 = .20, w2 = .25, w3 = .30; // weights for weighted average
	char letterGrade = 'X';
	const int num_Students = 35; // max number of students in a class
	string name = "";

	// set floats to print to two decimal places
	cout << fixed << setprecision(2);

	// output test-weights
	cout << "Grading Policy:\n"
	<< "Tests 1 and 3 are weighted 20%, \nTests 2 and 4 are weighted 25%, \nand Test 5 is weighted 30%." << endl << endl;

	// set up page with headers 
	cout << "Name " << setw(14) << "Scores " << setw(18) << "Avg " << setw(9) << "W.Avg" << setw(10) << "Grade " << setw(9) << "Message " << endl;
 
	do
	{
		// read in and print out name
		infile >> name;
		cout << setw(10) << setfill(' ') << left << name;

		// read in and print out test scores 
		cout << setfill(' ') << right;
		for (i = 0; i < n; i++)
		{
			infile >> tests[i];
			cout << setw(4) << setfill(' ') << tests[i];
		}
	
		// calculate and print the average
		for (i = 0; i < n; i++)
			test_sum += tests[i];
		avg = test_sum / n;
		cout << setw(8) << avg << " ";

		// calculate and print the weighted average
		w_avg = (tests[0] * w1) + (tests[1] * w2) + (tests[2] * w1) + (tests[3] * w2) + (tests[4] * w3);
		cout << setw(8) << w_avg;

		// compare average and weighted average
		if (w_avg >= avg)
			final_avg = w_avg;
		else final_avg = avg;

		// determine letter grade
		if (final_avg >= 90)
			letterGrade = 'A';
		else if (final_avg >= 80)
			letterGrade = 'B';
		else if (final_avg >= 70)
			letterGrade = 'C';
		else if (final_avg >= 60)
			letterGrade = 'D';
		else letterGrade = 'F';

		cout << setw(6) << letterGrade << setw(4) << " "; 

		// use a switch to determine message
		switch (letterGrade) {
		case 'A': cout << "Excellent work! ";
			break;
		case 'B': cout << "Good job! ";
			break;
		case 'C':
		case 'D':
			cout << "You could do better. ";
			break;
		case 'F': cout << "Not good. ";
			break;
		default: cout << "Invalid grade. ";
		}

		cout << endl;
		test_sum = 0; // reset variable for next iteration
	
	} while (!infile.eof());

	system("pause");
	return 0;
} // end main

