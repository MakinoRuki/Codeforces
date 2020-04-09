#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#define N 200005
using namespace std;
typedef long long ll;
const ll mod = 998244353LL;
int n, k;
string s;
int main() {
	cin>>n>>k;
	cin>>s;
	vector<vector<int>> ps;
	ps.clear();
	while(true) {
		vector<int> xs;
		xs.clear();
		string t= s;
		int i = 0;
		while(i +1< s.size()) {
			if (s[i] == 'R' && s[i+1] == 'L') {
				t[i] = 'L';
				t[i+1] = 'R';
				xs.push_back(i);
				i+=2;
			} else {
				i++;
			}
		}
		if (xs.empty()) break;
		ps.push_back(xs);
		s = t;
	}
	int maxv = 0;
	for (int i = 0; i < ps.size(); ++i) {
		maxv += ps[i].size();
	}
	if (k < ps.size() || k > maxv) {
		cout<<-1<<endl;
	} else {
		int det = k-ps.size();
		for (int i = 0; i < ps.size(); ++i) {
		//	cout<<"i="<<i<<" "<<det<<endl;
			int ext = min(det, (int)ps[i].size()-1);
			int j;
			for (j = 0; j < ext; ++j) {
				//cout<<1<<" "<<ps[i][j]+1<<endl;
				printf("1 %d\n", ps[i][j]+1);
			}
			int rem = ps[i].size()-j;
			if (rem > 0) {
				printf("%d", rem);
				//cout<<rem;
				for (; j < ps[i].size(); ++j) {
					//cout<<" "<<ps[i][j]+1;
					printf(" %d", ps[i][j]+1);
				}
				printf("\n");
				//cout<<endl;
			}
			det -= ext;
		//	cout<<"i="<<i<<" "<<det<<endl;
		}
	}
	return 0;
}
