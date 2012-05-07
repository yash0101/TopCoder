#include "StreetWalking.h"
#include <iostream>

using std::cerr;
using std::cout;
using std::endl;

class StreetWalkingTest {

    static void assertEquals(int testCase, const long long& expected, const long long& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    StreetWalking solution;

    void testCase0() {
		int X = 4;
		int Y = 2;
		int walkTime = 3;
		int sneakTime = 10;
		long long expected_ = 18LL;
        assertEquals(0, expected_, solution.minTime(X, Y, walkTime, sneakTime));
    }

    void testCase1() {
		int X = 4;
		int Y = 2;
		int walkTime = 3;
		int sneakTime = 5;
		long long expected_ = 16LL;
        assertEquals(1, expected_, solution.minTime(X, Y, walkTime, sneakTime));
    }

    void testCase2() {
		int X = 2;
		int Y = 0;
		int walkTime = 12;
		int sneakTime = 10;
		long long expected_ = 20LL;
        assertEquals(2, expected_, solution.minTime(X, Y, walkTime, sneakTime));
    }

    void testCase3() {
		int X = 25;
		int Y = 18;
		int walkTime = 7;
		int sneakTime = 11;
		long long expected_ = 247LL;
        assertEquals(3, expected_, solution.minTime(X, Y, walkTime, sneakTime));
    }

    void testCase4() {
		int X = 24;
		int Y = 16;
		int walkTime = 12;
		int sneakTime = 10;
		long long expected_ = 240LL;
        assertEquals(4, expected_, solution.minTime(X, Y, walkTime, sneakTime));
    }

    void testCase5() {
		int X = 10000000;
		int Y = 50000000;
		int walkTime = 800;
		int sneakTime = 901;
		long long expected_ = 41010000000LL;
        assertEquals(5, expected_, solution.minTime(X, Y, walkTime, sneakTime));
    }

    void testCase6() {
		int X = 135;
		int Y = 122;
		int walkTime = 43;
		int sneakTime = 29;
		long long expected_ = 3929LL;
        assertEquals(6, expected_, solution.minTime(X, Y, walkTime, sneakTime));
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
        StreetWalkingTest test;
        test.runTest(i);
    }
}
