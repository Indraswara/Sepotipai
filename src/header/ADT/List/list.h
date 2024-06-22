#ifndef SINGER_SingerList_H 
#define SINGER_LISTDIH_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../../shared/boolean.h"

#define IDX_MIN 0
#define IDX_UNDEF -1


typedef const char* ElType; 
typedef int IdxType; 

typedef struct{
    ElType *buffer; 
    int nEff; 
    int capacity; 
} ListDin; 

/* ============SELEKTOR===========*/
#define NEFF(l) (l).nEff
#define BUFFER(l) (l).buffer
#define ELMT(l, i) (l).buffer[i]
#define CAPACITY(l) (l).capacity

void CreateListDin(ListDin *l, int capacity);
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */

void dealocateList(ListDin *l);
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength(ListDin l);
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */

/* *** Selektor INDEKS *** */
IdxType getLastIdx(ListDin l);
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */


/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */

boolean isIdxValid(ListDin l, IdxType i);
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxEff(ListDin l, IdxType i);
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmpty(ListDin l);
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
boolean isFull(ListDin l);
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void readList(ListDin *l);
void printList(ListDin l);
void insertLast(ListDin *l, ElType val);
void deleteLast(ListDin *l, ElType *val);
void expandList(ListDin *l, int num);
void copyList(ListDin lIn, ListDin *lOut);

#endif