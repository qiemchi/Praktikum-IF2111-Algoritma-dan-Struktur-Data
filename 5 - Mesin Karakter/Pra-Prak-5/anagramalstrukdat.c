#include "mesinkarakterv2.h"
#include "mesinkata.h"
#include "boolean.h"
#include "anagramalstrukdat.h"


/*  Menerima sebuah parameter string bertipe string
    Mengirimkan panjang sebuah string */
int stringLength (char* string)
{ 
  int i = 0;
  while (string != '\0')
  {
    string++;
    i++;
  }

  return i;
}

/*  Menerima sebuah paramater command bertipe string
    Mengirimkan kata yang elemen of arraynya berasal dari command */
Word toKata(char* command)
{
  Word Kata;
  Kata.Length = stringLength(command);

  for (int i = 0; i < stringLength(command); i++){
  Kata.TabWord[i] = command[i];
  }

  return Kata;
}

/*  Menerima dua buah parameter yaitu string1 dan string2
    Mengembalikan true apabila string2 merupakan anagram dari string1
    Mengembalikan false apabila string2 bukan merupakan anagram dari string1
    String dianggap anagram apabila disusun dari huruf yang tepat sama */
boolean isAnagram(Word string1, Word string2){
  boolean Anagram = true;
  
  if (string1.Length !=  string2.Length)
  {
    Anagram = false;
  }
  else
  {
    int first[26] = {0}, second[26] = {0}, c = 0;

    while (string1.TabWord[c] != '\0')
    {
      first[string1.TabWord[c] - 'a']++;
      c++;
    }

    c = 0;

    while (string2.TabWord[c] != '\0')
    {
      first[string2.TabWord[c] - 'a']++;
      c++;
    }

    c = 0;

    while ((c < 26) && (Anagram = true))
    {
      if (first[c] != second[c])
        Anagram = false;
    }
  }

  return Anagram;

}

/*  Mengembalikan jumlah frekuensi kemunculan anagram alstrukdat 
    pada argumen frek */
void anagramalstrukdat(int* frek)
{
  *frek = 0;
  STARTWORD();
  while (!EndWord)
  {
    if (isAnagram(currentWord, toKata("alstrukdat")))
    {
      (*frek)++;
    }
    ADVWORD();
  }
}
