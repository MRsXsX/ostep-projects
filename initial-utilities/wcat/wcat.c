#include <stdio.h>
#include <stdlib.h>
int main(int argc, char** argv){
    if(argc!=2){
        printf("2 args pls\n");
        exit(1);
    }
    printf("%s",argv[1]);
    FILE *file = fopen(argv[1],"r"); 
    char *buf;
    while((fgets(buf,100,file))!=NULL){
        printf("%s",buf);
    } 
    fclose(file);
    return 0;
}