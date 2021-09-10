/**
 * @file Iterator.hpp
 * @description Iterator Implementation Header File
 * @author oguzhan.ince@protonmail.com
 */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP
#include "Dugum.hpp"
class Iterator
{
public:
	Dugum *current;
	Iterator()
	{
		current = nullptr;
	}
	Iterator(Dugum *node)
	{
		current = node;
	}
	bool IsEndNode()
	{
		return current == nullptr;
	}
	void StepNext()
	{
		if (!IsEndNode())
			current = current->next;
	}
	void StepBack()
	{
		if (!IsEndNode())
			current = current->prev;
	}
	int GetCurrentData()
	{
		return current->data;
	}
};
#endif
