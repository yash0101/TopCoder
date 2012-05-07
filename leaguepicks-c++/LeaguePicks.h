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

class LeaguePicks {

	public: vector<int> returnPicks(int position, int friends, int picks) {
		vector<int> answer;
		int num=position, times=0;
		while(num <= picks) {
			times++;
			answer.push_back(num);
			if(times%2!=0)
				num += ((friends - position) * 2 + 1);
			else
				num += ((position-1)*2 + 1);
		}
		return answer;
	}

};
