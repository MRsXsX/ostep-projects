#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc,char ** argv){


if (argc==1){
printf("wgrep: searchterm [file ...]\n");
return 1;
}


}
char* line = NULL;
size_t len =0;
ssize_t nread;
FILE * f;
if(argc==2){
f=stdin;
}
else{
	f = fopen(argv[2],"r");
}
	if(f==NULL){
printf("wgrep: cannot open file\n");
return 1;
}
//printf("%d",strlen(argv[1]));
while((nread=getline(&line,&len,f))!=-1){
	size_t i=0;
	for(int j=0;j<nread;j++){
		if(i==strlen(argv[1])){
			printf("%s",line);
			i=0;
			break;
			}
		else if(argv[1][i]==line[j]){
		//	printf("%d\n",j);
			i++;
		}
		else {
			i=0;
		}

	}
}
fclose(f);
free(line);
return 0;

}
