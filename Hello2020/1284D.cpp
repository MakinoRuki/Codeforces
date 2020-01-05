#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#define N 250005
using namespace std;
typedef long long ll;
const ll inf = 2000000000000000000LL;
int n;
vector<pair<int, int>> a;
vector<pair<int, int>> b;
bool check(vector<pair<int,int>>& av, vector<pair<int,int>>& bv) {
	vector<pair<int, pair<int, int>>> rk;
	rk.clear();
	for (int i = 0; i < av.size(); ++i) {
		rk.push_back(make_pair(av[i].first, make_pair(-1, i)));
		rk.push_back(make_pair(av[i].second, make_pair(1, i)));
	}
	sort(rk.begin(), rk.end());
	multiset<int> ss;
	multiset<int> es;
	ss.clear();
	es.clear();
	for (int i = 0; i < rk.size(); ++i) {
		if (rk[i].second.first < 0) {
			int id = rk[i].second.second;
			if (es.size()) {
				int e = *es.begin();
				int s = *ss.rbegin();
				if (bv[id].first > e || bv[id].second < s) {
					return false;
				}
			}
			es.insert(bv[id].second);
			ss.insert(bv[id].first);
		} else {
			int id = rk[i].second.second;
			es.erase(es.find(bv[id].second));
			ss.erase(ss.find(bv[id].first));
		}
	}
	return true;
}
int main() {
	cin>>n;
	a.clear();
	b.clear();
	for (int i = 0; i < n; ++i) {
		int sa,ea,sb,eb;
		cin>>sa>>ea>>sb>>eb;
		a.push_back(make_pair(sa, ea));
		b.push_back(make_pair(sb, eb));
	}
	//cout<<check(a, b)<<" "<<check(b,a);
	if (check(a, b) && check(b, a)) {
		cout<<"YES"<<endl;
	} else {
		cout<<"NO"<<endl;
	}
	return 0;
}
