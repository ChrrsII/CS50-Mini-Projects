#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{

    // Prompt the user for some text
    string input=get_string("text:");

    // Count the number of letters, words, and sentences in the text
    //1-Letters(each time there's a alphabetical inc 1)
    int i=0;
    int letters=0;
    while (i<strlen(input)){
        if (isalpha(input[i])){
             letters=letters+1;
        }
        else{
            letters=letters+0;
        }
        i++;
    }
    printf("letters=%i\n", letters);
    //words (each time there's a space increase 1)
    int w=0;
    int words=0;
    if (isalpha(input[0])){
            words=1;
        }
    while(w<strlen(input)){
        if (input[w]==' ' && isalpha(input[w+1])){
            words=words+1;
        }
        else if (input[w]=='.' && isalpha(input[w+1])){
            words=words+1;
        }
        else{
            words=words+0;
        }
        w++;
    }
    printf("words=%i\n", words);
    //sentences (each time there's a "." increase 1)
    int s=0;
    int sentences=0;
    while(s<strlen(input)){
        if (input[s]=='.' || input[s]=='!' || input[s]=='?'){
            sentences=sentences+1;
        }
        else{
            sentences=sentences+0;
        }
        s++;
    }
    printf("sentences=%i\n", sentences);
    // Compute the Coleman-Liau index
    float L=100*letters/words;
    float S=100*sentences/words;
    float index = 0.0588 * L - 0.296 * S - 15.8;

    // Print the grade level
    int final=round(index);
    if (index<0){
        printf("before grade 1\n");
    }
    else if (index>15){
        printf("grade 16+\n");

    }
    else{
        printf("grade:%i\n", final);
    }
}
