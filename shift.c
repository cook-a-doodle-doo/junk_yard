#include <stdio.h>
#include <stdlib.h>

int main(int argc,char **argv){
	int e;
	char s;
	FILE *fp;
	
	if(argc != 2){
		fprintf(stderr,"1 filename please");
		return EXIT_FAILURE;
	}
	if ((fp = fopen(argv[1],"r")) == NULL){
		printf("this file can't open");
		return EXIT_FAILURE;
	}

	for(;;){
		puts("How many shift? (0:end)");
		scanf("%d",&e);
		if(e == 0)break;
		for(;(s = fgetc(fp)) != EOF;){
			//if (s == ' '){printf(" ");continue;}
			if(s >= 'A' && s <= 'Z'){
				s += e - 'A';
				s %= 26;
				s += 'A';
			}else if(s >= 'a' && s <= 'z'){
				s += e - 'a';
				s %= 26;
				s += 'a';
			}
			fprintf(stderr,"%c",s);
		}
		puts("");
		rewind(fp);
	}
	
	fclose(fp);
	return EXIT_SUCCESS;
}
