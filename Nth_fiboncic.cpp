#include <bits/stdc++.h>
using namespace std;

using Matrix = array<array<long long, 2>, 2>;

Matrix multiply(Matrix a, Matrix b) {
    Matrix result = {{{0, 0}, {0, 0}}};

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                result[i][j] += a[i][k] * b[k][j];

    return result;
}

Matrix power(Matrix base, long long n) {
    Matrix result = {{{1, 0}, {0, 1}}};

    while (n > 0) {
        if (n % 2)
            result = multiply(result, base);

        base = multiply(base, base);
        n /= 2;
    }

    return result;
}

int main() {
    long long n;
    cin >> n;

    if (n == 0) {
        cout << 0;
        return 0;
    }

    Matrix base = {{{1, 1}, {1, 0}}};
    Matrix result = power(base, n - 1);

    cout << "Fibonacci = " << result[0][0];

    return 0;
}
