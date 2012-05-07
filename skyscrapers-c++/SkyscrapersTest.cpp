#include "Skyscrapers.h"
#include <iostream>

using std::cerr;
using std::cout;
using std::endl;

class SkyscrapersTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    Skyscrapers solution;

    void testCase0() {
		int N = 3;
		int leftSide = 2;
		int rightSide = 2;
		int expected_ = 2;
        assertEquals(0, expected_, solution.buildingCount(N, leftSide, rightSide));
    }

    void testCase1() {
		int N = 3;
		int leftSide = 2;
		int rightSide = 1;
		int expected_ = 1;
        assertEquals(1, expected_, solution.buildingCount(N, leftSide, rightSide));
    }

    void testCase2() {
		int N = 5;
		int leftSide = 3;
		int rightSide = 2;
		int expected_ = 18;
        assertEquals(2, expected_, solution.buildingCount(N, leftSide, rightSide));
    }

    void testCase3() {
		int N = 12;
		int leftSide = 1;
		int rightSide = 1;
		int expected_ = 0;
        assertEquals(3, expected_, solution.buildingCount(N, leftSide, rightSide));
    }

    void testCase4() {
		int N = 8;
		int leftSide = 3;
		int rightSide = 2;
		int expected_ = 4872;
        assertEquals(4, expected_, solution.buildingCount(N, leftSide, rightSide));
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
        SkyscrapersTest test;
        test.runTest(i);
    }
}
