#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>

struct cliente buscarCliente(int cpf){
	FILE *arquivo;
	arquivo = fopen("cadastro.txt" , "r+");
	struct cliente clienteTemp;
	while(cpf != clienteTemp.cpf){
		fread(&clienteTemp,sizeof(struct cliente),1,arquivo);
		if(feof(arquivo)){// o cpf n√£o existe no arquivo
			break;
		}
	}
	fclose(arquivo);
	return clienteTemp;
}

void inserirNoArquivoAgendamento(struct agendamento insere){
	FILE *arquivo;
	arquivo = fopen("agendamento.txt","a+"); // r|w|a;
	int tamanhoDoRegistro = sizeof(struct agendamento); // retorna o tamanho em bystes de um tipo de dado
	fwrite(&insere,tamanhoDoRegistro,1,arquivo);
	fclose(arquivo);
}

int agendar(){
	setlocale(LC_ALL,"Portuguese");
	struct agendamento agendando;
	int cpf;
	// aqui tem que inseriri o cpf do cliente pra ser agendado
	printf("Informe o CPF do cliente:  ");
	scanf("%d", &cpf);
	agendando.clienteagenda =  buscarCliente(cpf);
	printf("\t\t==============================================\n\n");
    printf("\t\t|             BANCO DE HORAS                   |\n\n");
    printf("\t\t|                                              |\n\n");
    printf("\t\t==============================================\n\n");
	printf("MÍss: ");
    scanf("%d", &agendando.mes);
    printf("Dia: ");
    scanf("%d", &agendando.dia);
    printf("Hora:");
    scanf("%d", &agendando.hora);
    inserirNoArquivoAgendamento(agendando);
	system("pause");
	system("cls");
	return ;
}
