#include <iostream>
#include <chrono>
using namespace std;

// Iterative Factorial
unsigned long long iterativeFactorial(int n)
{
    unsigned long long fact = 1;

    for (int i = 1; i <= n; i++)
    {
        fact = fact * i;
    }

    return fact;
}

// Recursive Factorial
unsigned long long recursiveFactorial(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }

    return n * recursiveFactorial(n - 1);
}

int main()
{
    int n;

    cout << "Enter a non-negative integer: ";
    cin >> n;

    if (n < 0)
    {
        cout << "Invalid input!" << endl;
        return 1;
    }

    // Iterative method timing
    auto start1 = chrono::high_resolution_clock::now();

    unsigned long long result1 = iterativeFactorial(n);

    auto end1 = chrono::high_resolution_clock::now();

    auto time1 = chrono::duration_cast<chrono::nanoseconds>
                 (end1 - start1).count();

    // Recursive method timing
    auto start2 = chrono::high_resolution_clock::now();

    unsigned long long result2 = recursiveFactorial(n);

    auto end2 = chrono::high_resolution_clock::now();

    auto time2 = chrono::duration_cast<chrono::nanoseconds>
                 (end2 - start2).count();

    // Display results
    cout << "\n--- Results ---" << endl;

    cout << "Factorial using Iterative Method: " << result1 << endl;
    cout << "Time taken (Iterative): " << time1 << " nanoseconds" << endl;

    cout << "Factorial using Recursive Method: " << result2 << endl;
    cout << "Time taken (Recursive): " << time2 << " nanoseconds" << endl;

    return 0;
}