#include <iostream>
#include <cmath>

using namespace std;

double cos_mclaurin(double x, int n) {
    double cos_val = 1.0;
    double term = 1.0;
    for (int i = 1; i <= n; i++) {
        term *= (-x * x) / ((2 * i - 1) * (2 * i));
        cos_val += term;
    }
    return cos_val;
}

int main() {
    double x = 1.0;
    int n = 10;

    cout << "Valor do angulo em radianos: ";
    cin >> x;
 
    cout << "Numero de termos: ";
    cin >> n;

    cout << "cos(" << x << ") = " << cos(x) << endl;
    cout << "cos_mclaurin(" << x << ", " << n << ") = " << cos_mclaurin(x, n) << endl;
    return 0;
}