#include <stdio.h>
#include <stdlib.h>

int main(int argc,char** argv){
int c=EOF;
int p=-1;
int i=0;
if(argc==1){
	printf("wzip: file1 [file2 ...]\n");
	return 1;
}





for(int j=1;j<argc;j++){
FILE * f = fopen(argv[j],"r");
if(f==NULL){
return 1;
}

while((c=getc(f))!=EOF){
	if(p==c){
		i++;
	}


	if(p!=c){
			if(p!=-1){
			fwrite(&i,sizeof(i),1,stdout);
			printf("%c",p);
			}
		p=c;
		i=1;
		
	}

}
fclose(f);
}
fwrite(&i,sizeof(i),1,stdout);
printf("%c",p);
return 0;
}
