// Recebe a entrada de graus e termos, converte os graus para radianos, realiza a operacao de seno
// e cosseno utilizando a funcao de cmath e series de Taylor, e ao fim calcula o erro entre ambas

// Fernando Perez Borin - 2125219
// Gustavo Soatto Santos - 2141790
// Julio Fábio Dos Santos Melo - 2165170

#include <iostream>
#include <cmath>
using namespace std;

int main(){

    float graus, radianos, pi = 3.14159265359,
          cmath_cos = 1.0, cos_taylor = 0.0, cos_termo = 1.0, erro_cos = 1.0, porcentagem_cos = 1.0,
          cmath_sin = 1.0, sin_taylor = 0.0, sin_termo = 1.0, erro_sin = 1.0, porcentagem_sin = 1.0;

    int i, termos, sinal = 1;

    cout << "-----------------------------------------" << endl << endl
         << "Digite o valor do angulo em graus: ";
    cin >> graus;

    cout << "Digite o numero de termos da serie: ";
    cin >> termos; 
    cout << endl;
 
    radianos = graus * (pi / 180);

    for (i = 1; i <= termos; i++){

       cos_termo = pow(radianos, 2 * i) / tgamma(2 * i + 1); // Series de Taylor para o cosseno
       cos_taylor += pow(sinal, i) * cos_termo;

       sin_termo = pow(radianos, 2 * i + 1) / tgamma(2 * i + 1); // Series de Taylor para o seno
       sin_taylor += pow(sinal, i) * sin_termo;

    }

    cmath_cos = cos(radianos);
    cmath_sin = sin(radianos);

    erro_cos = abs(cmath_cos - cos_taylor);
    erro_sin = abs(cmath_sin - sin_taylor);

    porcentagem_cos = abs((erro_cos * 100) / cmath_cos);
    porcentagem_sin = abs((erro_sin * 100) / cmath_sin);

    cout << "-----------------------------------------" << endl << endl

         << "O valor de " << graus << " graus em radianos e: " << radianos << endl << endl

         << "O valor do Cosseno, usando a funcao da biblioteca cmath e: " << cmath_cos << endl
         << "O valor do Cosseno, usando as series de Taylor e: " << cos_taylor << endl << endl

         << "O valor do Seno, usando a funcao da biblioteca cmath e: " << cmath_sin << endl
         << "O valor do Seno, usando as series de Taylor e: " << sin_taylor << endl << endl

         << "O erro entre o calculo do cosseno da biblioteca " << endl
         << "cmath e as series de Taylor e de: " << erro_cos << endl
         << "que equivale a uma margem de erro de " << porcentagem_cos << "%" << endl << endl

         << "O erro entre o calculo do seno da biblioteca " << endl
         << "cmath e as series de Taylor e de: " << erro_sin << endl
         << "que equivale a uma margem de erro de " << porcentagem_sin << "%" << endl << endl

         << "-----------------------------------------" << endl << endl;

    return 0;
}