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
#define N 150
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n;
string s;
int sum[N][2];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		cin>>s;
		if (n==1) {
			cout<<0<<endl;
		} else {
			if (s[0]=='<' && s.back()=='>') {
				int cnt1=0;
				int cnt2=0;
				for (int i = 0; i < n; ++i) {
					if (s[i]=='<') cnt1++;
					else break;
				}
				for (int i = n-1; i >= 0; --i) {
					if (s[i]=='>') cnt2++;
					else break;
				}
				cout<<min(cnt1, cnt2)<<endl;
			} else {
				cout<<0<<endl;
			}
		}
	}
	return 0;
}
