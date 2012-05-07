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


class ProblemWriting {
//"3.........../...........4"
//"9..+.5...*....3"

	int checklegal(string str) {
		//cout<<"str="<<str<<"\n";
		int len= str.length(), index=0, flag=0;
		for(int i=0; i< len;i++) {
			if(i>0 && str[i] == '.') {
				if(str[i-1] != '+' && str[i-1] != '-' && str[i-1] != '/' && str[i-1] != '*' && str[i-1] != '.') {
					flag = 1;
					//cout<<"setting flag="<<i<<"\n";
					continue;
				}
			} else if(str[i] != '+' && str[i] != '-' && str[i] != '/' && str[i] != '*' && str[i] != '.') {
				if(flag == 1 && i>0 && str[i-1] == '.') {
					index =i;
					//cout<<"Breaking="<<i<<"\n";
					break;
				}
			} else if(flag == 1 && (str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*'))
				flag =0;
				//cout<<"unsetting flag="<<i<<"\n";
		}
			//cout<<index<<"\n";
			return index;
	}

	public: string myCheckData(string dotForm) {
		string err1="dotForm must contain between 1 and 25 characters, inclusive.";
		string err2="dotForm is not in dot notation, check character ";
		string success="";
		//1.check if len is greater than 25
		if(dotForm.length()>25) {
			return err1;
		} else {
			//2.check if dot is present between numbers
			int x = checklegal(dotForm);
			if(!x)
				return success;
			else {
				stringstream ss;
				ss << err2 << x<<".";
				return ss.str();
			}
		}
		return string();
	}

};
