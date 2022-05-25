#pragma once



//  ========================
    class DoublyLinkedList {

//      =======
        public:
//      =======

//          ============
//          Constructors
//          ============

            DoublyLinkedList(void);

//          ================
//          End Constructors        
//          ================

//          ===========
//          Destructors
//          ===========

            ~DoublyLinkedList(void);

//          ===============
//          End Destructors        
 //         ===============
            
//          ============================
//          Public M-Function Prototypes
//          ============================

            void DestroyList();
            Node* GetFirst();
            void InitializeList();
            void InsertFirst(int);
            void InsertLast(int);
            void Insert(int, int);
            bool Empty();
            int Length();
            void Print();
            void ReversePrint(Node*);
            void DeleteFirst();
            void Delete(int);
            void DeleteLast();

//          ================================
//          End Public M-Function Prototypes
//          ================================


//      ==========
//      end public
//      ==========

//      ========
        private:
//      ========

//          ================
//          Member variables
//          ================

            Node* first;
            Node* prev;
            Node* last;

//          ===========

//          ===================
//          Private M-Functions
//          ===================

            void ConstructorBanner();
            void DestructorBanner();

//         =========================


    }; // Class SinglyLinkedList
//  ============================

