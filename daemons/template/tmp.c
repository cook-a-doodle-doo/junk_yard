#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc,char *argv[]){
	pid_t pid, sid;
	FILE *log;

	pid = fork();
	if(pid<  0){
		exit(EXIT_FAILURE);
	}
	if (pid >0){
		exit(EXIT_SUCCESS);
	}

	umask(0);//change the filemode mask

	if((log = fopen("tmp.log","w"))==NULL){
		printf("can't open logfile\n");
		exit(EXIT_FAILURE);
	}
	fprintf(log,argv[0]);
	fprintf(log,"\nend:change the filemode mask\n");
	
	sid = setsid();
	if(sid< 0){
		fprintf(log,"fatal:can't get new SID\n");
		exit(EXIT_FAILURE);
	}

	if((chdir("/"))< 0){
		fprintf(log,"fatal:can't change current directory\n");
		exit(EXIT_FAILURE);
	}
	
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);

	fprintf(log,"daemon was started\n");

//	for(;;){
//		sleep(30);
//	}


	fprintf(log,"daemon was ended\n");
	fclose(log);
	return 0;
}




