#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>

struct cliente{
	char nome[20];
	char email[100];
	char sobrenome[20];
	int idade,cel;
	int cpf;
};
struct agendamento{
	int mes;
	int dia,hora;
	int cpf;
	struct cliente clienteagenda;
};

#include "cadastro.h"
#include "agendar.h"
#include "Verificar.h"


int menu()
           {
           int op;
	       setlocale(LC_ALL,"Portuguese");
           printf("\t\t==============================================\n\n");
           printf("\t\t|                  BARBEARIA                   |\n\n");
           printf("\t\t|                    RETRO                     |\n\n");
           printf("\t\t==============================================\n\n");
	       printf("\t1-Cadastrar Cliente\n");
	       printf("\t2-Agendar corte e barba\n"); 
	       printf("\t3-Mostrar agendamento\n" );
	       printf("\t0-Sair.\n\n");
	       printf("Informe a opção desejada: ");
	       scanf("%d", &op);
	       return op;
           }

int main(){
	int op;
	do{
		op = menu();
		switch(op){
	        case 1:
	        system("cls");
			cadastro();
	           break;
			case 2:
			system("cls");
	        agendar();
	           	break;
	         case 3:
	            system("cls");
	           verificar();
	           		break;

			case 0:
	           	break;
			default:
	        printf("Opção Inválida");
	            break;
	        }
	}while(op!=0);
          system ("pause");
	      return 0;
}
