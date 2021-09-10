/**
 * @file Dugum.cpp
 * @description Node Implementation
 * @author oguzhan.ince@protonmail.com
 */

#include "Dugum.hpp"
using namespace std;

Dugum::Dugum(const int &data, Dugum *next, Dugum *prev) // düğümün kurucu fonksiyonu
{
	this->data = data;
	this->next = next;
	this->prev = prev;
}

