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

class MergeSort {
/*
 * List mergeSort(List a)
1. if size(a) <= 1, return a
2. split a into two sublists b and c
   if size(a) = 2*k, b contains the first k elements of a, c the last k elements
   if size(a) = 2*k+1, b contains the first k elements of a, c the last k+1 elements
3. List sb = mergeSort(b)
   List sc = mergeSort(c)
4. return merge(sb, sc)


List merge(List b, List c)
1. create an empty list a
2. while both b and c are not empty, compare the first elements of b and c
   first(b) < first(c): remove the first element of b and append it to the end of a
   first(b) > first(c): remove the first element of c and append it to the end of a
   first(b) = first(c): remove the first elements of b and c and append them to the end of a
3. if either b or c is not empty, append that non-empty list to the end of a
4. return a
 *
 */

	vector <int> merge(vector<int> fst, vector<int> sec, int *final_cmp){
		vector<int> final;
		int len1 = fst.size(), len2=sec.size(), i1=0, i2=0;
		int cmp=0;

		//cout<<"First=\t\t";
		//FOR(i,0,fst.size())
		// 	 cout<<fst[i]<<"\t";
		//cout<<"\n";
		//cout<<"Second=\t\t";
		//FOR(i,0,sec.size())
		//	cout<<sec[i]<<"\t";
		//cout<<"\n";
		while((i1<len1) && (i2<len2)) {
			if(fst[i1] < sec[i2]) {
				final.push_back(fst[i1++]);
				cmp++;
			} else if(fst[i1] > sec[i2]) {
				final.push_back(sec[i2++]);
				cmp++;
			} else if(fst[i1] == sec[i2]) {
				final.push_back(fst[i1++]);
				final.push_back(sec[i2++]);
				cmp++;
			}
		}
		if(i1<len1) {
			FOR(i,i1,fst.size())
				final.push_back(fst[i]);
		} else {
			FOR(i,i2,fst.size())
				final.push_back(sec[i]);
		}
		//cout<<"Final=\t\t";
		//FOR(i,0,final.size())
		//	cout<<final[i]<<"\t";
		//cout<<"\n";

		*final_cmp += cmp;
		return final;
		//return cmp;
	}

	void print(vector<int> arr) {
		FOR(i,0,arr.size()) {
			cout<<arr[i]<<"\t";
		}
		cout<<"\n";
	}


	vector<int> mergesort(vector<int> numbers, int * cmp) {
				int len = numbers.size();
				vector<int> first, second;

				//FOR(i,0,len/2)
					//cout<<numbers[i]<<"\t";
				//cout<<endl;
				//FOR(i,len/2,len)
				//	cout<<numbers[i]<<"\t";
				//cout<<endl;
				if(len <= 1) {
					//cout<<"returning\n";
					return numbers;
				}
				else {
					FOR(i,0,len/2)
						first.push_back(numbers[i]);
					FOR(i,len/2, len)
						second.push_back(numbers[i]);

					first = mergesort(first, cmp);
					//print(first); cout<<"After first\n";
					second = mergesort(second, cmp);
					//print(second); cout<<"After second\n";
				}
				//*cmp +=
				//numbers =
					return	merge(first, second, cmp);
				//return numbers;
	}

	public: int howManyComparisons(vector<int> numbers) {
		vector<int> answer;
		int cmp =0;
		//My testing
		/*
		//static const int arr[] = {10,8,4,12,15,7,4,2,3,1,20};
		static const int arr[] = {10,8,4,12};
		vector<int> mytest (arr, arr + sizeof(arr) / sizeof(arr[0]) );

		answer = mergesort(mytest, &cmp);
		cout<<"Showing =>"<<"\n";
		for(int i=0;i< answer.size();i++)
			cout<<answer[i]<<"\t";

		cout<<"\ncmp="<<cmp<<"\n";
		//ends here
		*/
		///*
		answer = mergesort(numbers, &cmp);
		//cout<<"\ncmp="<<cmp<<"\n";
		//*/
		return cmp;

	}

};
