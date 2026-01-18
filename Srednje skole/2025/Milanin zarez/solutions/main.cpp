#include <iostream>
#include <vector>

using namespace std;

char last_char(string s) {
	return s[s.size()-1];
}

int main() {
	int n;
	cin >> n;

	vector<string> vs(n);
	for (int i = 0; i < n; i++) 
		cin >> vs[i];

	string uputstvo;
	cin >> uputstvo;

	if(uputstvo == "DODATI") {
		for(int i = 1; i < n - 2; i++)
			if(vs[i-1].back() == ',' && vs[i].back() != ',' && (vs[i+1] == "i" || vs[i+1] == "ili"))
				vs[i] += ",";
	}
	else {
		for(int i = 1; i < n - 2; i++)
			if(vs[i-1].back() == ',' && vs[i].back() == ',' && (vs[i+1] == "i" || vs[i+1] == "ili"))
				vs[i].pop_back();
	}
	
	for (int i = 0; i < n; i++)
		cout << vs[i] << " ";
	cout << endl;

	return 0;
}
