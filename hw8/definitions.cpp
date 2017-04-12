// Programmer: Anna Case                         Date: 3/19/2017
// File: definitions.cpp                         Class: CS1570
//Section: C
// Description: function definitions

#include "definitions.h"
//Pre: Called once a word has been formed
//Post: Calls stammer function if necessary, handles 'very' and '-ly'
void parse (char word[], int length)
{
  if ((length) >= 10) //Stammer
  {
    stammer(word);
  }
  if (!strcmp(word, "very")) //very
  {
    strcat(word, " very");
  }
  if ((word[length-2]=='l')&&(word[length-1]=='y'))
  {
    if (word[length]=='.')
    {
      word[length - 2] = '.';
      word[length - 1] = '\0';
      word[length] = '\0';
    }
    else
    {
      word[length - 2] = '\0';
      word[length - 1] = '\0';
    }
  }
  return;
}
//Pre: called when a word is over ten letters
//Post: inserts a random stammer in the middle of the word
void stammer (char word[])
{
  char stammers[15] = {'-','u','m','m','-','-','e','r','r','-','-','u','h','h','-'}; //charnge to chars
  int insert = rand()%(7-4 + 1) + 4;
  int stammer = rand()%(2 + 1);
  const int LENGTH = 5;
  memmove(word + insert + LENGTH,word + insert,strlen(word) - insert);
  for (int l=0;l<LENGTH;l++)
  {
    word[insert+l] = stammers[(stammer*5)+l];
  }
  return;
}
//Pre: called once a word has been formed
//Post: if a word matches one of the five swaps, there is an 80% chance it will be replaced
void wordSwap (char word[])
{
  string found[WORDS] = {"is", "isn't", "has", "she", "he"};
  string replace[WORDS] = {"are", "ain't", "have", "her", "him"};
  for (int i=0;i<=WORDS;i++)
  {
    if (!strcmp(word, found[i].c_str()) && ((rand() % 100) < 80))
    {
      strcpy(word, replace[i].c_str());
    }
  }
  return;
}

//Pre: Called when the first period is identified
//Post: Deletes period, space, and decapitalizes
void runOn (char sentence[])
{
  static int call = 0;
  if (call == 0)
  {
    sentence[strlen(sentence)-1] = '\0';
    call++;
  }
  else
  {
    sentence[1]= tolower(sentence[1]);
  }
  return;
}

//Pre: Called once the second sentence has been built
//Post: Swaps the sentence around the first comma
void swap (char sentence[])
{
  static int call = 0;
  char* comma = strchr(sentence,',');
  if (call==0 && comma!=NULL)
  {
    int loc = comma - sentence;
    char firsthalf[500];
    char secondhalf[500];
    sentence[loc] = '.';
    sentence[strlen(sentence)-1] = ',';
    strncpy (firsthalf, sentence, loc + 1); //store first
    firsthalf[1]= tolower(firsthalf[1]);
    strncpy (secondhalf, sentence + loc + 2, 500 - loc);
    secondhalf[0]= toupper(secondhalf[0]);
    sentence[0] = ' ';
    strcpy (sentence + 1, secondhalf); //second to first
    strcat(sentence, firsthalf); //first to second
	call++;
  }
  return;
}

