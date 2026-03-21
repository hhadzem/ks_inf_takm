// Rjesenje zadatka dobijeno od Admira Tuzovica. 

#include <bits/stdc++.h>

using namespace std;

// Converting character to integer.
static int ctoi(char c) {
    return c - '0';
}

static void solve() {
    string S;
    cin >> S;

    int N = S.length();

    // Modifier that consideres parity of first digit.
    // 0 if first digit is even, otherwise 1.
    // Used later to avoid code duplication.
    int comp = ctoi(S[0]) % 2;

    // Index of first digit that is mismatched by parity.
    int in = 0;

    // Search for index of parity mismatch.
    while(in < N) {

        // If there is mismatch in parity.
        if(((in+comp) % 2) != (ctoi(S[in]) % 2)) {

            // Abort search.
            break;
        }
        in++;
    }

    // If all digits match required parity.
    if(in == N) {

        // Output original input as result.
        cout << S << '\n';
        return;
    }

    // Two possible solutions.
    string S1 = "";
    string S2 = "";

    // Copy existing characters from input string 0...(in-1).
    for(int i = 0; i < in; i++) {
        S1 += S[i];
        S2 += S[i];
    }

    // If mismatching digit is '0'.
    if(S[in] == '0') {

        // It can only be changed to 1.
        S1 += '1';

        // Remaining digits should be 01010101...
        for(int i = in+1; i < N; i++) {
            S1 += '0' + i % 2;
        }

        // Output S1 as only possible solution.
        cout << S1 << '\n';
        return;
    }

    // If mismatching digit is 9.
    if(S[in] == '9'){

        // It can only be changed to 8.
        S2 += '8';

        // Remanining digits should be 989898989...
        for(int i = in+1; i < N; i++) {
            S2 += '8' + i % 2;
        }

        // Output S2 as only possible solution.
        cout << S2 << '\n';
        return;
    }

    // In other situations, we have two options.
    // First option includes increasing mismatching digit by 1.
    S1 += S[in] + 1;

    // Second option includes decreasing mismatching digit by 1.
    S2 += S[in] - 1;

    // Let's assume both options are equally distant from the input.
    bool same = true;

    // Used to indicate which one will be printed if they are not equally distant from input.
    bool printS1 = false;
    bool printS2 = false;

    // Iterate through remaining digits (in+1)...N-1.
    for(int i = in+1; i < N; i++) {

        // Alternate 0/1 in larger option.
        S1 += '0' + (i + comp) % 2;

        // Alternate 8/9 in smaller option.
        S2 += '8' + (i + comp) % 2;

        // Calculate distance from original digit.
        int diff1 = ctoi(S1[i]) - ctoi(S[i]);
        int diff2 = ctoi(S[i]) - ctoi(S2[i]);

        // If strings were equally distant so far but they are no longer.
        if(same && diff1 != diff2) {

            // Indicate that they are no longer equally distant.
            same = false;

            // Formulate 2-digit strings from mismatch char and current char.
            string t = { S[in], S[i] };
            string t1 = { S1[in], S1[i] };
            string t2 = { S2[in], S2[i] };

            // Convert strings to numbers.
            int num = stoi(t);
            int num1 = stoi(t1);
            int num2 = stoi(t2);

            // Calculate differences.
            diff1 = num1 - num;
            diff2 = num - num2;

            // If first string is closer to input.
            if(diff1 < diff2) {
                // Print S1 only.
                printS1 = true;
            } else {
                // Otherwise print S2.
                printS2 = true;
            }
        }
    }

    // IF: S1 and S2 are equally distant.
    if(same) {
        // Print  both.
        cout << S2 << ' ' << S1 << '\n';
    } else {
        if(printS1) {
            // Print S1 only.
            cout << S1 << '\n';
        } else { 
            // Print S2 only.
            cout << S2 << '\n';
        }
    }

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}