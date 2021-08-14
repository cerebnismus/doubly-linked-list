/**
 * @file Iterator.cpp
 * @description Iterator Implementation
 * @course 1/A
 * @assignment Ödev I
 * @date 14.08.2021
 * @author u161210071 - oguzhan.ince@ogr.sakarya.edu.tr
 */

#include <iostream>
using namespace std;
#include "Iterator.hpp"

Iterator::Iterator()
{
	current = nullptr;
}
Iterator::Iterator(Dugum *node)
{
	current = node;
}
bool Iterator::IsEndNode()
{
	return current == nullptr;
}
void Iterator::StepNext()
{
	if (!IsEndNode())
		current = current->next;
}
void Iterator::StepBack()
{
	if (!IsEndNode())
		current = current->prev;
}
int Iterator::GetCurrentData()
{
	return current->data;
}
