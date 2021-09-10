/**
 * @file DoublyLinkedList.cpp
 * @description DoublyLinkedList Implementation
 * @author oguzhan.ince@protonmail.com
 */
#include <iostream>
#include "Iterator.hpp"
#include "DoublyLinkedList.hpp"

using namespace std;

Iterator DoublyLinkedList::IterateFromPrevIndex(int index) // Listedeki istenilen indexden önceki indexi döndürür
{
	if (!(index < 0 || index > Count()))
	{
		int i = 0;
		Iterator itr(head);
		while (!itr.IsEndNode() && index != i++)
			itr.StepNext();
		return itr;
	}
	return NULL;
}
Iterator DoublyLinkedList::IterateFromFirstNode() // ilk düğüm döner
{
	if (!IsEmpty())
		return Iterator(head->next);
	return NULL;
}
DoublyLinkedList::DoublyLinkedList() //kurucu fonksiyon
{
	head = new Dugum();
	size = 0;
}

bool DoublyLinkedList::IsEmpty() // liste boş mu kontrolü yapar
{
	return head->next == NULL;
}
int DoublyLinkedList::Count() //listenin eleman sayısını döndürür
{
	return size;
}
const int DoublyLinkedList::First() //listenin ilk elemanı döner
{
	return head->next->data;
}
const int DoublyLinkedList::Last() //listenin son elemanı döner
{
	return IterateFromPrevIndex(size).GetCurrentData();
}
void DoublyLinkedList::Add(const int &obj) // liste sonuna eleman ekler
{
	Insert(Count(), obj);
}
Dugum *DoublyLinkedList::Head() // headi döndürür
{
	return head;
}
void DoublyLinkedList::RemoveAt(int index) // listeden istenilen indexteki elemanı siler
{
	Iterator itr;
	itr = IterateFromPrevIndex(index);
	if (itr.current->next != NULL)
	{
		Dugum *oldNode = itr.current->next;
		itr.current->next = itr.current->next->next;
		if (oldNode->next != NULL)
			oldNode->next->prev = oldNode->prev;
		delete oldNode;
		size--;
	}
}
void DoublyLinkedList::Insert(int index, const int &obj) // listede istenilen indexe eleman ekler
{
	Iterator itr;
	itr = IterateFromPrevIndex(index);
	Dugum *newNext = itr.current->next;
	itr.current->next = new Dugum(obj, newNext, itr.current);
	if (newNext != NULL)
		newNext->prev = itr.current->next;
	size++;
}

void DoublyLinkedList::Clear() // listedeki elemanları siler
{
	while (!IsEmpty())
	{
		RemoveAt(0);
	}
}

DoublyLinkedList::~DoublyLinkedList() // yıkıcı fonksiyon
{
	Clear();
	delete head;
}

