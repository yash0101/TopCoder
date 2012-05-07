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

class MostProfitable {

	public: string bestItem(vector<int> costs, vector<int> prices, vector<int> sales, vector<string> items) {
		int index=-1,max=-1, val=-1;
		for(unsigned int i =0; i< items.size(); i++) {
			if(prices[i] > costs[i]) {
				val = (prices[i] - costs[i])*sales[i];
			}
			if(val > max) {
				max = val;
				index = i;
			}
		}
		if(max > 0)
			return items[index];
		else
			return "";
	}

};
