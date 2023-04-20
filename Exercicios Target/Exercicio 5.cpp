#include <iostream>
using namespace std;

void inverterString(string string1, string string2){
    for (int i = string1.length(); i >= 0; i--){
        string2 = string2 + string1[i]; // Soma a string2 vazia com a string1 em um contador decrescente
    }

    cout << "String invertida: " << string2;
}

int main(){
    string string1, string2;

    cout << "Digite a string: ";
    getline(cin, string1);

    inverterString(string1, string2);

}