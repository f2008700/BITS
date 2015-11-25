/* File name: StringOps.h */

#include "String.h"

/* Pre cond: memory allocation for text 
 *       Post cond: input text is stored in text  */
extern void createString(String text);

  /* Pre cond: text should not be empty 
          Post cond: input text is printed */
extern void printString(String text);

/* Pre cond: Text should have atleast one word 
 *      Post cond: returns index position of word, if present, else returns -1  */
extern Position findWord(String text, String word);

 /* Pre cond: There should be enough room for insertion;
 *      0=pos <length(text)     
 *          Post cond: returns length of Text after insertion*/
extern Size insertWord(String text, Position index, String newWd);

 /* Pre cond: text and word should not be empty 
    Post cond text after removing all occurances of word */
extern Size deleteWord(String text, String word);


