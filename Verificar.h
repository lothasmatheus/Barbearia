#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

void exibirHorarios(int dia,int mes){
	FILE * arquivo;
	arquivo = fopen("agendamento.txt", "r");
	struct agendamento agendaTemporario;
	while(1){
		fread(&agendaTemporario,sizeof(struct agendamento),1,arquivo);
		if(feof(arquivo)){
			break;
		}
		if(agendaTemporario.dia == dia && mes == agendaTemporario.mes ){
			printf("\n");
			printf("Hora: %d", agendaTemporario.hora);
			printf("Nome %s",agendaTemporario.clienteagenda.nome);
			printf("Sobrenome %s", agendaTemporario.clienteagenda.sobrenome);
			printf("E-mail: %s",agendaTemporario.clienteagenda.email);
			printf("\n");
		}


	}
	system("pause");
	system("cls");
	fclose(arquivo);
	return;
}

int verificar(){
	setlocale(LC_ALL,"Portuguese");
	int dia,mes;
	printf("Informe o dia do agendamento: ");
	scanf("%d", &dia);
	printf("Informe o mês do agendamento: ");
	scanf("%d", &mes);
	exibirHorarios(dia,mes);
return;
}
