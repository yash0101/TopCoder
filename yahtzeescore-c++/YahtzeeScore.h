#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#define FOR(i,s,e) for (int i = int(s); i < int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ISEQ(c) (c).begin(), (c).end()

class YahtzeeScore {

	public: int maxPoints(vector<int> toss) {
		int tot=0, max=0;
		sort(toss.begin(), toss.end());
		tot = max = toss[0];
		FOR(i,1, toss.size()) {

			if(toss[i]==toss[i-1]) {
				tot += toss[i];
			} else {
				tot = toss[i];
			}
			if(max < tot)
				max = tot;
		}
		return max;
	}

};
