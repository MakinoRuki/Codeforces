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
#define M 22
#define N 200
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m;
int a[N];
string s;
int main() {
	cin>>s;
	n = (int)s.size();
	vector<char> cv = {'R', 'G', 'B', 'Y'};
	for (int i = 0; i < cv.size(); ++i) {
		for (int j = 0; j < cv.size(); ++j) {
			for (int k = 0; k < cv.size(); ++k) {
				if (i == j || j == k || i == k) {
					continue;
				}
				string t = "";
				t.push_back(cv[i]);
				t.push_back(cv[j]);
				t.push_back(cv[k]);
				int rc = 0, gc = 0, bc = 0, yc = 0;
				bool ok= true;
				for (int idx = 0; idx < n; ++idx) {
					if (idx >= 3) {
						int idx2 = 0;
						for (idx2 = 0; idx2 < 4; ++idx2) {
							if (t[idx-1] != cv[idx2] && t[idx-2] != cv[idx2] && t[idx-3] != cv[idx2]) {
								break;
							}
						}
						t.push_back(cv[idx2]);
					}
					if (s[idx] != '!' && s[idx] != t[idx]) {
						ok=false;
						break;
					}
					if (s[idx] == '!') {
						if (t[idx] == 'R') rc++;
						else if (t[idx] == 'G') gc++;
						else if (t[idx] == 'B') bc++;
						else if (t[idx] == 'Y') yc++;
					}
				}
				if (ok) {
					cout<<rc<<" "<<bc<<" "<<yc<<" "<<gc<<endl;
					return 0;
				}
			}
		}
	}
  return 0;
}
