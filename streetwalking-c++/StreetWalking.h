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

class StreetWalking {

	public: long long minTime(int x, int y, int w, int s) {
		long long answer =0, X=(long long)x, Y=(long long)y, walkTime=(long long)w, sneakTime=(long long)s;
		long long tmp;
		if(X<Y) { tmp = X; X = Y; Y = tmp; }

			if(sneakTime < 2*walkTime){
				answer = sneakTime * Y;
			} else {
				answer = 2 *walkTime * Y;
			}

			X = X - Y;
			if(sneakTime < walkTime) {
				if(X%2==0) {
					answer += sneakTime * X;
				} else {
					answer += sneakTime * (X-1) + walkTime;
				}
			} else {
				answer += X * walkTime;
			}

		return answer;
	}

};
