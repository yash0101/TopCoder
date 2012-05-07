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

class WidgetRepairs {

	public: int days(vector<int> arrivals, int numPerDay) {
		int tot_days = 0, remaining = 0;
		FOR(i,0,arrivals.size()) {
			remaining += arrivals[i];
			if(remaining != 0) {
				tot_days++;
				remaining = (remaining - numPerDay);
				if(remaining < 0)
					remaining = 0;
			}
		}
		while (remaining > 0) {
			tot_days++;
			remaining = (remaining - numPerDay);
		}
		return tot_days;
	}

};
