#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

int linhas, colunas, quadrado, somatotal = 0;
int maiori, maiorj;

//--------------------------------------------------//

int main()
{

    srand(time(0));

    cout << "Digite o numero de linhas e colunas da matriz: ";
    cin >> linhas;
    colunas = linhas;

    cout << "Digite o valor do quadrado magico: ";
    cin >> quadrado;

    int matriz[linhas][colunas];

    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {

            matriz[i][j] = rand()%quadrado + 1; // Gera um valor para a posição determinada
            somatotal = somatotal + matriz[i][j];

        }
    }
    
    for (int i = 0; i < linhas; i++) // Montagem visual da matriz
    {
        for (int j = 0; j < colunas; j++)
        {

            if (matriz[i][j] < 10)
            {
                cout << " " << setfill('0') << setw(2) << matriz[i][j] << " "; // Por estética, adiciona um 0 na frente
            }                                                                  // caso o valor tenha apenas um digito
            else
            {
                cout << " " << matriz[i][j] << " ";
            }

            if (j == colunas - 1)
            {
                cout << endl;
            }   

        }
    }

    return 0;
}
