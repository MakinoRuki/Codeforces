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
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int q;
int t, n;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		int x,y;
		scanf("%d%d", &x, &y);
		string s;
		cin>>s;
		n = s.size();
		int dx = 0, dy = 0;
		int un=0,dn=0,rn=0,ln=0;
		for (int i = 0; i < n; ++i) {
			if (s[i] == 'U') {
				dy++;
				un++;
			} else if (s[i] == 'D') {
				dy--;
				dn++;
			} else if (s[i] == 'L') {
				dx--;
				ln++;
			} else {
				dx++;
				rn++;
			}
		}
		int dx2 = x-dx;
		int dy2 = y-dy;
	//	cout<<dx2<<" "<<dy2<<endl;
		if (dx2 >= 0 && dy2 >= 0) {
			if (ln >= dx2 && dn >= dy2) {
				puts("YES");
			} else {
				puts("NO");
			}
		} else if (dx2 >=0 && dy2<0) {
			if (ln >= dx2 && un >= -dy2) {
				puts("YES");
			} else {
				puts("NO");
			}
		} else if (dx2 < 0 && dy2>=0) {
			if (rn >= -dx2 && dn>=dy2) {
				puts("YES");
			} else {
				puts("NO");
			}
		} else {
			if (rn >= -dx2 && un >= -dy2) {
				puts("YES");
			} else {
				puts("NO");
			}
		}
	}
  return 0;
}
