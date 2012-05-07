#include "QuiningTopCoder.h"
#include <iostream>
#include <string>

using std::cerr;
using std::cout;
using std::endl;
using std::string;

class QuiningTopCoderTest {

    static void assertEquals(int testCase, const string& expected, const string& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << '"' << expected << '"' << "> but was: <" << '"' << actual << '"' << '>' << endl;
        }
    }

    QuiningTopCoder solution;

    void testCase0() {
		string source = ",";
		string expected_ = "QUINES 0";
        assertEquals(0, expected_, solution.testCode(source));
    }

    void testCase1() {
		string source = "_";
		string expected_ = "TIMEOUT";
        assertEquals(1, expected_, solution.testCode(source));
    }

    void testCase2() {
		string source = "1:+:1J";
		string expected_ = "OVERFLOW 147";
        assertEquals(2, expected_, solution.testCode(source));
    }

    void testCase3() {
		string source = "0,1+:#@:$1J";
		string expected_ = "QUINES 91";
        assertEquals(3, expected_, solution.testCode(source));
    }

    void testCase4() {
		string source = "0,1+::9W-9W-S1W1W:+2_J_@_@";
		string expected_ = "BADEND 437";
        assertEquals(4, expected_, solution.testCode(source));
    }

    void testCase5() {
		string source = "#R,#:+1+:#,R#";
		string expected_ = "QUINES 97";
        assertEquals(5, expected_, solution.testCode(source));
    }

    void testCase6() {
		string source = "R,#1+1:";
		string expected_ = "MISMATCH 7";
        assertEquals(6, expected_, solution.testCode(source));
    }

    public: void runTest(int testCase) {
        switch (testCase) {
            case (0): testCase0(); break;
            case (1): testCase1(); break;
            case (2): testCase2(); break;
            case (3): testCase3(); break;
            case (4): testCase4(); break;
            case (5): testCase5(); break;
            case (6): testCase6(); break;
            default: cerr << "No such test case: " << testCase << endl; break;
        }
    }

};

int main() {
    for (int i = 0; i < 7; i++) {
        QuiningTopCoderTest test;
        test.runTest(i);
    }
}
