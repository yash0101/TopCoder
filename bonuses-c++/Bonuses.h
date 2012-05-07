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

class Bonuses {

	/*
	int check_validity(vector<int> points, int bonus, int index){
		if(bonus == 1 && points[index] == points[index-1])
			return 1;
		else {
			return 0;
		}
	}
	*/

	int get_best_index(vector<int> points, vector<int> sorted_point) {

		static int val = 0, val_index= 0;
		int index=0;
		FOR(i,0,points.size()) {
					if(val==0) {//get the highest value
						val = sorted_point[sorted_point.size()-1];
						FOR(i,0,points.size()) {
							if(points[i] == val) {
								index = i;
								val_index = i ;
							}
						}
					} else { // next greater after val
						FOR(i,val_index,points.size())
							for(int j= val_index; j > 0; j++ ){
							//if(sorted_point[j] > sorted_point[j-1])
								//index = j -1;
							//else if they are equal
						}
					}
				}
		cout<<index<<"\t"<<val<<"\n";
		return index;
	}

	public: vector<int> getDivision(vector<int> points) {
		/* There may be some percentage of bonus left over (because of the fractional truncation).
		 * If n% of the bonus is left over, give the top n employees 1% of the bonus.
		 * There will be no more bonus left after this.
		 * If two or more employees with the same number of points qualify for this "extra" bonus,
		 * but not enough bonus is left to give them all an extra 1%, give it to the employees that come first in points.
		 * */
		int tot_points=0, new_tot=0;
		vector<int> percent, sorted_points;

		sorted_points = points;
		sort(sorted_points.begin(), sorted_points.end());

		FOR(i,0,points.size()) {
			tot_points += points[i];
		}

		FOR(i,0,points.size()) {
			percent.push_back((points[i]*100)/tot_points);
			new_tot += percent[i];
		}

		new_tot = 100 - new_tot;

		//while(new_tot--) {
			percent[get_best_index(points, sorted_points)]++;
		//}

		/*
		if(new_tot > 0) {
			FOR2(i,0,points.size()) {
				if(check_validity(points, new_tot, i))
					percent[i] += 1;
				else
					i = points.size() -1;

				if(new_tot)
					new_tot--;
				else
					break;
				cout<<new_tot<<"\n";
			}
		}
		*/
		return percent;
	}

};
