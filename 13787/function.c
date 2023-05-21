#include<stdio.h>
#include "function.h"
#define MAX(x,y) x>y?x:y
// TODO: upgrade and recover the Pokémon
void fight(Pokemon* fighter,Pokemon* defencer);
void level_up(Pokemon *P){
    if(P->level<5){
        P->level+=1;
        P->attack+=lvup_atk;
        P->defense+=lvup_dfn;
        P->maxHp+=lvup_maxHp;
        P->maxMp+=lvup_maxMp;
    }
    P->Hp = P->maxHp;
    P->Mp = P->maxMp;
}
// TODO: simulate and print the process of the battle
void battle(Pokemon *A, Pokemon *B){
    for(int round=1;;round++){
        if(A->Hp==0 && B->Hp==0){
            printf("Draw\n\n");
            break;
        }
        else if(A->Hp!=0 && B->Hp==0){
            printf("%s is the winner! %s died in vain...\n\n",A->name,B->name);
            //printf("%d\n",A->Mp);
            break;
        }
        else if(A->Hp==0 && B->Hp!=0){
            printf("%s is the winner! %s died in vain...\n\n",B->name,A->name);
            //printf("%d\n",A->Mp);
            break;
        }
        else{
            if(round%2==1){
                fight(A,B);
            }
            else{
                fight(B,A);
            }
        }
    }
}
void fight(Pokemon* fighter,Pokemon* defencer){
    fighter->Mp+=T;
    if(fighter->Mp>fighter->maxMp)
        fighter->Mp = fighter->maxMp;

    if(fighter->Mp>=fighter->costMp){
        fighter->Mp -= fighter->costMp;
        defencer->Hp -= 2*(fighter->level)*(MAX(fighter->attack-defencer->defense,0))/100;
        if(defencer->Hp<=0)
            defencer->Hp=0;
        printf("%s used Headbutt!\n%s now has %d HP.\n",fighter->name,defencer->name,defencer->Hp);
    }
    else{
        fighter->Mp+=T;
        if(fighter->Mp>fighter->maxMp)
            fighter->Mp = fighter->maxMp;
        printf("%s used Rest!\n%s now has %d MP.\n",fighter->name,fighter->name,fighter->Mp);
    }
}