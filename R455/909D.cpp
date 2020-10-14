#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <cmath>
#include <queue>
#define eps 1e-7
#define M 20005
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n,m;
string s;
int main() {
	cin>>s;
	vector<pair<int,int>> v;
	v.clear();
	n=s.size();
	for (int i = 0; i < n; ++i) {
		if (i==0) {
			v.push_back(make_pair(s[i]-'a',1));
		} else {
			if (s[i]-'a'==v.back().first) {
				v.back().second++;
			} else {
				v.push_back(make_pair(s[i]-'a',1));
			}
		}
	}
	int ans=0;
	while(v.size()>1) {
		vector<pair<int,int>> v2;
		v2.clear();
		ans++;
		for (int i = 0; i < v.size(); ++i) {
		//	cout<<"i="<<i<<endl;
			if (i==0) {
				if (i+1<v.size() && v[i].first != v[i+1].first) {
					if (v[i].second-1<=0) {
			//			cout<<"i1="<<i<<endl;
						continue;
					} else {
						v2.push_back(make_pair(v[i].first, v[i].second-1));
					}
				} else {
					v2.push_back(v[i]);
				}
			} else if (i == v.size()-1) {
				if (i-1>=0 && v[i].first != v[i-1].first) {
					if (v[i].second-1<=0) {
						continue;
					} else {
						v2.push_back(make_pair(v[i].first, v[i].second-1));
					}
				} else {
					v2.push_back(v[i]);
				}
			} else {
				int det=0;
				if (v[i-1].first != v[i].first) {
					det++;
				}
				if (v[i+1].first != v[i].first) {
					det++;
				}
				if (v[i].second-det<=0) {
					continue;
				} else {
					v2.push_back(make_pair(v[i].first, v[i].second-det));
				}
			}
		}
		v.clear();
		for (int i = 0; i < v2.size(); ++i) {
			if (i==0) v.push_back(v2[i]);
			else {
				if (v.back().first != v2[i].first) {
					v.push_back(v2[i]);
				} else {
					v.back().second += v2[i].second;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
