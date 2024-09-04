#include<bits/stdc++.h>

using namespace std;

vector<int> vec(20);

bool ok() {
	for(int i = 1; i < vec.size(); i++) {
		if(vec[i - 1] == vec[i]) return false;
	}
	return true;
}

void gen() {
	do {
		random_shuffle(vec.begin(), vec.end());
	} while(!ok());
	for(int x : vec) cout<<x<<' '; cout<<endl;
}

int main() {
	freopen("result.txt", "w", stdout);
	
	srand(time(0));
	for(int i = 20; i--; ) vec[i] = i % 5;
	
	cout<<"How many arrays do you need ?"<<endl;
	int n; scanf("%d", &n);
	while(n--) gen();
	
	return 0;
}