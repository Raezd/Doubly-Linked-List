#pragma once


    //  ============
    class Node {

//      ==============================
        friend class DoublyLinkedList;
//      ==============================

//      =======
        public: 
//      =======

//          ======================
//          Constructor Prototypes
//          ======================

            Node(void);

            Node(int, Node*, Node*);

//          ===================
//          End of Constructors
//          ====================


//          =====================
//          Destructor Prototypes
//          =====================

            ~Node(void);

//          ==================
//          End of Destructors
//          ==================

//          ==========
//          End public
//          ==========

//      ========
        private:
//      ========

//          ==========================
//          Member-Function Prototypes
//          ==========================

            void ConstructorBanner();
            void DestructorBanner();

//          ====================
//          End Member-Functions
//          ====================

//          Member Variables
//          ================

            int info;
            Node* next;
            Node* prev;

//         ====================
//         End Member Variables
//         ====================

//        ===========
//        end private
//        ===========


    }; // Class Node
//  ================

