/**
 * @file DoublyLinkedList.hpp
 * @description DoublyLinkedList Implementation Header File
 * @course 1/A
 * @assignment Ödev I
 * @date 14.08.2021
 * @author u161210071 - oguzhan.ince@ogr.sakarya.edu.tr
 */

#ifndef DOUBLYLINKEDLIST_HPP
#define DOUBLYLINKEDLIST_HPP
#include "Iterator.hpp"
#include "Dugum.hpp"

class DoublyLinkedList
{
private:
	Dugum *head;
	int size;

	Iterator IterateFromPrevIndex(int index);
	Iterator IterateFromFirstNode();

public:
	DoublyLinkedList();
	bool IsEmpty();
	int Count();
	const int First();
	const int Last();
	Dugum *Head();
	void RemoveAt(int index);
	void Add(const int &obj);
	void Insert(int index, const int &obj);
	void Clear();
	~DoublyLinkedList();
};
#endif
