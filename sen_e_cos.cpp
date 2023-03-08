// Le o valor de graus e o numero de termos, converte os graus para radianos e realiza a operacao
// de seno e cosseno, utilizando a funcao da biblioteca cmath e as series de Mclaurin

#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

float graus, radianos, pi,
      cmath_cos = 1.0, cos_mclaurin = 1.0, cos_termo = 1.0, erro_cos, abs_cos, porcentagem_cos,
      cmath_sin = 1.0, sin_mclaurin = 1.0, sin_termo = 1.0, erro_sin, abs_sin, porcentagem_sin;

int i, termos;

int main(){

    pi = 3.14159265359;

    cout << "Digite o valor do angulo em graus: ";
    cin >> graus;

    cout << "Digite o numero de termos da serie: ";
    cin >> termos; 
    cout << endl;
 
    radianos = graus * (pi / 180);

    for (i = 1; i <= termos; i++){

       cos_termo *= (-radianos * radianos) / ((2 * i - 1) * (2 * i)); // Series de Mclaurin para encontrar o cosseno 
       cos_mclaurin += cos_termo; 

       sin_termo = -sin_termo * radianos * radianos / (2 * i) / (2 * i + 1); // Series de Mclaurin para encontrar o seno
       sin_mclaurin += sin_termo;
       
    }

    cmath_cos = cos(radianos);
    cmath_sin = sin(radianos);

    erro_cos = cmath_cos - cos_mclaurin;
    erro_sin = cmath_sin - sin_mclaurin;

    abs_cos = abs(erro_cos);
    abs_sin = abs(erro_sin);

    porcentagem_cos = (abs_cos * 100) / cmath_cos;
    porcentagem_sin = (abs_sin * 100) / cmath_sin;

    cout << "O valor de " << graus << " graus em radianos e " << radianos << endl;
    cout << endl;

    cout << "O valor do Cosseno, usando a funcao da biblioteca cmath e: " << cmath_cos << endl;
    cout << "O valor do Seno, usando a funcao da biblioteca cmath e: " << cmath_sin << endl;
    cout << endl;

    cout << "O valor do Cosseno, usando as series de Mclaurin e: " << cos_mclaurin << endl;
    cout << "O valor do Seno, usando as series de Mclaurin e: " << sin_mclaurin << endl;
    cout << endl;

    cout << "O erro entre o calculo do cosseno da biblioteca " << endl <<
            "cmath e as divisoes de Mclaurin e de: " << abs_cos << endl <<
            "que equivale a uma margem de erro de " << porcentagem_cos << "%" << endl <<
            endl;

    cout << "O erro entre o calculo do seno da biblioteca " << endl <<
            "cmath e as divisoes de Mclaurin e de: " << abs_sin << endl <<
            "que equivale a uma margem de erro de " << porcentagem_sin << "%" << endl <<
            endl;

    return 0;
}