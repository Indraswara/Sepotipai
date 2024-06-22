#include "../../../header/ADT/List/list.h"


void CreateListDin(ListDin *l, int capacity)
{
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
    BUFFER(*l) = (ElType*)malloc(capacity * sizeof(ElType));
    NEFF(*l) = 0;
    CAPACITY(*l) = capacity;

}

void dealocateList(ListDin *l)
{
    CAPACITY(*l) = 0; 
    NEFF(*l) = 0; 
    free(BUFFER(*l));
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength(ListDin l){
    return NEFF(l);
}

/* *** Selektor INDEKS *** */
IdxType getLastIdx(ListDin l){
    return ((IdxType)(listLength(l)-1));
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListDin l, IdxType i){
    return ((i < CAPACITY(l)) && (i >= IDX_MIN));
}
boolean isIdxEff(ListDin l, IdxType i)
{
    return ((i < NEFF(l)) && (i >= IDX_MIN));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmpty(ListDin l){
    return (listLength(l) == 0);
}

boolean isFull(ListDin l){
    return (listLength(l) == CAPACITY(l));
}

void readList(ListDin *l){
    int N; 
    IdxType idx;
    char elmnt[100]; // Assuming MAX_LENGTH is defined appropriately

    scanf("%d", &N); 
    while(N < 0 || N > CAPACITY(*l)){
        scanf("%d", &N);
    }
    NEFF(*l) = N; 

    if(N > 0){
        for(idx = 0; idx < (IdxType)N; idx++){
            scanf("%s", elmnt);
            ELMT(*l, idx) = strdup(elmnt); // Assuming you want to store a copy of the string
        }
    }
}

void printList(ListDin l){
    IdxType idx; 
    for(idx = 0; idx < listLength(l); idx++){
        printf("%d. %s\n", idx + 1, ELMT(l, idx));
    }
}

void insertLast(ListDin *l, ElType val){
    ELMT(*l, NEFF(*l)) = val;
    NEFF(*l) += 1; 
}

void deleteLast(ListDin *l, ElType *val){
    *val = ELMT(*l, getLastIdx(*l));
    NEFF(*l)--; 
}

void expandList(ListDin *l, int num){
    ListDin tempList; 
    int idx; 
    CreateListDin(&tempList, CAPACITY(*l) + num);
    for(idx = 0; idx<listLength(*l); idx++){
        ELMT(tempList, idx) = ELMT(*l, idx);
    }
    NEFF(tempList) = NEFF(*l); 
    dealocateList(l); 
    copyList(tempList, l);
}

void copyList(ListDin lIn, ListDin *lOut){
    IdxType i; 
    CreateListDin(lOut, CAPACITY(lIn));
    NEFF(*lOut) = NEFF(lIn);
    for(i = 0; i<listLength(lIn); i++){
        ELMT(*lOut, i) = ELMT(lIn, i);
    }
}
