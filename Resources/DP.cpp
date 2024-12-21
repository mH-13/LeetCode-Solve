/*Dynamic Programming is essential for problems involving overlapping subproblems or optimal substructures.

Code: Fibonacci Sequence (Bottom-Up Approach)*/

#include <vector>
#include <iostream>
using namespace std;

// Function to calculate nth Fibonacci number
int fibonacci(int n) {
    if (n <= 1) return n;

    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main() {
    int n = 10;
    cout << "Fibonacci number at position " << n << ": " << fibonacci(n) << endl;

    return 0;
}

//Problems like Climbing Stairs.
//Any problem reducible to a recurrence relation.