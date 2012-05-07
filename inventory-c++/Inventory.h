#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#define FOR(i,s,e) for (int i = int(s); i != int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ISEQ(c) (c).begin(), (c).end()

class Inventory {

	public: int monthlyOrder(vector<int> sales, vector<int> daysAvailable) {
		double val, tot_months=0;
		for(unsigned int i=0;i < sales.size();i++) {
			double up=sales[i], down=daysAvailable[i];
			if(down) {
				val += ((up/down)*30);
				tot_months++;
			}
		}

		double final_val=0;
		final_val = val/tot_months;
		int month= val/tot_months;
		if((final_val - month) > 1e-9)
			final_val +=1;

		return final_val;
	}

};
