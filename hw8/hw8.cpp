// Programmer: Anna Case                         Date: 3/19/2017
// File: hw8.cpp                                 Class: CS1570
//Section: C
// Description: main function, calls functions

#include "definitions.h"
int main()
{
  //Declarations
  char c;
  char word[MAXINWORD+1];
  char sentence[750];
  int letter = 0;
  int punct = 0;
  int length;
  int sent = 1;
  srand(time(NULL)); //seeds RNG
  //Opens Files
  ifstream in;
  ofstream out;
  in.open("speech.dat");
  out.open("output.dat");
  //Error Correction
  if (!in)
  {
    cout << "The input file could not be opened properly.";
    exit(0);
  }
  else if (!out)
  {
    cout << "The output file could not be opened properly.";
    exit(0);
  }
  //Header
  if ((rand() % 100) < 50)
  {
    out << "I mean ";
  }
  //During Text
  while(in.get(c))
  {
    if (isalpha(c)) //builds word
    {
      word[letter] = c;
      letter++;
    }
    else if (ispunct(c)) //appends punctuation to word
    {
      word[letter] = c;
      letter++;
      punct++;
      if (c=='.' || c =='?' || c=='!')//Iterates sentences
      {
        //finishes sentence
        strcat(sentence, word);
	    //Runon and Swap
	    if (sent==1)
	    {
	      runOn(sentence);
	    }
	    else if (sent==2)
	    {
	      runOn(sentence);
        }
	    else if (sent>=3)
	    {
	      swap(sentence);
	    }
	    //Output
	    out << sentence;
	    //Iterations and resets
	    sent++;
	    letter = 0;
	    punct = 0;
	    memset(&word[0], 0, sizeof(word));
        memset(&sentence[0], 0, sizeof(sentence));
      }
    }
    else if ((c==' ') || (c=='\n'))
    {
      //edits words
      length = letter - punct;
      wordSwap(word);
      parse(word,length);
      word[strlen(word)] = ' '; //appends space to word
      //append to sentence
      strcat(sentence, word);
      if (c=='\n')
      {
        sentence[strlen(sentence)] = '\n';
      }
      //resets
      letter = 0;
      punct = 0;
      memset(&word[0], 0, sizeof(word));
    }
  }
  //End
  if ((in.eof()) && ((rand() % 100) < 70))
  {
    out << " n'stuff";
  }
  //Closes files and ends
  in.close();
  out.close();
  return 0;
}
