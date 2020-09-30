
#include <stdio.h>
#include<string.h>
#include <stdio.h>
#include <ctype.h>

int main()
{ 
  	char inputString[200];  //Variable for finalized input string
  	char testString[200];   //Variable for input string before adding a space to the beggining. 
  	int pos, i, j, len, startIndex, endIndex;   // Simple Variable initializations
  	char articleA[] = " a ";    //Variable for article "a"
  	char articleAn[] = " an ";  //Variable for article "an"
  	char articleThe[] = " the "; //Variable for article "the"
 
  	printf("\n Enter a string:"); //Prompt asking user to input string of choice. 
  	gets(testString); //Saving this input string into variable.
  	
  	len = strlen(testString); //Finding the length of the input string. 
  	endIndex = len - 1; //Finding the location of the last character in the input string.
  	
  	
  	inputString[0] = ' '; //Adding a space to the beggining of the new string so that I can located the articles.
  	 	for(i = len - 1; i >= 0; i--) //For loop to convert all letters to lowercase - No worries about cases.  
	        {
                 inputString[i+1] = tolower(testString[i]); //Copying the input string into the string that starts with a space. 
            } 
    len += 1; //adjusting the length for the added space at the beggining
    endIndex += 1; //adjusting the end index for the added space at the begginig.
    
  	
  if(strstr(inputString,articleA) != 0){ //Checking to see if the article is the scentence that I was given...
        pos = ((strstr(inputString,articleA)) - inputString); //Find the position of the article "a".
        inputString[pos+2] = '_'; //Replace the space following the article with a character not found in the sentence.
    }

  if(strstr(inputString,articleAn) != 0){   //if the word "an" is in the sentence...
        pos = ((strstr(inputString,articleAn)) - inputString); //Find the position of the article "a".
        inputString[pos+3] = '_'; //Replace the space following the article with a character not found in the sentence.
    }
    
  if(strstr(inputString,articleThe) != 0){  //if the word "the" is in the sentence...
        pos = ((strstr(inputString,articleThe)) - inputString); //Find the position of the article "a".
        inputString[pos+4] = '_'; //Replace the space following the article with a character not found in the sentence.
    }
    
inputString[0] = '\0'; //Remove that extra space that I originally added now that I've checked for the articles.
  	
  	
//At this point, the articles now have "_" following them rather than a space. 
//I will now do a reversal, and later go back and replace the "_" with  space to undo this. 
//This will be my technique to connect the article to the word that it's attached to. 
  	
  	
  	//This is where the string reversal occurs.
  	printf("\n *****Reversed String***** \n"); 
  	for(i = len - 1; i >= 0; i--) 
	{
		if(inputString[i] == ' ' || i == 0)
		{
			if(i == 0)
				startIndex = 0;
			else
				startIndex = i + 1;
			for(j = startIndex; j <= endIndex; j++){
			    if (inputString[j] == '_') //Replacing all the "_" back with spaces.
			            inputString[j] = ' ';
			    
			    printf("%c", inputString[j]);
			}
			
			endIndex = i - 1;
			printf(" ");				
		} 
	}
	
	
}
