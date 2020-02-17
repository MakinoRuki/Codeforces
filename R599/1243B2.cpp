#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 1002
using namespace std;
int k, n;
string s,t;
int main() {
	cin>>k;
	for (int c = 1; c <= k; ++c) {
		cin>>n>>s>>t;
		vector<int> ans;
		int i;
		for (i = 0; i < n; ++i) {
			if (s[i] == t[i]) continue;
			bool found = false;
			for (int j = i + 1; j < n; ++j) {
				if (t[j] == t[i]) {
					swap(t[j], s[i]);
					ans.push_back(i+1);
					ans.push_back(j+1);
					found=true;
					break;
				}
			}
			if (found) continue;
			for (int j = i + 1; j < n; ++j) {
				if (s[j] == t[i]) {
					swap(s[j], t[j]);
					ans.push_back(j+1);
					ans.push_back(j+1);
					swap(t[j], s[i]);
					ans.push_back(i+1);
					ans.push_back(j+1);
					found=true;
					break;
				}
			}
			if (found) continue;
			break;
		}
		if (i < n) {
			cout<<"No"<<endl;
		} else {
			cout<<"Yes"<<endl;
			cout<<ans.size()/2<<endl;
			for (int i = 0; i < ans.size(); i += 2) {
				cout<<ans[i]<<" "<<ans[i+1]<<endl;
			}
		}
	}
	return 0;
}
