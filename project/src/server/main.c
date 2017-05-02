#include "../lib.c"
#include "menus_sv.c"
#include "methods_sv.c"
#include "users_sv.c"
#include "stocks_sv.c"
#include "actions_sv.c"
#include "login_sv.c"

int main(int argc, char **argv);
void mainActions();

int main(int argc, char **argv){
	if(argc == 3){
		if(strcmp(argv[1], "reset") == 0){
			if(strcmp(argv[2], "users") == 0){
				char fp[512];
				getUsersFilePath(fp);
				remove(fp);
				printf("Ficheiro de utilizadores removido!\n");
				exit(0);
			}
			if(strcmp(argv[2], "stocks") == 0){
				char fp[512];
				getStocksFilePath(fp);
				remove(fp);
				printf("Ficheiro de stocks removido!\n");
				exit(0);
			}
		}
	}

	startupActions();
	parseUsers();

	printf("numusers = %d\n", numUsers);
	int i = 0;
	for(i = 0; i < numUsers; i++){
		char buff[256];
		getAllQuantidade(getUserId(i), buff);
		printf("User #%d - %s\n", i, buff);
	}

	return(0);

	parseStock();
	login();
	mainActions();
	return(0);
}

void mainActions(){
	int input = 1;

	do {
		menu();
		if(scanf("%d", &input) >= 1){
			clearScreen();
			actions(input);
		}
	} while(1);
}
