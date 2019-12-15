#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <map>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#define N 200020
#define inf 1000000000
using namespace std;
int t;
int main() {
	cin>>t;
	for (int cas = 0; cas <t; ++cas){ 
		string s,c;
		cin>>s>>c;
		if (s < c) {
			cout<<s<<endl;
		} else {
			int ns = s.size();
			int nc = c.size();
			if (ns < nc) {
				int cnt=0;
				int idx1=-1;
				int idx2=-1;
				for (int i = 0; i < ns; ++i) {
					if (s[i] != c[i]) {
						cnt++;
						if (idx1<0) idx1=i;
						else if (idx2<0) idx2=i;
					}
				}
				if (cnt == 2) {
					if (s[idx2] == c[idx1] && s[idx1] == c[idx2]) {
						swap(s[idx1], s[idx2]);
						cout<<s<<endl;
						continue;
					}
				}
			}
			string ts = s;
			for (int i = 0; i < min(ns, nc); ++i) {
				int j;
				for (j = i+1; j < ns; ++j) {
					if (s[j] < c[i]) {
						break;
					}
				}
				if (j < ns) {
					swap(s[j], s[i]);
					break;
				} else {
					if (s[i] > c[i]) {
						break;
					}
				}
			}
			if (s < c) {
				cout<<s<<endl;
			} else {
				// 处理情况：可以把位置i换成相等，这样后面第一个不相等的位置是小于的，就也合法。
				s = ts;
				for (int i = 0; i < min(ns, nc); ++i) {
					if (s[i] != c[i]) {
						int j;
						for (j = ns-1; j > i; --j) {
							if (s[j] == c[i]) {
								break;
							}
						}
						if (j > i) {
							swap(s[j], s[i]);
						}
						break;
					}
				}
				if (s < c) cout<<s<<endl;
				else cout<<"---"<<endl;
			}
		}
	}
	return 0;
}
