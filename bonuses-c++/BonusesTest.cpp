#include "Bonuses.h"
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class BonusesTest {

    static void writeTo(std::ostream& out, const vector<int>& v) {
        out << '{';
        for (unsigned int i = 0; i < v.size(); i++) {
            out << v[i];
            if (i + 1 != v.size()) out << ", ";
        }
        out << '}';
    }

    static void assertEquals(int testCase, const vector<int>& expected, const vector<int>& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <";
            writeTo(cout, expected);
            cout << "> but was: <";
            writeTo(cout, actual);
            cout << '>' << endl;
        }
    }

    Bonuses solution;

    void testCase0() {
        int points_[] = {1, 2, 3, 4, 5};
        vector<int> points(points_, points_ + (sizeof(points_) / sizeof(points_[0])));
        int expected__[] = {6, 13, 20, 27, 34};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(0, expected_, solution.getDivision(points));
    }

    void testCase1() {
        int points_[] = {5, 5, 5, 5, 5, 5};
        vector<int> points(points_, points_ + (sizeof(points_) / sizeof(points_[0])));
        int expected__[] = {17, 17, 17, 17, 16, 16};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(1, expected_, solution.getDivision(points));
    }

    void testCase2() {
        int points_[] = {485, 324, 263, 143, 470, 292, 304, 188, 100, 254, 296, 255, 360, 231, 311, 275, 93, 463, 115, 366, 197, 470};
        vector<int> points(points_, points_ + (sizeof(points_) / sizeof(points_[0])));
        int expected__[] = {8, 6, 4, 2, 8, 5, 5, 3, 1, 4, 5, 4, 6, 3, 5, 4, 1, 8, 1, 6, 3, 8};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(2, expected_, solution.getDivision(points));
    }

    public: void runTest(int testCase) {
        switch (testCase) {
            case (0): testCase0(); break;
            case (1): testCase1(); break;
            case (2): testCase2(); break;
            default: cerr << "No such test case: " << testCase << endl; break;
        }
    }

};

int main() {
    for (int i = 0; i < 3; i++) {
        BonusesTest test;
        test.runTest(i);
    }
}
