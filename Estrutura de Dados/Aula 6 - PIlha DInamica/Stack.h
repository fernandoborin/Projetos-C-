class Stack{
    public:
    Stack();
    ~Stack();
    void Push(int x);
    void Pop(int &x);
    bool Empty();
    bool Full();
    int Size();
    void Top(int &x);

    private:
    struct StackNode{
        int Entry;
        StackNode *NextNode;
    };

    typedef struct StackNode* StackPointer;
    StackPointer top;
};
