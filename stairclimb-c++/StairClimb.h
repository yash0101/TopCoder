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

class StairClimb {

	public: int stridesTaken(vector<int> flights, int stairsPerStride) {
		int tot_steps=0;
		for(unsigned int i =0;i<flights.size(); i++) {
			tot_steps += 2;
			if(flights[i]%stairsPerStride == 0)
				tot_steps += flights[i]/stairsPerStride ;
			else
				tot_steps += flights[i]/stairsPerStride + 1;
		}
			tot_steps -= 2;
		return tot_steps;
	}

};
