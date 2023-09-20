#include <iostream>
using namespace std;

void swap(void*& left, void*& right){
    void* temp = left;
    left = right;
    right = temp;    
}

int main(){
    void* left = new int[0];
    void* right = new int[0];

    cout << "Endereco de left: " << left << endl
         << "Endereco de right: " << right << endl << endl;

    swap(left, right);

    cout << "Swap!" << endl
         << "Endereco de left: " << left << endl
         << "Endereco de right: " << right << endl;

}