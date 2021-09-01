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
#include <time.h>
#define eps 1e-7
#define M 52
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n;
int m;
string s;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d", &n, &m);
		cin>>s;
		vector<int> ids;
		ids.clear();
		for (int i = 0; i < n; ++i) {
			if (s[i] == '1') {
				if (!ids.empty()) {
					if (ids[0] == 0) {
						for (int j = 1; j <= min(m, (int)ids.size()); ++j) {
							s[ids[ids.size()-j]] = '1';
						}
					} else {
						int l = 0, r = ids.size()-1;
						int cnt=1;
						while(l < r && cnt <= m) {
							s[ids[l]] = '1';
							s[ids[r]] = '1';
							l++;
							r--;
							cnt++;
						}
					}
					ids.clear();
				}
			} else {
				ids.push_back(i);
			}
		}
		if (!ids.empty()) {
			if (ids[0] > 0) {
				for (int i = 0; i < min((int)ids.size(), m); ++i) {
					s[ids[i]] = '1';
				}
			}
		}
		cout<<s<<endl;
	}
  return 0;
}
