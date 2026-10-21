#ifndef DOUBLYLIST_H_INCLUDED
#define DOUBLYLIST_H_INCLUDED

#include <iostream>
#include <string>

#define Nil NULL

using namespace std;

// Tipe data kendaraan (Modul 6.2 No. 1)
struct kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};

typedef kendaraan infotype;
typedef struct ElmList *address;

// Struct elemen Doubly Linked List
struct ElmList {
    infotype info;
    address next;
    address prev;
};

// Struct List
struct List {
    address First;
    address Last;
};

// Prototipe Fungsi dan Prosedur ADT Doubly Linked List
void CreateList(List &L);
void createList(List &L); // alias lowercase
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertLast(List &L, address P);
void insertFirst(List &L, address P); // prosedur tambahan helper

// Fungsi & Prosedur Latihan (Modul 6.2 No. 2 & 3)
address findElm(List L, infotype x);
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(address Prec, address &P);

#endif // DOUBLYLIST_H_INCLUDED
