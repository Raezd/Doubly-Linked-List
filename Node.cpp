#include "pch.h"
#include <iostream>

using namespace std;

//  ========================
//  Default Node Constructor
//  ========================

    Node::Node(void) {

	    ConstructorBanner();

	    info = 0;
	    next = nullptr;
		prev = nullptr;


    } // Default Constructor
//  ========================


//  ================
//  Node Constructor
//  ================

	Node::Node(int listElement, Node* nextPtr, Node* prevPtr) {

		//ConstructorBanner();

		info = listElement;
		next = nextPtr;
		prev = prevPtr;


	} // Node Constructor
//  =====================


//  ==========
//  Destructor
//  ==========

	//  All deallocating is performed in DoublyLinkedList class

	Node::~Node(void) {


		//DestructorBanner();


	} // Destructor
//  ===============

//  ================
//  Member-Functions
//  ================

//  ============================
//  M-Function ConstructorBanner
//  ============================

	void Node::ConstructorBanner() {

		cout << "======================" << endl;
		cout << "Constructor Invoked..." << endl;
		cout << "======================" << endl;


	} // M-Function ConstructorBanner
//  =================================
	 


//  ===========================
//  M-Function DestructorBanner
//  ===========================

	void Node::DestructorBanner() {

		cout << "======================" << endl;
		cout << "Destructor Invoked..."  << endl;
		cout << "======================" << endl;
		cout << endl;

	} // M-Function DestructorBanner
//  ================================
