#ifndef AVLTREE_HPP
#define AVLTREE_HPP

#include <cmath>
#include "ElemanYok.hpp"

struct Dugum;

class AVLTree
{
private:
	Dugum *root;
	int size;
	Dugum *AraveEkle(Dugum *, string, const int);
	Dugum *AraveEkle(Dugum *, string, string, const int,const int);
	Dugum *AraveEkle(Dugum *, string, AVLTree *);
	Dugum *SolCocukIleDegistir(Dugum *);
	Dugum *SagCocukIleDegistir(Dugum *);
	void Inorder(Dugum *) const;
	void KiyaslaGuncelle(Dugum *);
	void Preorder(Dugum *) const;
	void Postorder(Dugum *) const;
	void Postorder2(Dugum *) const;
	void SeviyeyiYazdir(Dugum *, int) const;
	int Yukseklik(Dugum *) const;
	bool DugumSil(Dugum *&);
	bool Ara(Dugum *, string);
	Dugum* AraGetir(Dugum *, string );

public:
	AVLTree();
	int getSize();
	bool Bosmu() const;
	void Ekle(string, string, const int);
	void Ekle(string isim, const int);
	void Ekle(string isim, AVLTree *);
	void Inorder() const;
	void Preorder() const;
	void Postorder() const;
	void Postorder2() const;
	void Levelorder() const;
	int getBalance(Dugum *);
	int agacKontrol(Dugum *);
	int agacKontrol();
	int maxDeger(Dugum* );
	int minDeger(Dugum* );
	Dugum *minDegerliDugum(Dugum *);
	Dugum *maxDegerliDugum(Dugum *);
	Dugum *deleteDugum(Dugum *, int,string);
	void CalisanTemizle();
	void deleteDugum(int,string);
	bool Arama(string);
	Dugum* AraGetir(string isim);
	void Temizle();
	int Yukseklik() const;
	~AVLTree();
};

struct Dugum
{
	AVLTree *calisanlar;
	string isim;
	int veri;
	Dugum *sol;
	Dugum *sag;
	int yukseklik;
	Dugum(string, const int, Dugum *, Dugum *);
	Dugum(string, string, const int, Dugum *, Dugum *);
	Dugum(string, AVLTree*, Dugum *, Dugum *);
};

#endif