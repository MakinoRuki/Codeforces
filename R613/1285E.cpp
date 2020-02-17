#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <unordered_set>
#include <algorithm>
#define N 200005
using namespace std;
int t;
int n;
int cnt[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>n;
		vector<pair<pair<int,int>, int>> rks;
		rks.clear();
		vector<pair<int,int>> segs;
		segs.clear();
		for (int i = 0; i < n; ++i) {
			int l, r;
			cin>>l>>r;
			segs.push_back(make_pair(l, r));
			rks.push_back(make_pair(make_pair(l, -1), i));
			rks.push_back(make_pair(make_pair(r, 1), i));
		}
		sort(segs.begin(), segs.end());
		int tot=1;
		int b = segs[0].first;
		int e = segs[0].second;
		for (int i = 0; i < n; ++i) {
			if (segs[i].first > e) {
				tot++;
				b = segs[i].first;
				e = segs[i].second;
			} else {
				b = min(segs[i].first, b);
				e = max(e, segs[i].second);
			}
		}
		memset(cnt, 0, sizeof(cnt));
		sort(rks.begin(), rks.end());
		int num=0;
		unordered_set<int> ss;
		ss.clear();
		for (int i = 0; i < rks.size(); ++i) {
			int v = rks[i].first.first;
			int f = rks[i].first.second;
			int id = rks[i].second;
		//	cout<<v<<" "<<f<<" "<<id<<endl;
			if (f < 0) {
				ss.insert(id);
				num++;
			} else {
				num--;
				ss.erase(id);
				if (num == 1) {
				//	cout<<i<<" "<<rks[i+1].first<<" "<<rks[i].
					if (i + 1< rks.size() && rks[i+1].first.second < 0) {
						cnt[*ss.begin()]++;
					}
				}
			}
		//	cout<<num<<endl;
		}
		int maxadd = 0;
		for (int i = 0; i <n; ++i) {
			maxadd = max(maxadd, cnt[i]);
		}
		if (maxadd == 0) {
			if (tot == n) cout<<n-1<<endl;
			else cout<<tot<<endl;
		} else {
			cout<<tot+maxadd<<endl;
		}
	}
	return 0;
}
