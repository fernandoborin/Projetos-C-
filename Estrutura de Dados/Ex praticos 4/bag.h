class Bag{
    public:
    void criarBag(int t);
    void inserirNumero();
    int verificarNumero();
    void removerNumero();
    bool verificarBag();
    void imprimirBag();

    private:
    int bag[0];
    int slotUsado = 0;
};