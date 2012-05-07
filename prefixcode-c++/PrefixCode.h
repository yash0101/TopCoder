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


class PrefixCode {

	string convertInt(int number)
	{
	   stringstream ss;//create a stringstream
	   ss << number;//add number to the stream
	   return ss.str();//return a string with the contents of the stream
	};

	int is_prefix(string main, string sub) {
		int len, ret;
		if(main.size() > sub.size()) {
			len = sub.size();
			ret = 1;
		} else {
			len = main.size();
			ret = 2;
		}

		FOR(i,0,len) {
			if(main[i] != sub[i]) {
				ret=0;
				break;
			}
		}
		return ret;
	};

	public: string isOne(vector<string> words) {
		unsigned int index, index_final=-1, match=0, ret;
		string answer;
		FOR(i,0,words.size()-1) {
			FOR(j,i+1,words.size()) {
				if((ret = is_prefix(words[i], words[j]))) {
					match++;
					if(ret == 1) {
						index = j;
					} else {
						index = i;
					}
					if(index < index_final)
						index_final = index;
				}
			}
		}
		string buff = convertInt(index_final);
		if(match) {
			answer.push_back('N');
			answer.push_back('o');
			answer.push_back(',');
			answer.push_back(' ');
			FOR(i,0,buff.size()) {
				answer.push_back(buff[i]);
			}
		} else {
			answer.push_back('Y');
			answer.push_back('e');
			answer.push_back('s');
		}
		return answer;
	}

};
