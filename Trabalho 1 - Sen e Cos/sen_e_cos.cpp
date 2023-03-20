// Le o valor de graus e o numero de termos, converte os graus para radianos e realiza a operacao
// de seno e cosseno, utilizando a funcao da biblioteca cmath e as series de Mclaurin

// Fernando Perez Borin - 2125219

#include <iostream>
#include <cmath>
using namespace std;

int main(){

    float graus, radianos, pi = 3.14159265359,
          cmath_cos = 1.0, cos_mclaurin = 1.0, cos_termo = 1.0, erro_cos, porcentagem_cos,
          cmath_sin = 1.0, sin_mclaurin = 1.0, sin_termo = 1.0, erro_sin, porcentagem_sin;

    int i, termos;

    cout << "Digite o valor do angulo em graus: ";
    cin >> graus;

    cout << "Digite o numero de termos da serie: ";
    cin >> termos; 
    cout << endl;
 
    radianos = graus * (pi / 180);

    for (i = 1; i <= termos; i++){

       cos_termo *= (-radianos * radianos) / ((2 * i - 1) * (2 * i)); // Series para encontrar o cosseno 
       cos_mclaurin += cos_termo; 

       sin_termo = -sin_termo * radianos * radianos / (2 * i) / (2 * i + 1); // Series para encontrar o seno
       sin_mclaurin += sin_termo;
    }

    cmath_cos = cos(radianos);
    cmath_sin = sin(radianos);

    erro_cos = abs(cmath_cos - cos_mclaurin);
    erro_sin = abs(cmath_sin - sin_mclaurin);

    porcentagem_cos = abs((erro_cos * 100) / cmath_cos);
    porcentagem_sin = abs((erro_sin * 100) / cmath_sin);

    cout << "O valor de " << graus << " graus em radianos e " << radianos << endl << endl

         << "O valor do Cosseno, usando a funcao da biblioteca cmath e: " << cmath_cos << endl
         << "O valor do Cosseno, usando as series de Mclaurin e: " << cos_mclaurin << endl << endl

         << "O valor do Seno, usando a funcao da biblioteca cmath e: " << cmath_sin << endl
         << "O valor do Seno, usando as series de Mclaurin e: " << sin_mclaurin << endl << endl

         << "O erro entre o calculo do cosseno da biblioteca " << endl
         << "cmath e as divisoes de Mclaurin e de: " << erro_cos << endl
         << "que equivale a uma margem de erro de " << porcentagem_cos << "%" << endl << endl

         << "O erro entre o calculo do seno da biblioteca " << endl
         << "cmath e as divisoes de Mclaurin e de: " << erro_sin << endl
         << "que equivale a uma margem de erro de " << porcentagem_sin << "%" << endl << endl;

    return 0;
}