/**
 * @file Iterator.hpp
 * @description Iterator Implementation Header File
 * @course 1/A
 * @assignment Ödev I
 * @date 14.08.2021
 * @author u161210071 - oguzhan.ince@ogr.sakarya.edu.tr
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
