/**
 * @file Dugum.hpp
 * @description Node Implementation Header File
 * @course 1/A
 * @assignment Ödev I
 * @date 14.08.2021
 * @author u161210071 - oguzhan.ince@ogr.sakarya.edu.tr
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

