/**
* @file test.cpp
* @description Veriler dosyadan satır satır okunarak AVL ağacı olusturma ve postorder olarak ekrana yazdirma
* @course 2. Öğretim A Grubu
* @assignment 2. Ödev
* @date 26.12.2020
* @author Oğuzhan İnce oguzhan.ince@ogr.sakarya.edu.tr
*/
#include "AVLTree.hpp"
#include <fstream>

void kelimeOku(string str, AVLTree *agac)
{
	int i = 0;
	string dizi[3];
	string word = "";
	int sayi;
	for (char x : str)
	{
		if (x == '#')
		{
			dizi[i] = word;
			word = "";
			i++;
		}
		else{word = word + x;}
	}
	dizi[2] = word;
	agac->Ekle(dizi[0],dizi[1],stoi(dizi[2]));
    // cout<<"func: kelimeOku"<<endl;
}

void satirOku(AVLTree *agac)
{
	int i = 0;
	ifstream file("Veri.txt");
	if (file.is_open())
	{
		string line;
		while (getline(file, line))
		{
			kelimeOku(line, agac);
			i++;
		}
		file.close();
	}
    // cout<<"func: satirOku"<<endl;
}

int main()
{
    cout<<endl;
	AVLTree *agac = new AVLTree();
	satirOku(agac);
    // cout<<"Postorder :\n"<<endl;
	agac->Postorder();
	delete agac;
	return 0;
}
