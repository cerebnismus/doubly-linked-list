/**
* @file AVLTree.cpp
* @description AVL ağacı implementasyonu
* @course 2. Öğretim A Grubu
* @assignment 2. Ödev
* @date 26.12.2020
* @author Oğuzhan İnce oguzhan.ince@ogr.sakarya.edu.tr
*/
#include "AVLTree.hpp"

Dugum::Dugum(string isim, const int vr, Dugum *sl = NULL, Dugum *sg = NULL)
{
    this->isim = isim;
    veri = vr;
    sol = sl;
    sag = sg;
    yukseklik = 0;
}
Dugum::Dugum(string isim, string calisanIsim, const int calisanYili, Dugum *sl = NULL, Dugum *sg = NULL)
{
    calisanlar = new AVLTree();
    calisanlar->Ekle(calisanIsim, calisanYili);
    this->isim = isim;
    veri = calisanlar->getSize();
    sol = sl;
    sag = sg;
    yukseklik = 0;
}

Dugum::Dugum(string isim, AVLTree *calisanlar, Dugum *sl = NULL, Dugum *sg = NULL)
{
    this->calisanlar = calisanlar;
    this->isim = isim;
    this->veri = calisanlar->getSize();
    sol = sl;
    sag = sg;
}

Dugum *AVLTree::AraveEkle(Dugum *alt_Dugum, string isim, const int yeni)
{
    if (alt_Dugum == NULL){alt_Dugum = new Dugum(isim, yeni);}
    else if ((2020 - yeni) <= (2020 - alt_Dugum->veri))
    {
        alt_Dugum->sol = AraveEkle(alt_Dugum->sol, isim, yeni);
        if (Yukseklik(alt_Dugum->sol) - Yukseklik(alt_Dugum->sag) == 2)
        {
            if ((2020 - yeni) <= (2020 - alt_Dugum->sol->veri)){alt_Dugum = SolCocukIleDegistir(alt_Dugum);}
            else
            {
                alt_Dugum->sol = SagCocukIleDegistir(alt_Dugum->sol);
                alt_Dugum = SolCocukIleDegistir(alt_Dugum);
            }
        }
    }
    else if ((2020 - yeni) > (2020 - alt_Dugum->veri))
    {
        alt_Dugum->sag = AraveEkle(alt_Dugum->sag, isim, yeni);
        if (Yukseklik(alt_Dugum->sag) - Yukseklik(alt_Dugum->sol) == 2)
        {
            if ((2020 - yeni) > (2020 - alt_Dugum->sag->veri))
            {
                alt_Dugum = SagCocukIleDegistir(alt_Dugum);
            }
            else
            {
                alt_Dugum->sag = SolCocukIleDegistir(alt_Dugum->sag);
                alt_Dugum = SagCocukIleDegistir(alt_Dugum);
            }
        }
    }
    else;
    alt_Dugum->yukseklik = Yukseklik(alt_Dugum);
    return alt_Dugum;
}

Dugum *AVLTree::AraveEkle(Dugum *alt_Dugum, string isim, string calisanIsim, const int yeni, const int calisanYil)
{
    if (alt_Dugum == NULL){alt_Dugum = new Dugum(isim, calisanIsim, calisanYil);}
    else if (yeni <= alt_Dugum->veri)
    {
        alt_Dugum->sol = AraveEkle(alt_Dugum->sol, isim, calisanIsim, yeni, calisanYil);
        if (Yukseklik(alt_Dugum->sol) - Yukseklik(alt_Dugum->sag) == 2)
        {
            if (yeni <= alt_Dugum->sol->veri){alt_Dugum = SolCocukIleDegistir(alt_Dugum);}
            else
            {
                alt_Dugum->sol = SagCocukIleDegistir(alt_Dugum->sol);
                alt_Dugum = SolCocukIleDegistir(alt_Dugum);
            }
        }
    }
    else if (yeni > alt_Dugum->veri)
    {
        alt_Dugum->sag = AraveEkle(alt_Dugum->sag, isim, calisanIsim, yeni, calisanYil);
        if (Yukseklik(alt_Dugum->sag) - Yukseklik(alt_Dugum->sol) == 2)
        {
            if (yeni > alt_Dugum->sag->veri){alt_Dugum = SagCocukIleDegistir(alt_Dugum);}
            else
            {
                alt_Dugum->sag = SolCocukIleDegistir(alt_Dugum->sag);
                alt_Dugum = SagCocukIleDegistir(alt_Dugum);
            }
        }
    }
    alt_Dugum->yukseklik = Yukseklik(alt_Dugum);
    return alt_Dugum;
}

Dugum *AVLTree::AraveEkle(Dugum *alt_Dugum, string isim, AVLTree *yeni)
{
    if (alt_Dugum == NULL)
    {
        alt_Dugum = new Dugum(isim, yeni);
    }
    else if (yeni->getSize() <= alt_Dugum->veri)
    {
        alt_Dugum->sol = AraveEkle(alt_Dugum->sol, isim, yeni);

        if (Yukseklik(alt_Dugum->sol) - Yukseklik(alt_Dugum->sag) == 2)
        {
            if (alt_Dugum->veri <= (2020 - alt_Dugum->sol->calisanlar->getSize()))
                alt_Dugum = SolCocukIleDegistir(alt_Dugum);
            else
            {
                alt_Dugum->sol = SagCocukIleDegistir(alt_Dugum->sol);
                alt_Dugum = SolCocukIleDegistir(alt_Dugum);
            }
        }
    }
    else if (yeni->getSize() > alt_Dugum->veri)
    {
        alt_Dugum->sag = AraveEkle(alt_Dugum->sag, isim, yeni);

        if (Yukseklik(alt_Dugum->sag) - Yukseklik(alt_Dugum->sol) == 2)
        {
            if (yeni->getSize() > alt_Dugum->sag->veri)
            {
                alt_Dugum = SagCocukIleDegistir(alt_Dugum);
            }

            else
            {
                alt_Dugum->sag = SolCocukIleDegistir(alt_Dugum->sag);
                alt_Dugum = SagCocukIleDegistir(alt_Dugum);
            }
        }
    }
    else;
    alt_Dugum->yukseklik = Yukseklik(alt_Dugum);
    return alt_Dugum;
}

Dugum *AVLTree::SolCocukIleDegistir(Dugum *alt_Dugum)
{
    Dugum *tmp = alt_Dugum->sol;
    alt_Dugum->sol = tmp->sag;
    tmp->sag = alt_Dugum;
    alt_Dugum->yukseklik = Yukseklik(alt_Dugum);
    tmp->yukseklik = max(Yukseklik(tmp->sol), alt_Dugum->yukseklik) + 1;
    return tmp;
}

Dugum *AVLTree::SagCocukIleDegistir(Dugum *alt_Dugum)
{
    Dugum *tmp = alt_Dugum->sag;
    alt_Dugum->sag = tmp->sol;
    tmp->sol = alt_Dugum;
    alt_Dugum->yukseklik = Yukseklik(alt_Dugum);
    tmp->yukseklik = max(Yukseklik(tmp->sag), alt_Dugum->yukseklik) + 1;
    return tmp;
}

int AVLTree::agacKontrol(Dugum *node)
{
    if (node == NULL)
        return 1;
    if (node->sol != NULL && maxDeger(node->sol) > node->veri)
    {
        if (maxDeger(node->sol) > node->veri)
        {
            AVLTree *calisanlar = maxDegerliDugum(node->sol)->calisanlar;
            string isim = maxDegerliDugum(node->sol)->isim;
            int veri = maxDegerliDugum(node->sol)->veri;
            deleteDugum(veri, isim);
            Ekle(isim, calisanlar);
            return 0;
        }
        else
        {
            AVLTree *calisanlar = node->calisanlar;
            string isim = node->isim;
            int veri = node->veri;
            deleteDugum(veri, isim);
            Ekle(isim, calisanlar);
            return 0;
        }
    }
    if (node->sag != NULL && minDeger(node->sag) < node->veri)
    {
        if (node->veri > minDeger(node->sag))
        {
            AVLTree *calisanlar = node->calisanlar;
            string isim = node->isim;
            int veri = node->veri;
            deleteDugum(veri, isim);
            Ekle(isim, calisanlar);
        }
        else
        {
            AVLTree *calisanlar = minDegerliDugum(node->sag)->calisanlar;
            string isim = minDegerliDugum(node->sag)->isim;
            int veri = minDegerliDugum(node->sag)->veri;
            deleteDugum(veri, isim);
            Ekle(isim, calisanlar);
        }
        return 0;
    }
    if (!agacKontrol(node->sol) || !agacKontrol(node->sag)){return 0;}
    return 1;
}

int AVLTree::agacKontrol(){return agacKontrol(root);}
int AVLTree::maxDeger(Dugum *dugum){return maxDegerliDugum(dugum)->veri;}
int AVLTree::minDeger(Dugum *dugum){return minDegerliDugum(dugum)->veri;}

void AVLTree::Inorder(Dugum *alt_Dugum) const
{
    if (alt_Dugum != NULL)
    {
        Inorder(alt_Dugum->sol);
        cout << alt_Dugum->veri << " ";
        Inorder(alt_Dugum->sag);
    }
}

void AVLTree::Preorder(Dugum *alt_Dugum) const
{
    if (alt_Dugum != NULL)
    {
        cout << alt_Dugum->veri << " ";
        Preorder(alt_Dugum->sol);
        Preorder(alt_Dugum->sag);
    }
}

void AVLTree::Postorder(Dugum *alt_Dugum) const
{
    if (alt_Dugum != NULL)
    {
        Postorder(alt_Dugum->sol);
        Postorder(alt_Dugum->sag);
        cout << alt_Dugum->isim << " ";
        cout << alt_Dugum->veri << " \n";
        alt_Dugum->calisanlar->Postorder2();
        cout << " \n" << endl;
    }
}

void AVLTree::Postorder2(Dugum *alt_Dugum) const
{
    if (alt_Dugum != NULL)
    {
        Postorder2(alt_Dugum->sol);
        Postorder2(alt_Dugum->sag);
        cout << alt_Dugum->isim << " – ";
        cout << alt_Dugum->veri << " | ";
    }
}

void AVLTree::SeviyeyiYazdir(Dugum *alt_Dugum, int seviye) const
{
    if (alt_Dugum == NULL){return;}
    if (seviye == 0){cout << alt_Dugum->veri << " ";}
    else
    {
        SeviyeyiYazdir(alt_Dugum->sol, seviye - 1);
        SeviyeyiYazdir(alt_Dugum->sag, seviye - 1);
    }
}

int AVLTree::Yukseklik(Dugum *alt_Dugum) const
{
    if (alt_Dugum == NULL){return -1;}
    return 1 + max(Yukseklik(alt_Dugum->sol), Yukseklik(alt_Dugum->sag));
}

bool AVLTree::DugumSil(Dugum *&alt_Dugum)
{
    Dugum *silinecekDugum = alt_Dugum;
    if (alt_Dugum->sag == NULL){alt_Dugum = alt_Dugum->sol;}
    else if (alt_Dugum->sol == NULL){alt_Dugum = alt_Dugum->sag;}
    else
    {
        silinecekDugum = alt_Dugum->sol;
        Dugum *ebeveynDugum = alt_Dugum;
        while (silinecekDugum->sag != NULL)
        {
            ebeveynDugum = silinecekDugum;
            silinecekDugum = silinecekDugum->sag;
        }
        alt_Dugum->veri = silinecekDugum->veri;
        if (ebeveynDugum == alt_Dugum)
            alt_Dugum->sol = silinecekDugum->sol;
        else
            ebeveynDugum->sag = silinecekDugum->sol;
    }
    delete silinecekDugum;
    size--;
    return true;
}

bool AVLTree::Ara(Dugum *alt_Dugum, string aranan)
{
    if (alt_Dugum == NULL){return false;}
    else if (alt_Dugum != NULL)
    {
        if (alt_Dugum->isim == aranan){return true;}
        else
        {
            bool temp = Ara(alt_Dugum->sol, aranan);
            if (temp == false){temp = Ara(alt_Dugum->sag, aranan);}
            return temp;
        }
    }
}

Dugum *AVLTree::AraGetir(Dugum *alt_Dugum, string isim)
{

    if (alt_Dugum != NULL)
    {
        if (alt_Dugum->isim == isim){return alt_Dugum;}
        else
        {
            Dugum *temp = AraGetir(alt_Dugum->sol, isim);
            if (temp == NULL){temp = AraGetir(alt_Dugum->sag, isim);}
            return temp;
        }
    }
    else{return NULL;}
}

Dugum *AVLTree::AraGetir(string isim){return AraGetir(root, isim);}

AVLTree::AVLTree()
{
    root = NULL;
    size = 0;
}

int AVLTree::getSize(){return this->size;}
bool AVLTree::Bosmu() const{return root == NULL;}

void AVLTree::Ekle(string isim, string calisanIsim, const int calisanYil)
{
    bool deneme;
    deneme = Arama(isim);
    if (deneme == true)
    {
        Dugum *temp = AraGetir(isim);
        temp->calisanlar->Ekle(calisanIsim, calisanYil);
        temp->veri++;
    }
    else
    {
        root = AraveEkle(root, isim, calisanIsim, 1, calisanYil);
        size++;
    }
    agacKontrol();
}

void AVLTree::Ekle(string isim, const int yeni)
{
    root = AraveEkle(root, isim, yeni);
    size++;
}

void AVLTree::Ekle(string isim, AVLTree *yeni){root = AraveEkle(root, isim, yeni);}
void AVLTree::Inorder() const{Inorder(root);}
void AVLTree::Preorder() const{Preorder(root);}
void AVLTree::Postorder() const{Postorder(root);}
void AVLTree::Postorder2() const{Postorder2(root);}

void AVLTree::Levelorder() const
{
    int h = Yukseklik();
    for (int level = 0; level <= h; level++){SeviyeyiYazdir(root, level);}
}

bool AVLTree::Arama(string aranan){return Ara(root, aranan);}

void AVLTree::Temizle()
{
    while (!Bosmu())
    {
        root->calisanlar->CalisanTemizle();
        DugumSil(root);
    }
        
}

void AVLTree::CalisanTemizle(){while (!Bosmu()){DugumSil(root);}}
int AVLTree::Yukseklik() const{return Yukseklik(root);}

int AVLTree::getBalance(Dugum *N)
{
    if (N == NULL){return 0;}
    return Yukseklik(N->sol) - Yukseklik(N->sag);
}

Dugum *AVLTree::minDegerliDugum(Dugum *alt_Dugum)
{
    Dugum *current = alt_Dugum;
    while (current->sol != NULL){current = current->sol;}
    return current;
}

Dugum *AVLTree::maxDegerliDugum(Dugum *alt_Dugum)
{
    Dugum *current = alt_Dugum;
    while (current->sag != NULL){current = current->sag;}
    return current;
}

Dugum *AVLTree::deleteDugum(Dugum *root, int veri, string isim)
{

    if (root == NULL){return root;}
    else if (isim != root->isim)
    {
        root->sol = deleteDugum(root->sol, veri, isim);
        root->sag = deleteDugum(root->sag, veri, isim);
    }
    else if (isim == root->isim)
    {
        if ((root->sol == NULL) || (root->sag == NULL))
        {
            Dugum *temp = root->sol ? root->sol : root->sag;
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else{*root = *temp;}
            free(temp);
        }
        else
        {
            Dugum *temp = maxDegerliDugum(root->sol);
            root->veri = temp->veri;
            root->isim = temp->isim;
            root->calisanlar = temp->calisanlar;
            root->sol = deleteDugum(root->sol, temp->veri, temp->isim);
        }
    }
    
    if (root == NULL){return root;}
    root->yukseklik = 1 + max(Yukseklik(root->sol), Yukseklik(root->sag));
    int balance = getBalance(root);
    if (balance > 1 && getBalance(root->sol) >= 0){return SolCocukIleDegistir(root);}
    if (balance > 1 && getBalance(root->sol) < 0)
    {
        root->sol = SagCocukIleDegistir(root->sol);
        return SolCocukIleDegistir(root);
    }

    if (balance < -1 && getBalance(root->sag) <= 0){return SagCocukIleDegistir(root);}
    if (balance < -1 && getBalance(root->sag) > 0)
    {
        root->sag = SolCocukIleDegistir(root->sag);
        return SagCocukIleDegistir(root);
    }
    return root;
}
void AVLTree::deleteDugum(int veri, string isim){root = deleteDugum(root, veri, isim);}
AVLTree::~AVLTree(){Temizle();}
