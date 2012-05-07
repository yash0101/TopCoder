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

class Birthday {

	vector<string> tokenize(const string& str,const string& delimiters)
	{
		vector<string> tokens;
		// skip delimiters at beginning.
	    	string::size_type lastPos = str.find_first_not_of(delimiters, 0);
		// find first "non-delimiter".
	    	string::size_type pos = str.find_first_of(delimiters, lastPos);
	    	while (string::npos != pos || string::npos != lastPos)
	    	{
	        	// found a token, add it to the vector.
	        	tokens.push_back(str.substr(lastPos, pos - lastPos));
	        	// skip delimiters.  Note the "not_of"
	        	lastPos = str.find_first_not_of(delimiters, pos);
	        	// find next "non-delimiter"
	        	pos = str.find_first_of(delimiters, lastPos);
	    	}
		return tokens;
	}

	public: string getNext(string date, vector<string> birthdays) {
		vector<string> dates, getdate;
		string answer="";

		FOR(i,0,birthdays.size()) {
			getdate = (tokenize(birthdays[i], " "));
			dates.push_back(getdate[0]);
		}

		sort(dates.begin(), dates.end());

		FOR(i,0,(dates.size())) {
			if(dates[i] > date) {
				answer = dates[i];
				break;
			} else if (dates[i] == date) {
					answer = dates[i];
					break;
			}
		}

		if(answer == "") {
			answer = dates[0];
		}

		return answer;
	}
};
