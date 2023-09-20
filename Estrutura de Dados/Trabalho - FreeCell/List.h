#ifndef LIST_H
#define LIST_H

class List{
    public:
        List();
        ~List();
        bool Empty();
        bool Full();
        void Insert(int p, int x, char z);
        void Delete(int x, int &p, char &c);
        int Size();
        void Retrieve(int p, int &x, char &c);
        void Clear();
        void replace(int p, int x);
        void Fill();
        void Shuffle();
        void Read(int x);

    private:
        struct ListNode{
            int Entry;
            char Naipe;
            ListNode* NextNode;
        };
        typedef ListNode* ListPointer;
        void SetPosition(int p, ListPointer &current);
        ListPointer head;
        int count;
};  

#endif