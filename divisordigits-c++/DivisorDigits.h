#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

#define FOR(i,s,e) for (int i = int(s); i != int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ISEQ(c) (c).begin(), (c).end()

class DivisorDigits {

	public: int howMany(int number) {
		int temp = number, tot=0, num;
		int x =0;
		while(temp) {
			num = temp%(10);
			temp = temp - num;
			temp = temp/10;
			if(num && !(number%num))
				tot++;
			x++;
		}
		return tot;
	}

};
