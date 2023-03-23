// Recebe a entrada de graus e o numero de termos, converte os graus para radianos e realiza a
// operacao de seno e cosseno, utilizando a funcao da biblioteca cmath e series de potencia

// Fernando Perez Borin - 2125219

#include <iostream>
#include <cmath>
using namespace std;

int main(){
        
    float graus, radianos, pi = 3.14159265359,
          cmath_cos = 1.0, cos_series = 0.0, cos_termo = 1.0, erro_cos = 1.0, porcentagem_cos = 1.0,
          cmath_sin = 1.0, sin_series = 0.0, sin_termo = 1.0, erro_sin = 1.0, porcentagem_sin = 1.0;

    int i, termos, sinal = 1;

    cout << "Digite o valor do angulo em graus: ";
    cin >> graus;

    cout << "Digite o numero de termos da serie: ";
    cin >> termos; 
    cout << endl;
 
    radianos = graus * (pi / 180);

    for (i = 1; i <= termos; i++){

       //cos_termo *= (-1.0) * radianos * radianos / (2.0 * i * (2.0 * i - 1.0)); // Series para encontrar o cosseno
       //cos_series += cos_termo;                                                 // Usando Mclaurin

       cos_termo = pow(radianos, 2 * i) / tgamma(2 * i + 1); // Series de Taylor para encontrar o cosseno
       cos_series += sinal * cos_termo;
       sinal *= -1; // Inversor de sinal

       sin_termo = -sin_termo * radianos * radianos / (2 * i) / (2 * i + 1); // Series para encontrar o seno
       sin_series += sin_termo;
    }

    cmath_cos = cos(radianos);
    cmath_sin = sin(radianos);

    erro_cos = abs(cmath_cos - cos_series);
    erro_sin = abs(cmath_sin - sin_series);

    porcentagem_cos = abs((erro_cos * 100) / cmath_cos);
    porcentagem_sin = abs((erro_sin * 100) / cmath_sin);

    cout << "O valor de " << graus << " graus em radianos e " << radianos << endl << endl

         << "O valor do Cosseno, usando a funcao da biblioteca cmath e: " << cmath_cos << endl
         << "O valor do Cosseno, usando as series de potencias e: " << cos_series << endl << endl

         << "O valor do Seno, usando a funcao da biblioteca cmath e: " << cmath_sin << endl
         << "O valor do Seno, usando as series de potencias e: " << sin_series << endl << endl

         << "O erro entre o calculo do cosseno da biblioteca " << endl
         << "cmath e as series de potencia e de: " << erro_cos << endl
         << "que equivale a uma margem de erro de " << porcentagem_cos << "%" << endl << endl

         << "O erro entre o calculo do seno da biblioteca " << endl
         << "cmath e as series de potencia e de: " << erro_sin << endl
         << "que equivale a uma margem de erro de " << porcentagem_sin << "%" << endl << endl;

    return 0;
}