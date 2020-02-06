#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 200005
using namespace std;
string s;
int q;
int BIT[26][N];
int n;
int lowbit(int x) {
	return x & (-x);
}
void update(int id, int p) {
	while(p <= n) {
		BIT[id][p] += 1;
		p += lowbit(p);
	}
}
int query(int id, int p) {
	int sum=0;
	while(p > 0) {
		sum += BIT[id][p];
		p -= lowbit(p);
	}
	return sum;
}
int main() {
	cin>>s;
	n = s.size();
	memset(BIT, 0, sizeof(BIT));
	for (int i = 1; i <= n; ++i) {
		update(s[i-1]-'a', i);
	}
	cin>>q;
	for (int i =1 ; i<= q; ++i) {
		int l, r;
		cin>>l>>r;
		if (r == l) {
			cout<<"Yes"<<endl;
		} else {
			if (s[r-1] != s[l-1]) {
				cout<<"Yes"<<endl;
			} else {
				int cnt = 0;
				for (int i = 0; i < 26; ++i) {
					if (query(i, r) - query(i, l-1) > 0) {
						cnt++;
					}
				}
				if (cnt > 2) {
					cout<<"Yes"<<endl;
				} else {
					cout<<"No"<<endl;
				}
			}
		}
	}
	return 0;
}
