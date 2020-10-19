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
#define N 300005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t,n;
string s;
bool ok[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>s;
		vector<pair<int,int>> vs;
		vs.clear();
		int cnt=0;
		n=s.size();
		int id=0;
		for (int i = 0; i < n; ++i) {
			if (i==0) {
				id=s[i]-'A';
				cnt=1;
			} else {
				if (s[i] != s[i-1]) {
					vs.push_back(make_pair(id, cnt));
					id=s[i]-'A';
					cnt=1;
				} else {
					cnt++;
				}
			}
		}
		if (cnt>0) {
			vs.push_back(make_pair(id, cnt));
		}
		int tot=0;
		int bs=0;
		for (int i = vs.size()-1; i>=0; --i) {
			if (vs[i].first==0) {
				if (vs[i].second<=bs) {
					bs -= vs[i].second;
				} else {
					tot += vs[i].second-bs;
					bs=0;
				}
			} else {
				bs += vs[i].second;
			}
		}
		if (bs%2) tot++;
		printf("%d\n", tot);
	}
	return 0;
}
