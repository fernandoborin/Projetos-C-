class List{
    public:
    List();
    ~List();
    bool Empty();
    bool Full();
    void Insert(int p, int x);
    void Delete(int p, int &x);
    int Size();
    int Retrieve(int p, int &x);
    void Clear();
    void Replace(int p, int &x);

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