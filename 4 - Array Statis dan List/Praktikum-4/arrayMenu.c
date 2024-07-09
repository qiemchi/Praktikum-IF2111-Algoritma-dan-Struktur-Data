#include <stdio.h>

#include "arrayMenu.h"


void MakeEmpty (TabMenu *T)
{
    (*T).Neff = 0;
}

int NbElmt (TabMenu T)
{
    return T.Neff;
}

int MaxNbEl (TabMenu T)
{
    return IdxMax - IdxMin + 1;
}

IdxType GetFirstIdx (TabMenu T)
{
    return IdxMin;
}

IdxType GetLastIdx (TabMenu T)
{
    return T.Neff;
}

ElType GetElmt (TabMenu T, IdxType i)
{
    return T.TI[i];
}

void SetTab (TabMenu Tin, TabMenu *Tout)
{
    (*Tout).Neff = Tin.Neff;
    for(int i = IdxMin; i <= Tin.Neff; i++)
    {
        (*Tout).TI[i] = Tin.TI[i];
    }
}

void SetEl (TabMenu *T, IdxType i, ElType v)
{
    (*T).TI[i] = v;
    if ((*T).Neff < i)
    {
        (*T).Neff = i;
    }    
}

void SetNeff (TabMenu *T, IdxType N)
{
    (*T).Neff = N;
}

boolean IsIdxValid (TabMenu T, IdxType i)
{
    return ((i >= IdxMin) && (i <= IdxMax));
}

boolean IsIdxEff (TabMenu T, IdxType i)
{
    return ((i >= GetFirstIdx(T)) && (i <= GetLastIdx(T)));
}

boolean IsEmpty (TabMenu T)
{
    return (T.Neff == 0);
}

boolean IsFull (TabMenu T)
{
    return (T.Neff == IdxMax);
}

void TulisIsi (TabMenu T)
{
    if(IsEmpty(T))
    {
        printf("Tabel kosong\n");
    }
    else
    {
        for(int i = GetFirstIdx(T); i <= GetLastIdx(T); i++)
        {
            printf("%s - %s - Rp.%d\n", T.TI[i].nama, T.TI[i].tipe, T.TI[i].harga);
        }
    }
}

ElType MakeMenu (char *nama, char *tipe, int harga)
{
    ElType menu;
    menu.nama = nama;
    menu.tipe = tipe;
    menu.harga = harga;
    return menu;
}

int MenuMax (TabMenu T)
{
    int maks = T.TI[GetFirstIdx(T)].harga;
    for(int i = GetFirstIdx(T) + 1; i <= GetLastIdx(T); i++)
    {
        if(T.TI[i].harga > maks)
        {
            maks = T.TI[i].harga;
        }
    }
    return maks;
}

int MenuMin (TabMenu T)
{
    int mins = T.TI[GetFirstIdx(T)].harga;
    for(int i = GetFirstIdx(T) + 1; i <= GetLastIdx(T); i++)
    {
        if(T.TI[i].harga < mins)
        {
            mins = T.TI[i].harga;
        }
    }
    return mins;
}

int MakananCount (TabMenu T)
{
    int makanan = 0;
    for(int i =  GetFirstIdx(T); i <= GetLastIdx(T); i++)
    {
        if(T.TI[i].tipe[1] == 'a') {makanan++;}
    }
    return makanan;
}

int MinumanCount (TabMenu T)
{
    int minuman = 0;
    for(int i =  GetFirstIdx(T); i <= GetLastIdx(T); i++)
    {
        if(T.TI[i].tipe[1] == 'i') {minuman++;}
    }
    return minuman;
}

void MenuData (TabMenu T)
{
    printf("Jumlah Menu Makanan: %d\n", MakananCount(T));
    printf("Jumlah Menu Minuman: %d\n", MinumanCount(T));
    printf("Harga Menu Termahal: Rp.%d\n", MenuMax(T));
    printf("Harga Menu Termurah: Rp.%d\n", MenuMin(T));
}

