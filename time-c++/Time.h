#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <stdio.h>
using namespace std;

#define FOR(i,s,e) for (int i = int(s); i != int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ISEQ(c) (c).begin(), (c).end()

class Time {

	public: string whatTime(int seconds) {
		int hr, min, sec, tot_sec = seconds;
		ostringstream oss;
		string ret, buff;
		hr = tot_sec/(60*60);
		tot_sec -= (hr*60*60);
		min = tot_sec/60;
		tot_sec -= (min*60);
		sec = tot_sec;
		oss<<hr<<":"<<min<<":"<<sec;
		ret = oss.str();
		return ret;
	};
};
