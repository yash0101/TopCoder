#include "Birthday.h"
#include <iostream>
#include <string>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class BirthdayTest {

    static void assertEquals(int testCase, const string& expected, const string& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << '"' << expected << '"' << "> but was: <" << '"' << actual << '"' << '>' << endl;
        }
    }

    Birthday solution;

    void testCase0() {
		string date = "06/17";
        string birthdays_[] = {"02/17 Wernie", "10/12 Stefan"};
        vector<string> birthdays(birthdays_, birthdays_ + (sizeof(birthdays_) / sizeof(birthdays_[0])));
		string expected_ = "10/12";
        assertEquals(0, expected_, solution.getNext(date, birthdays));
    }

    void testCase1() {
		string date = "06/17";
        string birthdays_[] = {"10/12 Stefan"};
        vector<string> birthdays(birthdays_, birthdays_ + (sizeof(birthdays_) / sizeof(birthdays_[0])));
		string expected_ = "10/12";
        assertEquals(1, expected_, solution.getNext(date, birthdays));
    }

    void testCase2() {
		string date = "02/17";
        string birthdays_[] = {"02/17 Wernie", "10/12 Stefan"};
        vector<string> birthdays(birthdays_, birthdays_ + (sizeof(birthdays_) / sizeof(birthdays_[0])));
		string expected_ = "02/17";
        assertEquals(2, expected_, solution.getNext(date, birthdays));
    }

    void testCase3() {
		string date = "12/24";
        string birthdays_[] = {"10/12 Stefan"};
        vector<string> birthdays(birthdays_, birthdays_ + (sizeof(birthdays_) / sizeof(birthdays_[0])));
		string expected_ = "10/12";
        assertEquals(3, expected_, solution.getNext(date, birthdays));
    }

    void testCase4() {
		string date = "01/02";
        string birthdays_[] = {"02/17 Wernie", "10/12 Stefan", "02/17 MichaelJordan", "10/12 LucianoPavarotti", "05/18 WilhelmSteinitz"};
        vector<string> birthdays(birthdays_, birthdays_ + (sizeof(birthdays_) / sizeof(birthdays_[0])));
		string expected_ = "02/17";
        assertEquals(4, expected_, solution.getNext(date, birthdays));
    }

    public: void runTest(int testCase) {
        switch (testCase) {
            case (0): testCase0(); break;
            case (1): testCase1(); break;
            case (2): testCase2(); break;
            case (3): testCase3(); break;
            case (4): testCase4(); break;
            default: cerr << "No such test case: " << testCase << endl; break;
        }
    }

};

int main() {
    for (int i = 0; i < 5; i++) {
        BirthdayTest test;
        test.runTest(i);
    }
}
