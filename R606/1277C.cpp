#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
#define N 200005
using namespace std;
typedef long long ll;
int t;
int main() {
	cin>>t;
	for (int cas=1;cas<=t; ++cas) {
		string s;
		cin>>s;
		vector<int>idx;
		idx.clear();
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == 'o') {
				if (i-1>=0 &&i-2>=0 && s[i-1]=='w' && s[i-2] == 't' &&i+1<s.size() && i+2<s.size() && s[i+1]=='n' && s[i+2]=='e') {
					idx.push_back(i);
				}
			}
		}
	//	cout<<idx.size()<<endl;
		set<int> idxs(idx.begin(), idx.end());
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == 'w') {
				if (i-1 >=0 && s[i-1]=='t' &&i+1<s.size() &&s[i+1]=='o') {
					if (idxs.find(i+1) == idxs.end()) {
					//	cout<<"i="<<i<<endl;
						idx.push_back(i);
					}
				}
			} else if (s[i] == 'n') {
				if (i-1>=0&&s[i-1]=='o' && i+1<s.size() && s[i+1]=='e') {
					if (idxs.find(i-1) == idxs.end()) {
					//	cout<<"i2="<<i<<endl;
						idx.push_back(i);
					}
				}
			}
		}
		cout<<idx.size()<<endl;
		for (int i = 0; i < idx.size(); ++i) {
			cout<<idx[i]+1;
			if (i < idx.size()-1) cout<<" ";
		}
		cout<<endl;
	}
	return 0;
}
