#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#define N 202
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n;
int main() {
	ll sum = 0LL;
	ll sum2 = 0LL;
	set<int> ls;
	set<int> ds;
	set<int> tmps;
	ls.clear();
	ds.clear();
	tmps.clear();
	cin>>n;
	for (int i = 1; i <= n; ++i) {
		int tp, d;
		scanf("%d%d", &tp, &d);
		if (tp == 0) {
			if (d > 0) {
				sum += (ll)d;
				if (ds.empty() || *ds.begin()>d) {
					tmps.insert(d);
				} else {
					ds.insert(d);
					sum2 += d;
					int x = *ds.begin();
					ds.erase(x);
					sum2 -= x;
					tmps.insert(x);
				}
				while(ds.size() < ls.size() && !tmps.empty()) {
					auto top = *tmps.rbegin();
					tmps.erase(top);
					ds.insert(top);
					sum2 += top;
				}
			} else {
				d = -d;
				sum -= d;
				if (ds.find(d) != ds.end()) {
					ds.erase(d);
					sum2 -= d;
					while(ds.size() < ls.size() && !tmps.empty()) {
						auto top = *tmps.rbegin();
						tmps.erase(top);
						ds.insert(top);
						sum2 += top;
					}
				} else {
					tmps.erase(d);
				}
			}
		} else {
			if (d > 0) {
				sum += d;
				if (ls.empty()) {
					ls.insert(d);
					while(ds.size() < ls.size() && !tmps.empty()) {
						auto top = *tmps.rbegin();
						tmps.erase(top);
						ds.insert(top);
						sum2 += top;
					}
				} else if (d < *ls.begin()) {
					int x = *ls.begin();
					if (ds.empty() || *ds.begin()>x) {
						tmps.insert(x);
					} else {
						ds.insert(x);
						sum2 += x;
						int x2 = *ds.begin();
						ds.erase(x2);
						sum2 -= x2;
						tmps.insert(x2);
					}
					ls.insert(d);
					while (ds.size() < ls.size() && !tmps.empty()) {
						int x = *tmps.rbegin();
						tmps.erase(x);
						ds.insert(x);
						sum2 += x;
					}
				} else {
					ls.insert(d);
					if (ds.empty() || *ds.begin()>d) {
						tmps.insert(d);
					} else {
						ds.insert(d);
						sum2 += d;
						int x2 = *ds.begin();
						ds.erase(x2);
						sum2 -= x2;
						tmps.insert(x2);
					}
					while(ds.size() < ls.size() && !tmps.empty()) {
						auto top = *tmps.rbegin();
						tmps.erase(top);
						ds.insert(top);
						sum2 += top;
					}
				}
				// if (ls.empty() || d < *ls.begin()) {
				// 	ls.insert(d);
				// } else {
				// 	ls.insert(d);
				// 	tmps.insert(-d);
				// }
				// while (ds.size() < ls.size() && !tmps.empty()) {
				// 	auto top = *tmps.begin();
				// 	tmps.erase(top);
				// 	sum2 += -top;
				// 	ds.insert(-top);
				// }
				// while (ds.size() == ls.size() && ds.size()>0 && tmps.size()>0) {
				// 	int x1 = -(*tmps.begin());
				// 	int x2 = *ds.begin();
				// 	if (x1 > x2) {
				// 		ds.erase(x2);
				// 		sum2 -= x2;
				// 		tmps.erase(x1);
				// 		tmps.insert(-x2);
				// 		ds.insert(x1);
				// 		sum2 += x1;
				// 	} else {
				// 		break;
				// 	}
				// }
			} else {
				d = -d;
				sum -= d;
				if (*ls.begin() == d) {
					ls.erase(d);
					if (ls.size() > 0) {
						int x = *ls.begin();
						if (tmps.find(x) != tmps.end()) {
							tmps.erase(x);
						} else {
							ds.erase(x);
							sum2 -= x;
						}
					}
				} else {
					ls.erase(d);
					if (tmps.find(d) != tmps.end()) {
						tmps.erase(d);
					} else {
						ds.erase(d);
						sum2 -= d;
					}
				}
				while(ds.size() > ls.size()) {
					auto top = *ds.begin();
					sum2 -= top;
					ds.erase(top);
					tmps.insert(top);
				}
				while(ds.size() < ls.size() && !tmps.empty()) {
					auto top = *tmps.rbegin();
					tmps.erase(top);
					ds.insert(top);
					sum2 += top;
				}
			}
		}
		printf("%lld\n", sum+sum2);
	}
	return 0;
}
