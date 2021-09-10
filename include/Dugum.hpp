/**
 * @file Dugum.hpp
 * @description Node Implementation Header File
 * @author oguzhan.ince@protonmail.com
 */

#ifndef DUGUM_HPP
#define DUGUM_HPP

class Dugum
{
public:
	int data;																	
	Dugum *next;																 
	Dugum *prev;																  
	Dugum(const int &data = int(), Dugum *next = nullptr, Dugum *prev = nullptr); //kurucu
};
#endif

