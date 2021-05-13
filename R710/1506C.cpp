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
#define M 25
#define N 500005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, k;
string s;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		string a,b;
		cin>>a>>b;
		int ans=0;
		for (int i = 0; i < a.size(); ++i) {
			for (int j = 0; j < b.size(); ++j) {
				int len=0;
				for (int k = 0; i + k < a.size() && j + k < b.size(); ++k) {
					if (a[i+k] != b[j+k]) {
						break;
					}
					len++;
				}

				ans = max(ans, len);
			}
		}
		printf("%d\n", (int)a.size() + (int)b.size() - 2*ans);
	}
  return 0;
}
