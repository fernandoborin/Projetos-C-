class List{
    public:
    List();
    ~List();
    void Insert(int p, int x);
    void maiorElemento();
    void printList();

    private:
    struct ListNode{
        int Entry;
        ListNode* NextNode;
    };

    typedef ListNode* ListPointer;

    void SetPosition(int p, ListPointer &current);
    ListPointer head;
    int count;

};