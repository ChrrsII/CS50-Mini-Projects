#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
int calc(string words);
int point[26]={1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};

int main(){
    //input
string word1=get_string("player1: \n");
string word2=get_string("player2: \n");
//calculate scores
int score1=calc(word1);
int score2=calc(word2);
//win cons
if (score1>score2){
    printf("player1 wins!");
}
else if (score2>score1){
    printf("player2 wins!");
}
else{
    printf("Tie");
}

}
int calc(string words){
    //initialization
    int score=0;
    for (int i=0, len=strlen(words); i<len ;i++){
        //incase upper
        if (isupper(words[i])){
            score+=point[words[i]-'A'];
        }
        if (islower(words[i])){
            score+=point[words[i]-'a'];
        }

    }
    return score;

}
