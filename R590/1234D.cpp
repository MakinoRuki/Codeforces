#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#define N 100005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
string s;
int q;
int n;
int BIT[26][N];
int lowbit(int x) {
	return x&(-x);
}
void update(int id, int pos, int val) {
	while(pos <= n) {
		BIT[id][pos] += val;
		pos += lowbit(pos);
	}
}
int query(int id, int pos) {
	int res=0;
	while(pos > 0) {
		res += BIT[id][pos];
		pos -= lowbit(pos);
	}
	return res;
}
int main() {
	cin>>s;
	n = s.size();
	for (int i = 1; i <= n; ++i) {
		update(s[i-1]-'a', i, 1);
	}
	cin>>q;
	for (int i = 0; i < q; ++i) {
		int t;
		cin>>t;
		if (t == 1) {
			int pos;
			string c;
			cin>>pos>>c;
			update(s[pos-1]-'a', pos, -1);
			update(c[0]-'a', pos, 1);
			s[pos-1] = c[0];
		} else {
			int l, r;
			cin>>l>>r;
			int cnt=0;
			for (int i = 0; i < 26; ++i) {
				int res= query(i, r) - query(i, l-1);
				if (res) cnt++;
			}
			cout<<cnt<<endl;
		}
	}
	return 0;
}
