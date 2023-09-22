#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#define MAX 10000
#define LINE 54373
enum {SUCCESS, FAIL};

typedef struct vnedict
{
    char vne[30];
    char eng[50];
}dict;

int main(){
    FILE *file1,*file2;
    int reval = SUCCESS;
    dict *a;
    int i = 0;
    char c[MAX];
    if((file1 = fopen("vnedict.txt","r+")) == NULL){
        printf("Cannot open file1.\n");
        reval = FAIL;
        return reval;
    }
    if((file2 = fopen("vnedict2.dat","w+b")) == NULL){
        printf("Cannot open file2.\n");
        reval = FAIL;
        return reval;
    }
    a = (dict*)malloc(LINE*sizeof(dict));
    while (fgets(c,MAX,file1) != NULL)
    {   
        char *index;
        index = strrchr(c,':');
        int ind = (index-c);
        //printf("%d\n",ind);
        for(int j =0; j<=(ind-2); j++){
            a[i].vne[j] = c[j];
            a[i].vne[j+1] = '\0';
        }
        
        //printf("%s\n",a[i].vne);
        for(int j = (ind+2),k = 0; j <= (strlen(c)- 2), k <= (strlen(c) - ind -3); j++, k++){
            a[i].eng[k] = c[j];
            a[i].eng[k+1] = '\0';
        }
        //printf("%s\n",a[i].eng);
        i++;
    }
    fwrite(a,sizeof(dict),54373,file2);
    fclose(file1);
    fclose(file2);
    free(a);
    if((file2 = fopen("vnedict2.dat","r+b")) == NULL){
        printf("Cannot open file.\n");
        reval = FAIL;
        return reval;
    }
    dict *read;
    int irc;
    int begin, end;
    printf("Begin: ");
    scanf("%d",&begin);
    printf("End: ");
    scanf("%d",&end);
    read =(dict *)malloc((end - begin +1) * sizeof(dict));
    if (read == NULL){
        printf("Memory allocation failed!\n");
        return FAIL;
    }
    if (fseek(file2,(begin-1)*sizeof(dict),SEEK_SET) != 0)
    {
        printf("Fseek failed!\n");
        reval = FAIL;
        return reval;
    }
    irc = fread(read, sizeof(dict), (end - begin + 1), file2);
    for(int i = 0; i < (end-begin+1); i++){
        printf("%s trong tiếng Anh là: %s",read[i].vne,read[i].eng);
    }
    free(read);
    fclose(file2);
    return SUCCESS;
}
