#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct CARD{
    char suit[10];
    char face[10];
}card[52];

void swap(struct CARD *a, struct CARD *b){
    struct CARD t = *a;
    *a = *b, *b = t;
}

void init(){
    char *suit[] = {"Spades", "Hearts", "Diamonds", "Clubs"};
    char *face[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    for(int i=0; i<52; i++){
        strcpy(card[i].suit, suit[i/13]);
        strcpy(card[i].face, face[i%13]);
    }
}

void shuffle(){
    srand(time(NULL));
    for(int i=0; i<52; i++){
        int j = rand() % 52;
        swap(&card[i], &card[j]);
    }
}

void deal(){
    for(int i=0; i<52; i++){
        printf("%10s%10s\n", card[i].face, card[i].suit);
    }
}

int main(){
    init();
    shuffle();
    deal();
    return 0;
}