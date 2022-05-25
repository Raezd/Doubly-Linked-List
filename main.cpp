
#include <iostream>
#include "pch.h"


using namespace std;


//  ============
    int main() {

        Menu menu;

        DoublyLinkedList listA;

        do {

            menu.Display();
            menu.QueryUser();
            menu.ProcessCommand(listA);


        } while (menu.Continue() );

        return 0;

    } // Function main
//  ==================
