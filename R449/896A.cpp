#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>
#include <deque>
#include <cmath>
#define N 100005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int inf = 1000000000;
int n, m;
int h;
int q;
ll k;
ll dp[N];
int main() {
	cin>>q;
	memset(dp, 0, sizeof(dp));
	string s = "What are you doing at the end of the world? Are you busy? Will you save us?";
	string t1 = "What are you doing while sending \"";
	string t2 = "\"? Are you busy? Will you send \"";
	string t3 = "\"?";
	dp[0] = (int)s.size();
	for (int i = 1; i <= 100000; ++i) {
		if (dp[i-1] >= 1000000000000000000LL) {
			dp[i] = 2000000000000000000LL;
		} else {
			dp[i] = 2LL*dp[i-1] + (ll)t1.size() + (ll)t2.size() + (ll)t3.size();
		}
	}
	while(q-->0) {
		scanf("%d%lld", &n, &k);
		if (k > dp[n]) {
			printf("%c", '.');
			continue;
		}
		while(true) {
			if (n == 0) {
				printf("%c", s[k-1]);
				break;
			}
			if (k <= (ll)t1.size()) {
				printf("%c", t1[k-1]);
				break;
			}
			k -= (ll)t1.size();
			if (k <= dp[n-1]) {
				n--;
				continue;
			}
			k -= dp[n-1];
			if (k <= (ll)t2.size()) {
				printf("%c", t2[k-1]);
				break;
			}
			k -= (ll)t2.size();
			if (k <= dp[n-1]) {
				n--;
				continue;
			}
			k -= dp[n-1];
			printf("%c", t3[k-1]);
			break;
		}
	}
	cout<<endl;
	return 0;
}

/*myturn.ca.gov*/
