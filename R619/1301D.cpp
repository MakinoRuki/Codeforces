#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#define N 400005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t;
ll n,m,k;
int a[N];
int main() {
	cin>>n>>m>>k;
	if (k > 4 *n *m -2 *n - 2*m) {
		cout<<"NO"<<endl;
	} else {
		cout<<"YES"<<endl;
		vector<pair<int, string>> res;
		res.clear();
		if (m == 1) {
			if (n == 1) {
				cout<<0<<endl;
				return 0;
			}
			if (k >= n-1) {
				res.push_back(make_pair(n-1, "D"));
				k -= n-1;
			} else if (k) {
				res.push_back(make_pair(k, "D"));
				k -= k;
			}
			if (k) res.push_back(make_pair(k, "U"));
			cout<<res.size()<<endl;
			for (int i = 0; i < res.size(); ++i) {
				cout<<res[i].first<<" "<<res[i].second<<endl;
			}
			return 0;
		}
		if (k >= m-1) {
			res.push_back(make_pair(m-1, "R"));
			k -= m-1;
		} else if (k) {
			res.push_back(make_pair(k, "R"));
			k -= k;
		}
		if (k >= m-1) {
			res.push_back(make_pair(m-1, "L"));
			k -= m-1;
		} else if (k) {
			res.push_back(make_pair(k, "L"));
			k -= k;
		}
		for (int i = 1; i < n; ++i) {
			if (k) {
				res.push_back(make_pair(1, "D"));
				k--;
			} else {
				break;
			}
			if (k >= 3 * (m-1)) {
				res.push_back(make_pair(m-1, "RUD"));
				k -= 3*(m-1);
			} else {
				int b = k / 3;
				if (b) {
					res.push_back(make_pair(b, "RUD"));
				}
				k -= b * 3;
				if (k == 1) {
					res.push_back(make_pair(1, "R"));
				} else if (k == 2) {
					res.push_back(make_pair(1, "RU"));
				}
				k = 0;
			}
			if (k >= m-1) {
				res.push_back(make_pair(m-1, "L"));
				k -= m-1;
			} else if (k) {
				res.push_back(make_pair(k, "L"));
				k -= k;
			}
		}
		if (k) {
			res.push_back(make_pair(k, "U"));
		}
		cout<<res.size()<<endl;
		for (int i = 0; i < res.size(); ++i) {
			cout<<res[i].first<<" "<<res[i].second<<endl;
		}
	}
	return 0;
}
