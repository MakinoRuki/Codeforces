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
#define M 1000005
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
string s;
int t;
int n;
int a[N];
vector<int> getv(int sd) {
	deque<int> dq;
	vector<int> res;
	res.clear();
	int l = 1, r = n;
	for (int i = 1; i <= n; ++i) {
		if (i == n-1) {
			dq.push_front(a[l]);
			dq.push_back(a[r]);
			break;
		}
		if (i == 1) {
			if (!sd) {
				dq.push_back(a[l++]);
			} else {
				dq.push_back(a[r--]);
			}
		} else {
			if (a[l] >= a[r]) {
				dq.push_front(a[l++]);
			} else {
				dq.push_back(a[r--]);
			}
		}
	}
	while(!dq.empty()) {
		res.push_back(dq.front());
		dq.pop_front();
	}
	return res;
}
bool check2(vector<int>& v) {
	for (int i = 0; i < v.size(); ++i) {
		if (v[i] != a[i+1]) {
			return false;
		}
	}
	return true;
}
bool check(vector<int>& v) {
	int l = 0, r = n-1;
	vector<int> res;
	res.clear();
	deque<int> dq;
	for (int i =1; i < n; ++i) {
		if (v[l] <  v[r]) {
			dq.push_front(v[l++]);
		} else {
			dq.push_back(v[r--]);
		}
	}
	dq.push_front(v[l]);
	while(!dq.empty()) {
		res.push_back(dq.front());
		dq.pop_front();
	}
	if (check2(res)) {
		return true;
	}
	for (int i =1; i < n; ++i) {
		dq.push_back(res[i]);
	}
	dq.push_back(res[0]);
	res.clear();
	while(!dq.empty()) {
		res.push_back(dq.front());
		dq.pop_front();
	}
	if (check2(res)) {
		return true;
	}
	return false;
}
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		auto v = getv(0);
		if (check(v)) {
			for (int i = 0; i < v.size(); ++i) {
				printf("%d", v[i]);
				if (i < v.size()-1) cout<<" ";
				else cout<<endl;
			}
			continue;
		}
		v = getv(1);
		if (check(v)) {
			for (int i = 0; i < v.size(); ++i) {
				printf("%d", v[i]);
				if (i < v.size()-1) cout<<" ";
				else cout<<endl;
			}
			continue;
		}
		puts("-1");
	}
  return 0;
}

