#include <iostream>
#include <utility>
 
using namespace std;
 
int main() {
    int n;
    char iz[1000], u[1000];
    string rijec;
    char mjesto[1000];
 
    for(int i = 'a'; i <= 'z'; i++)
        mjesto[i] = i;
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> iz[i] >> u[i];
        swap(mjesto[iz[i]], mjesto[u[i]]);
    }
    cin >> rijec;

    for(int i = 0; i < rijec.size(); i++)
        cout << mjesto[rijec[i]];
 
    return 0;
}