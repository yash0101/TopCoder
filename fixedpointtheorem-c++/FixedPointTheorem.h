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

class FixedPointTheorem {

	public: double cycleRange(double R) {
		//F(X)=R*X*(1-X);
		double X=.25, min=0, max=0;
		int times = 200000;
			while(times--) {
				X = R * X * (1-X);
			}
		times = 1000;
		min = max =X;
		while(times--) {
			X = R * X * (1-X);
			if(X < min)
				min = X;
			if(X > max)
				max = X;
		}
		X= max-min;
		return X;
	}

};
