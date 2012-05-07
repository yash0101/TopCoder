#include "Over9000Rocks.h"
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class Over9000RocksTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    Over9000Rocks solution;

    void testCase0() {
        int lowerBound_[] = {9000};
        vector<int> lowerBound(lowerBound_, lowerBound_ + (sizeof(lowerBound_) / sizeof(lowerBound_[0])));
        int upperBound_[] = {9001};
        vector<int> upperBound(upperBound_, upperBound_ + (sizeof(upperBound_) / sizeof(upperBound_[0])));
		int expected_ = 1;
        assertEquals(0, expected_, solution.countPossibilities(lowerBound, upperBound));
    }

    void testCase1() {
        int lowerBound_[] = {9000, 1, 10};
        vector<int> lowerBound(lowerBound_, lowerBound_ + (sizeof(lowerBound_) / sizeof(lowerBound_[0])));
        int upperBound_[] = {9000, 2, 20};
        vector<int> upperBound(upperBound_, upperBound_ + (sizeof(upperBound_) / sizeof(upperBound_[0])));
		int expected_ = 15;
        assertEquals(1, expected_, solution.countPossibilities(lowerBound, upperBound));
    }

    void testCase2() {
        int lowerBound_[] = {1001, 2001, 3001, 3001};
        vector<int> lowerBound(lowerBound_, lowerBound_ + (sizeof(lowerBound_) / sizeof(lowerBound_[0])));
        int upperBound_[] = {1003, 2003, 3003, 3003};
        vector<int> upperBound(upperBound_, upperBound_ + (sizeof(upperBound_) / sizeof(upperBound_[0])));
		int expected_ = 9;
        assertEquals(2, expected_, solution.countPossibilities(lowerBound, upperBound));
    }

    void testCase3() {
        int lowerBound_[] = {9000, 90000, 1, 10};
        vector<int> lowerBound(lowerBound_, lowerBound_ + (sizeof(lowerBound_) / sizeof(lowerBound_[0])));
        int upperBound_[] = {9000, 90000, 3, 15};
        vector<int> upperBound(upperBound_, upperBound_ + (sizeof(upperBound_) / sizeof(upperBound_[0])));
		int expected_ = 38;
        assertEquals(3, expected_, solution.countPossibilities(lowerBound, upperBound));
    }

    void testCase4() {
        int lowerBound_[] = {1, 1, 1, 1, 1, 1};
        vector<int> lowerBound(lowerBound_, lowerBound_ + (sizeof(lowerBound_) / sizeof(lowerBound_[0])));
        int upperBound_[] = {3, 4, 5, 6, 7, 8};
        vector<int> upperBound(upperBound_, upperBound_ + (sizeof(upperBound_) / sizeof(upperBound_[0])));
		int expected_ = 0;
        assertEquals(4, expected_, solution.countPossibilities(lowerBound, upperBound));
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
        Over9000RocksTest test;
        test.runTest(i);
    }
}
