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
#define M 21
#define N 52
#define SZ 200000002
#define eps 1e-7
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n;
int main() {
	cin>>n;
	set<int> ss;
	ss.clear();
	int cnt=0;
	int ans=0;
	vector<int> tmp;
	tmp.clear();
	for (int i = 1; i <= 2*n; ++i) {
		string op;
		cin>>op;
		int x;
		if (op == "remove") {
			cnt++;
			if (tmp.empty()) {
				ss.erase(cnt);
			} else {
				if (tmp.back() != cnt) {
					ans++;
					for (int j = 0; j < tmp.size(); ++j) {
						ss.insert(tmp[j]);
					}
					tmp.clear();
					ss.erase(cnt);
				} else {
					tmp.pop_back();
				}
			}
		} else {
			scanf("%d", &x);
			tmp.push_back(x);
		}
	}
	cout<<ans<<endl;
  return 0;
}
