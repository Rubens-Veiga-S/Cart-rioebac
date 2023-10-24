#include <stdio.h> //biblioteca de comunic��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria, reserva o espa�o das vari�veis etc
#include <locale.h> //biblioteca de aloca��es de texto por regi�o, identifica acentos etc
#include <string.h>//biblioteca resopons�vel por cuidar das string

		//Bibliotecas sempre deve estar no �nicio, antes de qualquer coisa!!

int registro()                          //fun��o responsavel por cadastrar os usu�rios no sistema
{
										//inicio cria��o de vari�veis/string
	char arquivo[40];                               //nome dos arquivos; [] espa�o reservado para os arquivos
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
										//final da cria��o das vari�veis/string
	
	printf("Digite o CPF a ser cadastrado:\n ");
	scanf("%s", cpf);					//%s refere-se a string
	
	strcpy(arquivo,cpf);  				//Respons�vel por copiar os valores das strings
	
	FILE *file;    				   		//comando inicial para criar o arquivo
	file = fopen(arquivo, "w");         //cria o arquivo, tipo WRITE == ESCREVER
	fprintf(file, "\n CPF: "); 
	fprintf(file, cpf);					// salva o valor da variavel
	fclose(file);						// fecha o arquivo
	
	file = fopen(arquivo,"a");			//abre o arquivo. "a"== atualizar a informa��o do arquivo
	fprintf(file, "\n NOME: "); 		//salva a atualiza��o
	fclose(file);						// fecha o arquivo
	
	printf("Digite o nome a ser cadastrado:\n ");		//pede para o usua�rio a informa��o
	scanf("%s", nome);					//salva na string
	
	file = fopen(arquivo, "a"); 		//abre o arquivo. "a"== atualizar a informa��o do arquivo
	fprintf(file, nome);				//salva o valor da vari�vel
	fclose(file);						//fecha o arquivo
	
	file = fopen(arquivo, "a");			//abre o arquivo. "a"== atualizar a informa��o do arquivo
	fprintf(file,"\n SOBRENOME: ");				//salva o valor da vari�vel
	fclose(file);						//fecha o arquivo
	printf("Digite o sobrenome a ser cadastrado:\n ");				//pede para o usua�rio a informa��o
	scanf("%s", sobrenome); 			//salva na string
	
	file = fopen(arquivo, "a"); 		  //abre o arquivo. "a"== atualizar a informa��o do arquivo
	fprintf(file, sobrenome); 				//salva o valor da vari�vel
	fclose(file); 							//fecha o arquivo
			
	file = fopen(arquivo, "a");						//abre o arquivo. "a"== atualizar a informa��o do arquivo
	fprintf(file, "\n CARGO: "); 				//salva o valor da vari�vel
	fclose(file);						//fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado:\n ");				//pede para o usua�rio a informa��o
	scanf("%s", cargo);					//salva na string
	
	
	file = fopen(arquivo, "a");			//abre o arquivo. "a"== atualizar a informa��o do arquivo
	fprintf(file, cargo);;				//salva o valor da vari�vel
	fclose(file);						//fecha o arquivo
	
	file = fopen(arquivo, "a");			//abre o arquivo. "a"== atualizar a informa��o do arquivo
	fprintf(file, "\n\n");				//salva o valor da vari�vel
	fclose(file);						//fecha o arquivo
	
	printf("\nUsu�rio cadastrado com sucesso!\n\n");			//mensagem ao usu�rio
	system("pause");
	
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");				//defini��o de linguagem
	
	char cpf[40];
	char conteudo[200];
	

	
	printf ("Digite o CPF a ser consultado: ");			//pergunta ao usuario qual cpf quer consultar
	scanf ("%s", cpf);
	
	FILE *file;										//consulta o arquivo
	file = fopen(cpf,"r" );							//abre o arquivo, "r"== read == l�r
	
		
	
	if (file == NULL)								//arquivo inexistente
	{	
		printf("\nN�o foi poss�vel abrir o arquivo, arquivo n�o localizado!\n\n");			//mensagem ao usu�rio
		system("pause");
		system("cls");
	}
	
					
	while (fgets(conteudo, 200, file) != NULL)		//la�o de repeti��o, "enquanto". Enquanto for diferente de NULL
	{	
	
		printf ("%s", conteudo);					//salva o conte�do dentro da string
	}
	printf ("\nEssas s�o as informa��es do usu�rio:\n");
	fclose(file);
	system ("pause");
	system ("cls");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado:\n");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	printf("Usu�rio excluido com sucesso!\n\n");
	system("pause");
	system("cls");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!\n\n");
		system("pause");
		system("cls");
	}
	
	fclose(file);
}

int main()
{
	int opcao=0; 											//Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{   
	
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); 					//Definindo a linguagem
	
		printf("--- Cart�rio da Ebac --- \n\n"); 			//inicio do menu
		printf("Escolha a op��o desejada:\n\n");
		printf("\t1 - CADASTRAR NOMES\n");
		printf("\t2 - CONSULTAR NOMES\n");
		printf("\t3 - DELETAR NOMES\n\n"); 
		printf("Op��o: "); //fim do menu

		scanf("%d", &opcao); 								//armazenando a escolha do usu�rio
	
		system("cls");
			
		switch(opcao)
		{
			case 1:
				registro();
				break;
					
			case 2:
				consulta();	
				break;
					
			case 3:
				deletar();
				break;
				
			default:
				printf("\nEssa op��o n�o est� dispon�vel! \nEscolha entre as op��es 1, 2 e 3:\n\n");
				system("pause");	
				break;
					
		}
		
}
}
