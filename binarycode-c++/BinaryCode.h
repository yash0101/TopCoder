#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <string>

using namespace std;

#define FOR(i,s,e) for (int i = int(s); i != int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ISEQ(c) (c).begin(), (c).end()

int getv(string p,int l)
       {
               if(l >= (int)p.length() || l < 0)
               return 0;
               return p[l]-48;
       }


class BinaryCode {

	string decode (string message, char ch) {
		string ret = message;
		ret[0] = ch;
		unsigned int err=0, i;

        if(ret.length() <= 1) {
                if(ch == '0' && getv(message,0) == 0)
                        return ret;
                else if(ch == '1' && getv(message,0) == 1)
                        return ret;
                else /*if(ch != '1' && ch != '0')*/
                		return "NONE";
        }

		for(i =1;i < message.length();i++) {
			ret[i] = (getv(message, i-1) - getv(ret,i-1) - getv(ret, i-2)) + '0';
			if(((i+1 == ret.length()) && (getv(ret,i) != getv(message, i) - getv(ret,i-1))) ||
					(ret[i] > '1' || ret[i] < '0'))
			{
		    			err= 1;
		    			break;
		    }
		}
		if(err) {
			return "NONE";
		} else {
			return ret;
		}
	}

	public: vector<string> decode(string message) {
		 vector<string> ret;
		 ret.push_back(decode(message,'0'));
		 ret.push_back(decode(message,'1'));
		 return ret;
	}

};
