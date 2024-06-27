#include <bits/stdc++.h>
using namespace std;

class Task {
 public:
    /* Function that runs the code */
    void solve() {
        read_input();
        print_output(get_result());
    }

 private:
    int k;
    vector<int> x;
    vector<char> t;
    const int MOD = 1000000007;

    /* Reading function */
    void read_input() {
        ifstream fin("colorare.in");
        fin >> k;

        for (int i = 0, nr; i < k; i++) {
            char type;
            fin >> nr >> type;
            x.push_back(nr);
            t.push_back(type);
        }

        fin.close();
    }

    // Efficient power function that returns (b^e % MOD)
    int power(int b, int e) {
        int res = 1;

        while (e > 0) {
            // If the exponent is odd, multiply with b => e turns even
            if (e % 2 == 1) {
                res = (1LL * res * b) % MOD;
            }

            /* The exponent is even, raise the base to the power of 2
            and divide the exponent by 2 */
            b = (1LL * b * b) % MOD;
            e /= 2;
        }
        return res;
    }

    /* Function that calculates the result */
    int get_result() {
        int res = 0;
        int nr = x[0];
        char c = t[0];

        if (c == 'H') {  // The first rectangle is Horizontal
            res = 6;  // Initial number of possible paintings for 1 H rectangle
            if (nr > 1) {  // More than 1 H
                // Multiply by 3 for each H after the first one
                res = (1LL * res * power(3, (nr - 1))) % MOD;
            }
        } else {  // The first rectangle is Vertical
            res = 3;  // Initial number of possible paintings for 1 V rectangle
            if (nr > 1) {  // More than 1 V
                // Multiply by 2 for each V after the first one
                res = (1LL * res * power(2, (nr - 1))) % MOD;
            }
        }

        // For the rest of the rectangles
        for (int i = 1; i < k; i++) {
            if (c == 'H') {
                if (t[i] == 'H') {  // H H ..
                    // Multiply by 3 for each H
                    res = (1LL * res * power(3, x[i])) % MOD;
                } else {  // H V ..
                    // If there is only 1 V it changes nothing
                    if (x[i] > 1) {
                        // Multiply by 2 for each V after the first one
                        res = (1LL * res * power(2, x[i] - 1)) % MOD;
                    }
                }
            } else {
                if (t[i] == 'H') {  // V H ..
                    // Multiply by 2 for the first H
                    res = res * 2;
                    if (x[i] > 1) {
                        // Multiply by 3 for each H after the first one
                        res = (1LL * res * power(3, (x[i] - 1))) % MOD;
                    }
                } else {  // V V ..
                    // Multiply by 2 for each V
                    res = (1LL * res * power(2, x[i])) % MOD;
                }
            }
            c = t[i];
        }
        return res;
    }

    /* Printing function */
    void print_output(long long result) {
        ofstream fout("colorare.out");
        fout << result;
        fout.close();
    }
};

int main() {
    auto* task = new (nothrow) Task();
    if (!task) {
        cerr << "new failed: WTF are you doing? Throw your PC!\n";
        return -1;
    }
    task->solve();
    delete task;
    return 0;
}
