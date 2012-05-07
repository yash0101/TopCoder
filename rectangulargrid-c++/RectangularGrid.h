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

class RectangularGrid {

	public: long long countRectangles(int width, int height) {
		long long w=(long long)width, h=(long long)height, tot=0, i, j, l;
		cout<<"w="<<width<<"\th="<<height<<"\n";
		for(l=0; l<w; l++) {
			for(i=1;i <= w - l; i++) {
				for(j=1; j <= h; j++)
					if(i!=j) {
						cout<<"x="<<i<<"\ty="<<j<<endl;
						tot++;
					}
			}
		}
		cin>>tot;
		cout<<tot<<"\n";
		return tot;
	}

};
