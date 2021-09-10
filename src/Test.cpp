/**
 * @file Test.cpp
 * @description Main Function
 * @author oguzhan.ince@protonmail.com
 */

#include <iostream>
#include "DoublyLinkedList.hpp"
#include "Dugum.hpp"
#include <iostream>
#include <fstream>
#include <String.h>

using namespace std;
Dugum *elemaniGetir(int index, DoublyLinkedList *list); //listede indexteki düğümü getirir
void terscevir(DoublyLinkedList *list);
void yazdir(DoublyLinkedList *list); //listeyi ters çevirir
int main()
{
    string firstlist;         // 1.listenin elemanlarını tutar
    string secondlist;        // 2.listenin elemanlarını tutar
    string line;              // dosyadaki satırın tamamını tutar
    ifstream File;            //dosya açılır
    File.open("Sayilar.txt"); // sayılar.txt dosyasını açar
    getline(File, line);
    DoublyLinkedList *listone = new DoublyLinkedList(); // liste nesneleri oluşturulur
    DoublyLinkedList *listwo = new DoublyLinkedList();
    if (line[line.length() / 2] == '#')
    {
        firstlist = line.substr(0, line.length() / 2);                      // ilk listeye eklenecek string oluşturulur
        secondlist = line.substr(line.length() / 2 + 1, line.length() - 1); // ikinci listeye eklenecek string oluşturulur
        int size = firstlist.length();                                      // for döngüsü string ifadelerin uzunluğu kadar döneceği için uzunluk alınır
        for (int i = 0; i < size / 3; i++)                                  //3er li parçalar halinde ilerlendiği için sizeın 3te biri kadar ilerliyoruz
        {
            if (firstlist[0] == '0') // ilk eleman 0 mı diye kontrol edilir
            {
                firstlist[0] = '1'; //değilse 1 yazıyoruz
            }
            if (secondlist[0] == '0') // ilk eleman 0 mı diye kontrol edilir
            {
                secondlist[0] = '1'; //değilse 1 yazıyoruz
            }
            listone->Add(stoi(firstlist.substr(0, 3))); // stringin ilk 3 hanesini inte çevirip listeye ekliyoruz
            listwo->Add(stoi(secondlist.substr(0, 3))); // stringin ilk 3 hanesini inte çevirip listeye ekliyoruz
            firstlist.erase(0, 3);                      //ilk stringin ilk 3 hanesini siliyoruz
            secondlist.erase(0, 3);                     //ikinci stringin ilk 3 hanesini siliyoruz
        }
    }
    File.close();                              // dosya kapatılır
    for (int i = 0; i < listone->Count(); i++) //listelerin uzunlunluğu kadar dönen bir döngü oluşturulur
    {
        Dugum *node1 = elemaniGetir(i, listone); //değişecek düğümler ve düğümler listeden çekilir
        Dugum *node2 = elemaniGetir(i, listwo);
        if (node1->data < node2->data) // ilk liste elemanı küçükse
        {
            Dugum *node1prev = node1->prev; //değişecek düğümler ve düğümlerin nexti ve prevleri listeden çekilir
            Dugum *node2prev = node2->prev;
            Dugum *node1next = node1->next;
            Dugum *node2next = node2->next;
            node1prev->next = node2; // düğümler değişecek düğümlerin önü ve arkası olmak üzere 8 farklı bağlantı yapılarak bağlanır
            node2prev->next = node1;
            node1->prev = node2prev;
            node2->prev = node1prev;
            node1->next = node2next;
            node2->next = node1next;
            if (node2next != NULL) //eğer son düğüm değişiyor ise ondan sonraki düğümün previ olmayacağından alttaki işlemler bu durumda yapılmamalıdır
            {
                node2next->prev = node1;
                node1next->prev = node2;
            }
        }
        else if (node1->data > node2->data) //seçilen düğümlerden ilk listenin düğümünün datası daha büyükse bu if çalışır
        {
            terscevir(listone); // listone ters çevirilir
        }
        else //seçilen düğümlerden ilk listenin düğümünün dataları eşitse bu if çalışır
        {
            terscevir(listwo); // listwo ters çevirilir
        }
    }
    cout << "Sayi 1:";
    yazdir(listone); // listone yazdırılır
    cout << "Sayi 2:";
    yazdir(listwo); // listwo yazdırılır
    delete listone; // liste sınıfının yıkıcı fonksiyonu çağırılır
    delete listwo;
}
void terscevir(DoublyLinkedList *list) // listeyi ters çeviren fonksiyon
{
    Dugum *head = list->Head();
    Dugum *current = head->next;  //listenin headi döndürülür
    Dugum *after = current->next; //headin bir sonrasındaki düğüm alınır
    current->next = NULL;
    current->prev = after;
    while (after) // after düğümü nullı gösterene kadar döngü devam eder
    {
        after->prev = after->next; //sonraki düğüm bir önceki düğümle yer değiştire değiştire döngü devam eder
        after->next = current;
        current = after;
        after = after->prev;
    }
    list->Head()->next = current; // listenin ilk elemanı headin nextine bağlanır
    head->next->prev = head; //ilk eleman heade bağlanır
}
Dugum *elemaniGetir(int index, DoublyLinkedList *list) // listeden indexteki istenilene düğüm döndürülür
{

    Dugum *temp = list->Head()->next; //listenin ilk elemanı alınır
    for (int i = 0; i < index; i++)
    {
        temp = temp->next; // istenilen elemana ulaşana kadar bu döngü devam eder
    }
    return temp; 
}
void yazdir(DoublyLinkedList *list) // fonksiyona parametre ile gönderilen liste elemanları yazdırılır
{
    Dugum *temp = elemaniGetir(0, list);
    for (int i = 0; i < list->Count(); i++)
    {
        cout << temp->data; // düüğm datası yazdırılır
        temp = temp->next;
    }
    cout << endl;
}
