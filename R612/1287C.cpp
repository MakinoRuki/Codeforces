#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#define N 102
using namespace std;
typedef long long ll;
const ll inf = 2000000000000000000LL;
int n;
int p[N];
int main() {
	cin>>n;
	vector<int> os;
	vector<int> es;
	os.clear();
	es.clear();
	unordered_set<int> ex;
	ex.clear();
	for (int i = 0; i < n; ++i) {
		cin>>p[i];
		if (p[i] > 0) ex.insert(p[i]);
	}
	for (int i = 1; i <= n; ++i) {
		if (ex.find(i) == ex.end()) {
			if (i & 1) {
				os.push_back(i);
			} else {
				es.push_back(i);
			}
		}
	}
	int tot =0;
	for (int i = 0; i < n; ++i) {
		if (p[i] == 0) {
			tot++;
		}
	}
	if (tot == n) {
		if (n == 1) cout<<0<<endl;
		else cout<<1<<endl;
		return 0;
	}
	// cout<<os.size()<<" "<<os[0]<<endl;
	// cout<<es.size()<<" "<<es[0]<<endl;
	vector<pair<int, int>> rk;
	vector<pair<int, int>> rk2;
	rk.clear();
	rk2.clear();
	for (int i = 0; i < n; ++i) {
		if (p[i]) continue;
		int l = i;
		int r = i;
		while(r < n && (p[r] == 0)) {
			r++;
		}
		if (l > 0 && r <= n-1) {
			if ((p[l-1] % 2 == 0) && (p[r] % 2 == 0)) {
				rk.push_back(make_pair(r-l, l));
			}
		} else if (l > 0 && r >= n) {
			if (p[l-1] % 2 == 0) {
				rk2.push_back(make_pair(r-l, l));
			}
		} else if (r <= n-1 && l <= 0) {
			if (p[r] % 2 == 0) {
				rk2.push_back(make_pair(r-l, l));
			}
		}
		i = r-1;
	}
//	cout<<rk.size()<<" "<<rk2.size()<<endl;
	if (rk.size()) sort(rk.begin(), rk.end());
	if (rk2.size()) sort(rk2.begin(), rk2.end());
	for (int i = 0; i < rk.size(); ++i) {
		int id = rk[i].second;
		int len = rk[i].first;
		if (es.size() >= len) {
			for (int j = id; j < id + len; ++j) {
				p[j] = es.back();
				es.pop_back();
			}
		} else {
			break;
		}
	}
	for (int i = 0; i < rk2.size(); ++i) {
		int id = rk2[i].second;
		int len = rk2[i].first;
		if (es.size() >= len) {
			for (int j = id; j < id+len; ++j) {
				p[j] = es.back();
				es.pop_back();
			}
		} else {
			break;
		}
	}
	rk.clear();
	rk2.clear();
	for (int i = 0; i < n; ++i) {
		if (p[i]) continue;
		int l = i;
		int r = i;
		while(r < n && (p[r] == 0)) {
			r++;
		}
		if (l > 0 && r <= n-1) {
			if ((p[l-1] % 2) && (p[r] % 2)) {
				rk.push_back(make_pair(r-l, l));
			}
		} else if (l > 0 && r >= n) {
			if (p[l-1] % 2) {
				rk2.push_back(make_pair(r-l, l));
			}
		} else if (r <= n-1 && l <= 0) {
			if (p[r] % 2) {
				rk2.push_back(make_pair(r-l, l));
			}
		}
		i = r-1;
	}
	// cout<<"==="<<endl;
	// cout<<rk.size()<<" "<<rk2.size()<<endl;
	if (rk.size()) sort(rk.begin(), rk.end());
	if (rk2.size()) sort(rk2.begin(), rk2.end());
	for (int i = 0; i < rk.size(); ++i) {
		int id = rk[i].second;
		int len = rk[i].first;
		if (os.size() >= len) {
			for (int j = id; j < id + len; ++j) {
				p[j] = os.back();
				os.pop_back();
			}
		} else {
			break;
		}
	}
//	cout<<"aaaa"<<" "<<rk2.size()<<endl;
	for (int i = 0; i < rk2.size(); ++i) {
		int id = rk2[i].second;
		int len = rk2[i].first;
		if (os.size() >= len) {
			for (int j = id; j < id+len; ++j) {
				p[j] = os.back();
				os.pop_back();
			}
		} else {
			break;
		}
	}
	// cout<<"==="<<endl;
	// for (int i = 0; i < n; ++i) {
	// 	cout<<i<<" "<<p[i]<<endl;
	// }
	while(true) {
		int i;
		for (i = 0; i < n; ++i) {
			if (p[i] == 0) {
				if (i-1 >= 0 && p[i-1] > 0) {
					break;
				} else if (i + 1 < n && p[i+1] > 0) {
					break;
				}
			}
		}
		if (i < n) {
			if (i - 1 >= 0 && p[i-1]) {
				if (p[i-1] & 1) {
					if (os.size()) {
						p[i] = os.back();
						os.pop_back();
					} else {
						p[i] = es.back();
						es.pop_back();
					}
				} else {
					if (es.size()) {
						p[i] = es.back();
						es.pop_back();
					} else {
						p[i] = os.back();
						os.pop_back();
					}
				}
			} else if (i+1 < n && p[i+1]) {
				if (p[i+1] & 1) {
					if (os.size()) {
						p[i] = os.back();
						os.pop_back();
					} else {
						p[i] = es.back();
						es.pop_back();
					}
				} else {
					if (es.size()) {
						p[i] = es.back();
						es.pop_back();
					} else {
						p[i] = os.back();
						os.pop_back();
					}
				}
			}
		} else {
			break;
		}
	}
	int cnt=0;
	for (int i = 1; i < n; ++i) {
		if ((p[i-1] + p[i]) % 2) {
			cnt++;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
