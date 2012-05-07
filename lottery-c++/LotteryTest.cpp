#include "Lottery.h"
#include <iostream>
#include <string>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class LotteryTest {

    static void writeTo(std::ostream& out, const vector<string>& v) {
        out << '{';
        for (unsigned int i = 0; i < v.size(); i++) {
            out << '"' << v[i] << '"';
            if (i + 1 != v.size()) out << ", ";
        }
        out << '}';
    }

    static void assertEquals(int testCase, const vector<string>& expected, const vector<string>& actual) {
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

    Lottery solution;

    void testCase0() {
        string rules_[] = {"PICK ANY TWO: 10 2 F F", "PICK TWO IN ORDER: 10 2 T F", "PICK TWO DIFFERENT: 10 2 F T", "PICK TWO LIMITED: 10 2 T T"};
        vector<string> rules(rules_, rules_ + (sizeof(rules_) / sizeof(rules_[0])));
        string expected__[] = {"PICK TWO LIMITED", "PICK TWO IN ORDER", "PICK TWO DIFFERENT", "PICK ANY TWO"};
        vector<string> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(0, expected_, solution.sortByOdds(rules));
    }

    void testCase1() {
        string rules_[] = {"INDIGO: 93 8 T F", "ORANGE: 29 8 F T", "VIOLET: 76 6 F F", "BLUE: 100 8 T T", "RED: 99 8 T T", "GREEN: 78 6 F T", "YELLOW: 75 6 F F"};
        vector<string> rules(rules_, rules_ + (sizeof(rules_) / sizeof(rules_[0])));
        string expected__[] = {"RED", "ORANGE", "YELLOW", "GREEN", "BLUE", "INDIGO", "VIOLET"};
        vector<string> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(1, expected_, solution.sortByOdds(rules));
    }

    void testCase2() {
        vector<string> rules;
        vector<string> expected_;
        assertEquals(2, expected_, solution.sortByOdds(rules));
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
        LotteryTest test;
        test.runTest(i);
    }
}
