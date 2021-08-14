/**
 * @file Dugum.cpp
 * @description Node Implementation
 * @course 1/A
 * @assignment Ödev I
 * @date 14.08.2021
 * @author u161210071 - oguzhan.ince@ogr.sakarya.edu.tr
 */

#include "Dugum.hpp"
using namespace std;

Dugum::Dugum(const int &data, Dugum *next, Dugum *prev) // düğümün kurucu fonksiyonu
{
	this->data = data;
	this->next = next;
	this->prev = prev;
}

