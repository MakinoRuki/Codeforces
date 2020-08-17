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
#define N 100005
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int t, n;
string s;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>s;
		n = s.size();
		vector<int> os;
		os.clear();
		int cnt=0;
		for (int i = 0; i < n; ++i) {
			if (s[i] == '1') {
				cnt++;
			} else {
				if (cnt>0) os.push_back(cnt);
				cnt=0;
			}
		}
		if (cnt>0) {
			os.push_back(cnt);
		}
		sort(os.begin(), os.end());
		reverse(os.begin(), os.end());
		int tot =0;
		for (int i = 0; i < os.size(); i += 2) {
			tot += os[i];
		}
		printf("%d\n", tot);
	}
	return 0;
}
