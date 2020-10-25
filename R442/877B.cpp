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
#define N 5002
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n;
string a,b;
string s;
int sa[N], sb[N];
int main() {
	cin>>s;
	n=s.size();
	memset(sa, 0, sizeof(sa));
	memset(sb, 0, sizeof(sb));
	for (int i = 1; i <= n; ++i) {
		sa[i]=sa[i-1]+(s[i-1]=='a');
	}
	for (int i = 1; i <= n; ++i) {
		sb[i]=sb[i-1]+(s[i-1]=='b');
	}
	int ans=0;
	for (int i = 0; i <= n; ++i) {
		for (int j = i; j <= n; ++j) {
			int tmp=0;
			if (i>=1) tmp += i-sb[i];
			if (j>=i+1) tmp += j-i-sa[j]+sa[i];
			if (n>=j+1) tmp += n-j-sb[n]+sb[j];
			ans=max(ans, tmp);
		}
	}
	cout<<ans<<endl;
	return 0;
}
