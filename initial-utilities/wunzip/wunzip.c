#include <stdio.h>
#include <stdlib.h>

int main(int argc,char** argv){
	int buf;
	char c;
	if(argc==1){
		printf("wunzip: file1 [file2 ...]\n");	
		return 1;
	}


	for(int j=1;j<argc;j++){
		FILE* f = fopen(argv[j],"rb");
		if(f==NULL){
			return 1;
		}
		int br;
		while(1){
			br=fread(&buf,sizeof(int),1,f);
			if(br<=0){
				break;
			}
			br=fread(&c,1,1,f);
			for(int i=0;i<buf;i++){
				printf("%c",c);
			}
		}
		fclose(f);
	}
}
