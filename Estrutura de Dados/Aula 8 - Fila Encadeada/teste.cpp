struct carta{
    int numero; 
    int naipe; // 0 - Paus, 1 - Espadas, 2 - Ouros, 3 - Copas
};

int main(){
    carta baralho[52];
    int numCarta = 0;

    for (int i = 0; i <= 3; i++){ // Naipe
        for (int j = 0; j <= 12; j++){ // Num carta
            baralho[numCarta].naipe = i; // Adiciona o naipe a carta
            baralho[numCarta].numero = j; // Adiciona o numero a carta

            numCarta++;
        }

    }
}