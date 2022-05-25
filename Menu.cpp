#include "pch.h"
#include <string>
#include <iostream>

using namespace std;

//  ============
//  Constructors
//  ============

//      ==================
        Menu::Menu(void) {

            userMenuSelection = Quit;

        } // Constructor Menu
//      =====================

//  ================
//  End Constructors
//  ================

//  ===========
//  Destructors
//  ===========

//      ===================
        Menu::~Menu(void) {



        } // Destructor ~Menu
//      =====================

//  ===============
//  End Destructors
//  ===============

//  ==================
//  Public M-Functions
//  ==================

//      =================
//      Accessor Function
//      =================

        MenuChoices Menu::Get() {

            return userMenuSelection;

        } // Accessor Function Get
//      ==========================

//      ================
//      Mutator Function
//      ================

        void Menu::Set(MenuChoices newValue) {

        } // Mutator Function Set
//      =========================

//      =========================
//      Public M-Function Display
//      =========================

        void Menu::Display() {

            cout << "================================" << endl;
            cout << "1: Quit" << endl;
            cout << "2: Destroy List" << endl;
            cout << "3: Initialize List" << endl;
            cout << "4: Insert First" << endl;
            cout << "5: Insert Last" << endl;
            cout << "6: Insert" << endl;
            cout << "7: Print" << endl;
            cout << "8: Reverse Print" << endl;
            cout << "9: Delete First" << endl;
            cout << "10: Delete Last" << endl;
            cout << "11: Delete at Location" << endl;
            cout << endl;

        } // Public M-Function Display
//      ==============================

//      ===========================
//      Public M-Function QueryUser
//      ===========================

        void Menu::QueryUser() {

            int selection;

            cout << "Please enter a menu selection: ";
            
            cin >> selection;

            switch (selection) {

                case 1: userMenuSelection = Quit;
                    break;

                case 2: userMenuSelection = DestroyList;
                    break;

                case 3: userMenuSelection = InitializeList;
                    break;

                case 4: userMenuSelection = InsertFirst;
                    break;

                case 5: userMenuSelection = InsertLast;
                    break;

                case 6: userMenuSelection = Insert;
                    break;

                case 7: userMenuSelection = Print;
                    break;

                case 8: userMenuSelection = ReversePrint;
                    break;

                case 9: userMenuSelection = DeleteFirst;
                    break;

                case 10: userMenuSelection = DeleteLast;
                    break;

                case 11: userMenuSelection = Delete;
                    break;

                default: userMenuSelection = ReversePrint;
 
            } // switch (selection)
//          ==========================

            cout << endl;

        } // Public M-Function QueryUser
//      ================================

//      ==========================
//      Public M-Function Continue
//      ==========================

        bool Menu::Continue() {

            return userMenuSelection != Quit;

        } // Public M-Function Continue
//      ===============================

//      ================================
//      Public M-Function ProcessCommand
//      ================================

        void Menu::ProcessCommand(DoublyLinkedList& list) {

            int intValue;
            int location;

            if (userMenuSelection != Quit) {

//              ============================
                switch (userMenuSelection) {

                    case DestroyList: list.DestroyList();
                        break;

                    case InitializeList: list.InitializeList();
                        break;

                    case InsertFirst:

                        cout << "Enter a value to add to the beginning of the list: ";
                        cin >> intValue;
                        list.InsertFirst(intValue);
                        list.Print();
                        break;

                    case InsertLast: 

                        cout << "Enter a value to add to the end of the list: ";
                        cin >> intValue;
                        list.InsertLast(intValue);
                        list.Print();
                        break;

                    case Insert:

                        cout << "Enter a value to add to the list: ";
                        cin >> intValue;
                        cout << endl;
                        cout << "Enter a node location for insertion: ";
                        cin >> location;
                        list.Insert(intValue, location);
                        list.Print();
                        break;

                    case Print: list.Print();
                        break;

                    case ReversePrint: list.ReversePrint(list.GetFirst());
                        break;

                    case DeleteFirst: list.DeleteFirst();
                        list.Print();
                        break;

                    case DeleteLast: list.DeleteLast();
                        list.Print();
                        break;

                    case Delete: 
                        
                        cout << "Enter a node location for deletion: ";
                        cin >> location;
                        list.Delete(location);
                        list.Print();
                        break;

                    default:
                        
                        cout << "Invalid selection." << endl;

                        list.Print();

                } // switch (userMenuSelection)
//              ===============================

            } // then 

        } // Public M-Function ProcessCommand
//      =====================================
