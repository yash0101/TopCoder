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

class ImageDithering {

	public: int count(string dithered, vector<string> screen) {
		unsigned int tot=0;
		map<int, int> hash;


		FOR(i,0,dithered.length()) {
				hash[dithered[i]]=1;
		}

		FOR(i,0,screen.size()) {
			FOR(j,0,screen[i].length()) {
				string str = screen[i];
				if(hash[str[j]])
					tot++;
			}
		}
		return tot;
	};
};
