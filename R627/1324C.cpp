#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#define N 5002
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t,n;
string s;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>s;
		n = s.size();
		int ans = 0;
		int pre = n+1;
		for (int i = n; i >= 1; --i) {
			if (s[i-1] == 'R') {
				ans = max(ans, pre-i);
				pre = i;
			}
		}
		ans = max(ans, pre);
		cout<<ans<<endl;
	}
	return 0;
}
