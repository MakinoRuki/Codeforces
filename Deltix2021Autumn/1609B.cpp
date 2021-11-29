#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#define M 20000005
#define N 20
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
//string s;
string s;
int t;
int n, q, m, k;
int a[N];
int main() {
	cin>>n>>q;
	cin>>s;
	int tot=0;
	for (int i=0; i < n; ++i) {
		if (i+2 < n && s.substr(i, 3) == "abc") {
			tot++;
		}
	}
	while(q-->0) {
		int pos;
		string ss;
		scanf("%d", &pos);
		int i = pos-1;
		cin>>ss;
		bool f1=false,f2=false,f3=false;
		bool g1=false,g2=false,g3=false;
		if (i-2 >= 0 && s.substr(i-2,3) == "abc") {
			f1=true;
		}
		if (i-1>=0 && i+1<n && s.substr(i-1, 3) == "abc") {
			f2=true;
		}
		if (i+2<n && s.substr(i, 3) == "abc") {
			f3=true;
		}
		s[pos-1] = ss[0];
		if (i-2 >= 0 && s.substr(i-2,3) == "abc") {
			g1=true;
		}
		if (i-1>=0 && i+1<n && s.substr(i-1, 3) == "abc") {
			g2=true;
		}
		if (i+2<n && s.substr(i, 3) == "abc") {
			g3=true;
		}
		if (f1 && !g1) tot--;
		else if (!f1 && g1) tot++;
		if (f2 && !g2) tot--;
		else if (!f2 && g2) tot++;
		if (f3 && !g3) tot--;
		else if (!f3 && g3) tot++;
		printf("%d\n", tot);
	}
  return 0;
}

