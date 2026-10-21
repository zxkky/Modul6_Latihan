#include "doublylist.h"

void CreateList(List &L) {
    L.First = Nil;
    L.Last = Nil;
}

void createList(List &L) {
    CreateList(L);
}

address alokasi(infotype x) {
    address P = new ElmList;
    if (P != Nil) {
        P->info = x;
        P->next = Nil;
        P->prev = Nil;
    }
    return P;
}

void dealokasi(address &P) {
    if (P != Nil) {
        delete P;
        P = Nil;
    }
}

void printInfo(List L) {
    address P = L.Last; 
    while (P != Nil) {
        cout << "no polisi : " << P->info.nopol << endl;
        cout << "warna     : " << P->info.warna << endl;
        cout << "tahun     : " << P->info.thnBuat << endl;
        P = P->prev;
    }
}

void insertLast(List &L, address P) {
    if (P != Nil) {
        if (L.First == Nil && L.Last == Nil) {
            L.First = P;
            L.Last = P;
            P->prev = Nil;
            P->next = Nil;
        } else {
            P->prev = L.Last; 
            P->next = Nil;
            L.Last->next = P; 
            L.Last = P; 
        }
    }
}

void insertFirst(List &L, address P) {
    if (P != Nil) {
        if (L.First == Nil && L.Last == Nil) {
            L.First = P;
            L.Last = P;
            P->prev = Nil;
            P->next = Nil;
        } else {
            P->next = L.First;
            P->prev = Nil;
            L.First->prev = P;
            L.First = P;
        }
    }
}

// Mencari elemen berdasarkan nomor polisi (Modul 6.2 No. 2)
address findElm(List L, infotype x) {
    address P = L.First;
    while (P != Nil) {
        if (P->info.nopol == x.nopol) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

// Prosedur Delete (Modul 6.2 No. 3)
void deleteFirst(List &L, address &P) {
    if (L.First != Nil) {
        P = L.First;
        if (L.First == L.Last) {
            L.First = Nil;
            L.Last = Nil;
        } else {
            L.First = L.First->next; 
            L.First->prev = Nil; 
        }
        P->next = Nil; 
        P->prev = Nil;
    } else {
        P = Nil;
    }
}

void deleteLast(List &L, address &P) {
    if (L.Last != Nil) {
        P = L.Last;
        if (L.First == L.Last) {
            L.First = Nil;
            L.Last = Nil;
        } else {
            L.Last = L.Last->prev; 
            L.Last->next = Nil; 
        }
        P->next = Nil;
        P->prev = Nil; 
    } else {
        P = Nil;
    }
}

void deleteAfter(address Prec, address &P) {
    if (Prec != Nil && Prec->next != Nil) {
        P = Prec->next;
        Prec->next = P->next;
        if (P->next != Nil) {
            P->next->prev = Prec; 
        }
        P->next = Nil; 
        P->prev = Nil;
    } else {
        P = Nil;
    }
}
