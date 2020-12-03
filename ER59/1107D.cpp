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
#define N 5202
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n;
vector<string> mat;
int sum[N][N];
int main() {
	cin>>n;
	mat.clear();
	for (int i = 0; i < n; ++i) {
		string s;
		cin>>s;
		string t="";
		for (int j = 0; j < n/4; ++j) {
			int x;
			if (s[j]>='0' && s[j]<='9') {
				x=s[j]-'0';
			} else {
				x=s[j]-'A'+10;
			}
			for (int k = 3; k >= 0; --k) {
				if ((1<<k)&x) {
					t.push_back('1');
				} else {
					t.push_back('0');
				}
			}
		}
		mat.push_back(t);
	}
	memset(sum, 0, sizeof(sum));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			sum[i][j] = sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+(mat[i-1][j-1]=='1');
		}
	}
	int ans=1;
	for (int k = 2; k <= n; ++k) {
		if (n%k==0) {
			bool ok=true;
			for (int i = k; i <= n; i += k) {
				for (int j = k; j <= n; j += k) {
					int tot= sum[i][j]-sum[i-k][j]-sum[i][j-k]+sum[i-k][j-k];
					if (tot != 0 && tot != k*k) {
						ok=false;
						break;
					}
				}
				if (!ok) break;
			}
			if (ok) {
				ans=max(ans, k);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
