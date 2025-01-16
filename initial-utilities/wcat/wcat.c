#include <stdio.h>
#include <stdlib.h>
int main(int argc, char** argv){
    if(argc<2){
        exit(0);
    }
    for(int i=1;i<argc;i++){
    FILE *file = fopen(argv[i],"r"); 
    if(file==NULL){
    printf("wcat: cannot open file\n");
	    return(1);


    }
    char *buf;
    buf = (char*) malloc(100);
    while((fgets(buf,sizeof(buf),file))!=NULL){
        printf("%s",buf);
    } 
    fclose(file);}

    return 0;
}
