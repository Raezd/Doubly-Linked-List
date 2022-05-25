#include "pch.h"
#include <iostream>

using namespace std;

DoublyLinkedList::DoublyLinkedList() {


//  ============
//  Constructors
//  ============

//      ============================
//      Constructor DoublyLinkedList
//      ============================

        ConstructorBanner();

        first = last = nullptr;


        } // Constructor DoublyLinkedList
//      ==================================



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

            DestructorBanner();
            DestroyList();


        } // Destructor DoublyLinkedList
//      ================================

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

            Node* temp;

            while (first != nullptr) {

                temp = first;
                first = first->next;
                delete temp;

            } // while

            last = nullptr;

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

            Node* newNode = new Node(value, first, prev);

            first = newNode;
            newNode->prev = nullptr;

            if (prev != nullptr)
                first->prev = newNode;

        } // Public M-Function InsertFirst
//      ==================================

//      ============================
//      Public M-Function InsertLast
//      ============================

        void DoublyLinkedList::InsertLast(int value) {

            if (this->Empty()) {

                this->InsertFirst(value);

            } // if

            else {

                Node* newNode = new Node(value, nullptr, prev);
                
                last = first; // setting last to first so we can traverse to last node with a while loop

                newNode->next = nullptr; // this new node is last, so newNode->next is set to nullptr

             
                while (last->next != nullptr) {

                    last = last->next; // traversing the list

                } // while

                last->next = newNode;

                newNode->prev = last;
                

            } // else


        } // Public M-Function InsertLast
//      =================================


//      ========================
//      Public M-Function Insert
//      ========================

        void DoublyLinkedList::Insert(int value, int location) {

            Node* temp;
           

            if ( (location > this->Length() + 1) || (location < 1) ) {

                cout << endl;
                cout << "========================" << endl;
                cout << "Insert Function invoked." << endl;
                cout << "Insertion location is invalid." << endl;
                cout << "Terminating execution..." << endl;
                cout << "========================" << endl;
                cout << endl;

            } // then

            else {

                if (location == 1) {
                    this->InsertFirst(value);
                    return;
                }

                else if (location == this->Length() + 1) {

                    this->InsertLast(value);
                    return;
                }

                Node* newNode = new Node(value, nullptr, nullptr);

                temp = first;

                for (int ii = 1; ii < location - 1; ii++) {

                    temp = temp->next;

                } // for

                newNode->next = temp->next;
                newNode->prev = temp;
                temp->next = newNode;
                newNode->next->prev = newNode;

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

            int nbNodes = 0;
            Node* ptr;

            ptr = this->first;

            while (ptr != nullptr) {

                ptr = ptr->next;
                nbNodes++;

            } // while

            return nbNodes;

        } // Public M-Function Length
//      =============================


//      =======================
//      Publuc M-Function Print
//      =======================

        void DoublyLinkedList::Print() {

            Node* current;

            cout << endl;
            cout << "===========================" << endl;
            cout << "The list contains the following data:" << endl;
            cout << endl;

            if (this->Length() == 0) {

                cout << "The list is empty." << endl;
                cout << "==================" << endl;


            } // then

            else {

                cout << "==============" << endl;
                cout << "  Beginning..." << endl;
                cout << "==============" << endl;
                
                current = first;

                while (current != nullptr) {

                    cout << "    " << current->info << endl;
                    
                    current = current->next;

                } // while

                cout << "========" << endl;
                cout << "  End..." << endl;
                cout << "========" << endl;
                cout << endl;

            } // else

        } // Public M-Function Print
//      ============================



//      ==============================
//      Public M-Function ReversePrint
//      ==============================

        void DoublyLinkedList::ReversePrint(Node* currentNode) {

            
            if (currentNode != nullptr) {

                ReversePrint(currentNode->next);

                cout << currentNode->info << endl;

            } // then

        } // Public M-Function ReversePrint
//      ===================================

//      =============================
//      Public M-Function DeleteFirst
//      =============================
// 
        void DoublyLinkedList::DeleteFirst() {



            if (this->Empty()) {

                return;

            } // then

            Node* temp = first;

            first = first->next;

            delete temp;

            return;
                


        } // Public M-Function DeleteFirst
//      ==================================
//      
//      ========================
//      Public M-Function Delete
//      ========================

        void DoublyLinkedList::Delete(int location) {

            if ((location > this->Length() + 1) || (location < 1)) {

                cout << endl;
                cout << "========================" << endl;
                cout << "Delete Function invoked." << endl;
                cout << "Deletion location is invalid." << endl;
                cout << "Terminating execution..." << endl;
                cout << "========================" << endl;
                cout << endl;

            } // then

            else {

                if (location == 1)
                    this->DeleteFirst();

                else if (location == this->Length() + 1)
                    this->DeleteLast();

                else {

                    Node* temp = first;

                    if (location == 1) {

                        first = temp->next;

                        //free(temp); // can also deallocate
                        delete temp;

                        return;

                    } // then

                    for (int ii = 1; temp != nullptr && ii < location - 1; ii++) {

                        temp = temp->next;

                    } // for

                    if (temp == nullptr || temp->next == nullptr) {

                        return;

                    } // then

                    Node* next = temp->next->next;

                    //free(temp->next); can also deallocate
                    delete temp->next;

                    temp->next = next;

                } // nested else

            } // outer else

        } // Public M-Function Delete
//      =============================


//      =============================
//      Public M-Function DeleteLast
//      ============================

        void DoublyLinkedList::DeleteLast() {


            Node* prev = nullptr;
            Node* temp = first;

            while (temp->next != nullptr) {

                prev = temp;
                temp = temp->next;

            } // while

            delete temp;

            prev->next = nullptr;

            return;


        } // Public M-Function DeleteLast
//      =================================

// 
// 
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