#include "DotNotation.h"
#include <iostream>
#include <string>

using std::cerr;
using std::cout;
using std::endl;
using std::string;

class DotNotationTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    DotNotation solution;

    void testCase0() {
		string dotForm = "2";
		int expected_ = 1;
        assertEquals(0, expected_, solution.countAmbiguity(dotForm));
    }

    void testCase1() {
		string dotForm = "9+5*3";
		int expected_ = 2;
        assertEquals(1, expected_, solution.countAmbiguity(dotForm));
    }

    void testCase2() {
		string dotForm = "9+5.*3";
		int expected_ = 1;
        assertEquals(2, expected_, solution.countAmbiguity(dotForm));
    }

    void testCase3() {
		string dotForm = "1+2.*.3+4";
		int expected_ = 1;
        assertEquals(3, expected_, solution.countAmbiguity(dotForm));
    }

    void testCase4() {
		string dotForm = "9*8+7*6-5+4*3/2./9";
		int expected_ = 99;
        assertEquals(4, expected_, solution.countAmbiguity(dotForm));
    }

    void testCase5() {
		string dotForm = "1+...2....*.8..+7";
		int expected_ = 0;
        assertEquals(5, expected_, solution.countAmbiguity(dotForm));
    }

    public: void runTest(int testCase) {
        switch (testCase) {
            case (0): testCase0(); break;
            case (1): testCase1(); break;
            case (2): testCase2(); break;
            case (3): testCase3(); break;
            case (4): testCase4(); break;
            case (5): testCase5(); break;
            default: cerr << "No such test case: " << testCase << endl; break;
        }
    }

};

int main() {
    for (int i = 0; i < 6; i++) {
        DotNotationTest test;
        test.runTest(i);
    }
}
