#pragma once

#include <string>

using namespace std;


    class Menu {

//      =======
        public:
//      =======

//      ============
//      Constructors
//      ============

//         ============

            Menu(void);

//         ============

//      ================
//      End Constructors
//      ================

//      ===========
//      Destructors
//      ===========

//          ============

            ~Menu(void);

//          ============

//      ===============
//      End Destructors
//      ===============

//      ============================
//      Public M-Function Prototypes
//      ============================

//          ==============================
            MenuChoices Get(); // Accessor
            void Set(MenuChoices); // Mutator
            void Display();
            void QueryUser();
            bool Continue();
            void ProcessCommand(DoublyLinkedList&);
//          =======================================
// 
//      ================================
//      End Public M-Function Prototypes
//      ================================


//      ==========
//      End public
//      ==========


//      ========
        private:
//      ========

//      ================
//      Member Variables
//      ================

//          ==============================
            MenuChoices userMenuSelection;
//          ==============================

    }; // Class Menu
//  ================