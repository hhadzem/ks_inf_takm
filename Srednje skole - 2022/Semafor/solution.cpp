#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

int t(string a){
	int res = 0;
	for(size_t i = 0; i < a.length(); i++)
		if(a[i] == '*')
			res += (2 << i);
	return res;
}

vector<int> values(10);
void init(){	
	values[0] = t("****.**.**.****");
	values[1] = t("..*.***.*..*..*");
	values[2] = t("***..*****..***");
	values[3] = t("***..****..****");
	values[4] = t("*.**.****..*..*");
	values[5] = t("****..***..****");
	values[6] = t("****..****.****");
	values[7] = t("***..*..*..*..*");
	values[8] = t("****.*****.****");
	values[9] = t("****.****..****");
}

int check(vector<string> &board, int row, int col){
	string s;
	for(int i = row; i < row + 5; i++)
		for(int j = col; j < col + 3; j++)
			s += board[i][j];
	
	int val = t(s);
	for(size_t i = 0; i < values.size(); i++)
		if(val == values[i])
			return i;
	return -1;
}

vector<int> solve(vector<string> &board){
	int N = board.size(), M = board[0].length();
	vector<int> solution(10, 0);
	for(int i = 0; i < N - 4; i++)
		for(int j = 0; j < M - 2; j++){
			int num = check(board, i, j);
			if(num == -1)
				continue;
			solution[num] ++;
		}
	return solution;
}

void printArray(vector<int> arr){
	for(size_t i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main(){
	init();
	
	vector<string> board;
	int N, M;
	cin >> N >> M;
	string line;
	getline(cin, line);
	while(getline(cin, line)){
		board.push_back(line);
	}
	printArray(solve(board));
	return 0;
}
