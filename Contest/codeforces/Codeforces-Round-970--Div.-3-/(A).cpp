#include<bits/stdc++.h>

using namespace std;

bool ok(vector<int> vec) {
	int sum = 0;
	for(int i = vec.size(); i--; ) sum += vec[i];
	
	if(sum & 1) return false;
	
	sum >>= 1;
	
	for(int k = 1 << vec.size(); k--; ) {
		int s = 0;
		for(int i = vec.size(); i--; ) if((k >> i) & 1) s += vec[i];
		if(s == sum) return true;
	}
	return false;
}

int main() {
	
	int t; scanf("%d", &t);
	while(t--) {
		int a, b; scanf("%d %d", &a, &b);
		
		vector<int> vec;
		while(a--) vec.push_back(1);
		while(b--) vec.push_back(2);
		
		if(ok(vec)) puts("YES");
		else puts("NO");
	}
	return 0;
}
