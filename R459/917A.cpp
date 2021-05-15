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
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n;
string s;
bool dfs(string& t, int cur, int sum) {
	if (cur == t.size()) {
		return sum == 0;
	}
	if (sum < 0) return false;
	if (t[cur] == '(' || t[cur] == '?') {
		if (dfs(t, cur+1, sum+1)) return true;
	}
	if (t[cur] == ')' || t[cur] == '?') {
		if (dfs(t, cur+1, sum-1)) return true;
	}
	return false;
}
int main() {
	cin>>s;
	n = s.size();

	// srand (time(NULL));
	// s = "";
	// cin>>n;
	// for (int i = 0; i < n; ++i) {
	// 	int x = rand()%3;
	// 	if (x == 0) s.push_back('(');
	// 	else if (x == 1) s.push_back(')');
	// 	else s.push_back('?');
	// }
	// cout<<"s="<<s<<endl;

	// int tot=0;
	// for (int i = 0; i < n; ++i) {
	// 	for (int j = i; j < n; ++j) {
	// 		string t = s.substr(i, j-i+1);
	// 		if (dfs(t, 0, 0)) {
	// 		//	cout<<"t = "<<t<<endl;
	// 			tot++;
	// 		}
	// 	}
	// }

	// cout<<"tot="<<tot<<endl;

	int sum = 0, c1 = 0, c2 = 0;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		sum = 0;
		c1 = 0;
		c2 = 0;
		int res = 0;
		for (int j = i; j < n; ++j) {
			if (s[j] == '(') {
				sum++;
			} else if (s[j] == ')') {
				sum--;
				if (sum < 0) {
					if (c1 > 0) {
						c1--;
						sum++;
					} else if (c2 > 0) {
						c2--;
						sum += 2;
					} else {
						break;
					}
				}
			} else {
				c1++;
				if (sum > 0) {
					sum--;
					c1--;
					c2++;
				}
			}
			if (sum == 0 && (c1%2==0)) {
				res++;
				ans++;
			}
			//if (i == 4) cout<<"j="<<j<<" "<<res<<endl;
		}
		//cout<<"i="<<i<<" "<<res<<endl;
	}
	cout<<ans<<endl;
  return 0;
}
