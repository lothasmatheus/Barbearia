#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>

void inserirNoArquivoCliente(struct cliente insere){
	FILE *arquivo;
	arquivo = fopen("cadastro.txt","a+"); // r|w|a;
	int tamanhoDoRegistro = sizeof(struct cliente); // retorna o tamanho em bystes de um tipo de dado
	fwrite(&insere,tamanhoDoRegistro,1,arquivo);
	fclose(arquivo);
}

int cadastro(){
	setlocale(LC_ALL,"Portuguese");
	struct cliente cadastros;
	printf("\t\t==============================================\n\n");
    printf("\t\t|             CADASTRO DE CLIENTES             |\n\n");
    printf("\t\t|                                              |\n\n");
    printf("\t\t==============================================\n\n");
    fflush(stdin);
	printf("Nome: \n");
	scanf("%s",cadastros.nome);
	fflush(stdin);
	printf("Sobrenome: \n");
	scanf("%s",cadastros.sobrenome); //utilizo o gets pois ele só vai passar para o próxino tópico quando o usuário der enter
	printf("Idade: \n");
	scanf("%d", &cadastros.idade);
	fflush(stdin);
	printf("CPF(Somente n�meros): \n");
	scanf("%d", &cadastros.cpf);
	fflush(stdin);
	printf("Cel: \n");
	scanf("%d", &cadastros.cel);
	fflush(stdin);
	printf("E-mail: \n");
	scanf("%s",cadastros.email);
	system("pause");
	inserirNoArquivoCliente(cadastros);
	system("cls");   //cls utilizo para limpar a tela
	return ;
}
