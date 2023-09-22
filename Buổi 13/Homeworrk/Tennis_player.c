#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 1000
#include"BinTree_Ex1.h"
enum {SUCCESS, FAIL};

typedef struct play
{
    char plai[40];
}player;


int main(int argc, char *argv[]){
    treeType root;
    int reval = SUCCESS;
    player *player_list = (player *)malloc(16*sizeof(player));
    if(argc != 3){
        printf("Wrong number of arguments!\n");
        printf("CORRECT SYNTAX: Tennis_player <file to read> <file to write>");
        reval = FAIL;
        return reval;
    }
    FILE *fileread,*filewrite;
    if((fileread = fopen(argv[1],"r")) == NULL){
        printf("Cannot open file.\n");
        reval = FAIL;
        return reval;
    }
    if((filewrite = fopen(argv[2],"w")) == NULL){
        printf("Cannot open file.\n");
        reval = FAIL;
        return reval;
    }
    treeType first_round[16];
    int j = 0;
    if (fseek(fileread,0,SEEK_SET) != 0)
    {
        printf("Fseek failed!\n");
        reval = FAIL;
        return reval;
    }
    while (fgets(player_list[j].plai,MAX,fileread) != NULL)
    {
        first_round[j] = makeNewNode(player_list[j].plai);
        //printf("%s\n",player_list[j].plai);
        //printf("%s",first_round[j]->element);
        j++;
    }
    j = 0;
    int random;
    treeType second_round[8];
    for(int i = 0; i<8; i++){
        random = rand();
        if (random % 2 == 0)
            second_round[i] = createFrom2(first_round[2*i]->element,first_round[2*i],first_round[2*i+1]);
        if (random % 2 == 1)
            second_round[i] = createFrom2(first_round[2*i + 1]->element,first_round[2*i],first_round[2*i+1]);
        //printf("%s",second_round[i]->element);
    }
    treeType third_round[4];
    for(int i = 0; i<4; i++){
        random = rand();
        if (random % 2 == 0)
            third_round[i] = createFrom2(second_round[2*i]->element,second_round[2*i],second_round[2*i+1]);
        if (random % 2 == 1)
            third_round[i] = createFrom2(second_round[2*i+1]->element,second_round[2*i],second_round[2*i+1]);
    }
    treeType fourth_round[2];
    for(int i = 0; i<4; i++){
        random = rand();
        if (random % 2 == 0)
            fourth_round[i] = createFrom2(third_round[2*i]->element,third_round[2*i],third_round[2*i+1]);
        if (random % 2 == 1)
            fourth_round[i] = createFrom2(third_round[2*i+1]->element,third_round[2*i],third_round[2*i+1]);
    }
    treeType winner;
    random = rand();
    if (random % 2 == 0)
        winner = createFrom2(fourth_round[0]->element,fourth_round[0],fourth_round[1]);
    if (random % 2 == 1)
        winner = createFrom2(fourth_round[1]->element,fourth_round[0],fourth_round[1]);
    root = winner;
    drawTree(root);
    f_drawTree(filewrite,root);
    free_tree(root);
    free(player_list);
    fclose(fileread);
    fclose(filewrite);
    return reval;
}