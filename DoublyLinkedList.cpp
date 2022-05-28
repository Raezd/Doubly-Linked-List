#include "pch.h"
#include <iostream>

using namespace std;

//  ==================================
    DoublyLinkedList::DoublyLinkedList() {


    //  ============
    //  Constructors
    //  ============

    //      ============================
    //      Constructor DoublyLinkedList
    //      ============================

          //  ConstructorBanner();

            first = last = nullptr;
        
            } // Constructor DoublyLinkedList
    //      =================================



    //  ================
    //  End Constructors
    //  ================


    //  ===========
    //  Destructors
    //  ===========

    //      ===========================
    //      Destructor DoublyLinkedList
    //      ===========================

            DoublyLinkedList::~DoublyLinkedList() {

             // DestructorBanner();
                DestroyList();

            } // Destructor DoublyLinkedList
//          ================================

//  ===============
//  End Destructors
//  ===============


//  ==================
//  Public M-Functions
//  ==================
// 
//      =============================
//      Public M-Function DestroyList
//      =============================

        void DoublyLinkedList::DestroyList() {

            Node* ptr;

            while (first != nullptr) {

                ptr = first;
                first = first->next; // moving sequentially down the list, deleting 1x1
                delete ptr;

            } // while

            last = nullptr;

            cout << endl << endl;
            cout << "     =================================================" << endl;
            cout << "     The list is empty! Add some nodes using the menu." << endl;
            cout << "     =================================================" << endl;
            cout << endl;

        } // Public M-Function DestroyList
//      ==================================

//      =====================================
//      Public M-Function GetFirst (Accessor)
//      =====================================

        Node* DoublyLinkedList::GetFirst() {

            return first;

        } // Public M-Function GetFirst
//      ===============================

//      ================================
//      Public M-Function InitializeList
//      ================================

        void DoublyLinkedList::InitializeList() {

            DestroyList();

        } // Public M-Function InitializeList
//      =====================================

//      =============================
//      Public M-Function InsertFirst
//      =============================

        void DoublyLinkedList::InsertFirst(int value) {

//          =======================================
//          Variable declarations and node creation
//          ===================================================
            Node* newNodePtr = new Node(value, first, nullptr);
//          ===================================================

//          ==========
//          Node logic
//          ===========================
            newNodePtr->prev = nullptr;

            if (first != nullptr) {

                first->prev = newNodePtr;

            } // then

            first = newNodePtr;
//          ===================

        } // Public M-Function InsertFirst
//      ==================================

//      ============================
//      Public M-Function InsertLast
//      ============================

        void DoublyLinkedList::InsertLast(int value) {

//          =====================================
//          If-then clause to offload computation
//          =====================================
            if (this->Empty()) {

                this->InsertFirst(value);

            } // then
//          =========

            else {

//              =======================================                
//              Variable Declarations and node creation
//              =======================================
                Node* ptr = first;
                Node* newNodePtr = new Node(value, nullptr, nullptr);
//              =====================================================

                while (ptr->next != nullptr) {

                    ptr = ptr->next; // traversing

                } // while

//             ==========
//             Node logic
//             =======================
               newNodePtr->prev = ptr;
               ptr->next = newNodePtr;
               newNodePtr->next = nullptr;
//             ===========================
 
            } // else

        } // Public M-Function InsertLast
//      =================================


//      ========================
//      Public M-Function Insert
//      ========================

        void DoublyLinkedList::Insert(int value, int location) {

//          =====================================================       
//          If-then clauses to error handle & offload computation
//          ========================================================
            if ((location > this->Length() + 1) || (location < 1)) {

                cout << endl;
                cout << "==============================" << endl;
                cout << "Insertion location is invalid." << endl;
                cout << "Please enter a valid location." << endl;
                cout << "==============================" << endl;
                cout << endl;

                return;

            } // then

            else {

                if (location == 1) {

                    this->InsertFirst(value);

                    return;

                } // then

                else if (location == this->Length() + 1) {

                    this->InsertLast(value);

                    return;

                } // else then

//              ===================
//              End If-then clauses
//              ===================

//              =======================================
//              Variable Declarations and node creation
//              =======================================
                Node* ptr;
                Node* newNodePtr = new Node(value, nullptr, nullptr);
//              =====================================================

                ptr = first;

                for (int ii = 1; ii < location - 1; ii++) {

                    ptr = ptr->next; // traversing

                } // for


//              ==========
//              Node logic
//              =============================
                newNodePtr->next = ptr->next;
                newNodePtr->prev = ptr;
                ptr->next = newNodePtr;
                newNodePtr->next->prev = newNodePtr;
//              ====================================

            } // else

        } // Public M-Function Insert
//      =============================

//      =======================
//      Publuc M-Function Empty
//      =======================

        bool DoublyLinkedList::Empty() {

            return (first == nullptr);

        } // Public M-Function Empty
//      ============================

//      ========================
//      Public M-Function Length
//      ========================
       
        int DoublyLinkedList::Length() {

//          =====================
//          Variable declarations
//          =====================
            int listLength = 0;
            Node* ptr;
//          ==========

            ptr = this->first;

            while (ptr != nullptr) {

                ptr = ptr->next; // traversing
                listLength++; // incrementing length until end of list

            } // while

            return listLength;

        } // Public M-Function Length
//      =============================


//      =======================
//      Public M-Function Print
//      =======================

        void DoublyLinkedList::Print() {

//          ====================
//          Variable declaration
//          ====================
            Node* currentNode;
//          ==================

//          =================================
//          If-then clause for error handling
//          =================================
            if (this->Length() == 0) {

                cout << endl << endl;
                cout << "     ==================" << endl;
                cout << "     The list is empty!" << endl;
                cout << "     ==================" << endl;
                cout << endl;

                return;

            } // then
//          =========

//          ========================================================================================================
//                                                      Print Output Formatting
            else {

                cout << endl;
                cout << "                                  *** Top of List ***                            " << endl;
                cout << "     =========================================================================" << endl;
                cout << "       Prev Address      Current Address       Next Address          Data" << endl;
                cout << "     -------------------------------------------------------------------------" << endl;

                currentNode = first;

                while (currentNode != nullptr) {

                    
                    cout << "     " << currentNode->prev << " ** " << currentNode << " ** " << currentNode->next << " _______ "
                    << currentNode->info << endl;
                    
                    currentNode = currentNode->next;

                } // while

                cout << "     ========================================================================" << endl;
                cout << "     Nodes: " << this->Length() << "                    *** Bottom of List ***                        "
                     << endl;
                cout << endl;
                

//          =========================================================================================================

            } // else

        } // Public M-Function Print
//      ============================



//      ==============================
//      Public M-Function ReversePrint
//      ==============================

        void DoublyLinkedList::ReversePrint(Node* currentNode) {

            if (currentNode != nullptr) {

                ReversePrint(currentNode->next); // recursive

                cout << "     " << currentNode->prev << " ** " << currentNode << " ** " << currentNode->next
                     << " _______ " << currentNode->info << endl;

                currentNode = currentNode->next;

            } // then

        } // Public M-Function ReversePrint
//      ===================================

//      =============================
//      Public M-Function DeleteFirst
//      =============================
// 
        void DoublyLinkedList::DeleteFirst() {

//          =================================================
//          If-then clauses for offloading and error handling
//          =================================================
            if (this->Empty()) {

                cout << endl << endl;
                cout << "     ==================" << endl;
                cout << "     The list is empty!" << endl;
                cout << "     ==================" << endl;
                cout << endl;

                return;

            } // then

            else if (this->Length() == 1) {

                   DestroyList(); 

                   return;

            } // else then
//          ==============

//          ==========
//          Node logic
//          ===================
            Node* temp = first;

            first = first->next;
            first->prev = nullptr;

            delete temp;
//          =============

            cout << "Deleted the first node in the list." << endl;

        } // Public M-Function DeleteFirst
//      ==================================
//      
//      ========================
//      Public M-Function Delete
//      ========================

        void DoublyLinkedList::Delete(int location) {

//          =====================
//          Error handling clause
//          ========================================================
            if ((location > this->Length()) || (location < 1)) {

                cout << endl;
                cout << "========================" << endl;
                cout << "Delete Function invoked." << endl;
                cout << "Deletion location is invalid." << endl;
                cout << "Terminating execution..." << endl;
                cout << "========================" << endl;
                cout << endl;

                return;

            } // then
//          =========

//          =============================
//          Offloading to other functions
//          =============================
            else {

                if (location == 1) {

                    this->DeleteFirst();

                    return;

                } // then

                else if (location == this->Length()) {

                    this->DeleteLast();

                    return;
                } // else then
//              ==============

//                  =====================
//                  Variable declarations
//                  =====================
                    Node* ptr;
                    Node* temp;
//                  ===========

                    ptr = first;

                    for (int ii = 1; ii < location - 1; ii++) {

                        ptr = ptr->next; // traversing

                    } // for

//                  ==========
//                  Node logic
//                  =================
                    temp = ptr->next;
                    ptr->next = ptr->next->next;
                    ptr->next->prev = ptr;

                    delete temp;
//                  ============

                    cout << endl;
                    cout << "Deleted the node at location " << location << "." << endl;

            } // else

        } // Public M-Function Delete
//      =============================


//      ============================
//      Public M-Function DeleteLast
//      ============================

        void DoublyLinkedList::DeleteLast() {

//          ====================
//          Variable declaration
//          ===================
            Node* ptr = first;

            while (ptr->next != nullptr) {

                ptr = ptr->next;

            } // while

//          ==========
//          Node logic
//          ==========================
            ptr->prev->next = nullptr;

            delete ptr;
//          ===========

            cout << "Deleted the end node." << endl;
            cout << endl;

//          =====================

        } // Public M-Function DeleteLast
//      =================================


//  =====================
//  End Public M-Function
//  =====================


//  ========================
//  Private Member Functions
//  ========================


//      ====================================
//      Private M-Function ConstructorBanner
//      ====================================

        void DoublyLinkedList::ConstructorBanner() {

            cout << endl;
            cout << "=======================================" << endl;
            cout << "DoublyLinkedList constructor invoked..." << endl;
            cout << "=======================================" << endl;
            cout << endl;

        } // Private M-Function ConstructorBanner
//      =========================================


//      ===================================
//      Private M-Function DestructorBanner
//      ===================================

        void DoublyLinkedList::DestructorBanner() {

            cout << endl;
            cout << "=======================================" << endl;
            cout << "DoublyLinkedList destructor invoked..." << endl;
            cout << "=======================================" << endl;
            cout << endl;

        } // Private M-Function DestructorBanner
//      ========================================
