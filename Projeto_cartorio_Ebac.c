#include <stdio.h> //biblioteca de comunicção com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória, reserva o espaço das variáveis etc
#include <locale.h> //biblioteca de alocações de texto por região, identifica acentos etc
#include <string.h>//biblioteca resoponsável por cuidar das string

		//Bibliotecas sempre deve estar no ínicio, antes de qualquer coisa!!

int registro()                          //função responsavel por cadastrar os usuários no sistema
{
										//inicio criação de variáveis/string
	char arquivo[40];                               //nome dos arquivos; [] espaço reservado para os arquivos
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
										//final da criação das variáveis/string
	
	printf("Digite o CPF a ser cadastrado:\n ");
	scanf("%s", cpf);					//%s refere-se a string
	
	strcpy(arquivo,cpf);  				//Responsável por copiar os valores das strings
	
	FILE *file;    				   		//comando inicial para criar o arquivo
	file = fopen(arquivo, "w");         //cria o arquivo, tipo WRITE == ESCREVER
	fprintf(file, "\n CPF: "); 
	fprintf(file, cpf);					// salva o valor da variavel
	fclose(file);						// fecha o arquivo
	
	file = fopen(arquivo,"a");			//abre o arquivo. "a"== atualizar a informação do arquivo
	fprintf(file, "\n NOME: "); 		//salva a atualização
	fclose(file);						// fecha o arquivo
	
	printf("Digite o nome a ser cadastrado:\n ");		//pede para o usuaário a informação
	scanf("%s", nome);					//salva na string
	
	file = fopen(arquivo, "a"); 		//abre o arquivo. "a"== atualizar a informação do arquivo
	fprintf(file, nome);				//salva o valor da variável
	fclose(file);						//fecha o arquivo
	
	file = fopen(arquivo, "a");			//abre o arquivo. "a"== atualizar a informação do arquivo
	fprintf(file,"\n SOBRENOME: ");				//salva o valor da variável
	fclose(file);						//fecha o arquivo
	printf("Digite o sobrenome a ser cadastrado:\n ");				//pede para o usuaário a informação
	scanf("%s", sobrenome); 			//salva na string
	
	file = fopen(arquivo, "a"); 		  //abre o arquivo. "a"== atualizar a informação do arquivo
	fprintf(file, sobrenome); 				//salva o valor da variável
	fclose(file); 							//fecha o arquivo
			
	file = fopen(arquivo, "a");						//abre o arquivo. "a"== atualizar a informação do arquivo
	fprintf(file, "\n CARGO: "); 				//salva o valor da variável
	fclose(file);						//fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado:\n ");				//pede para o usuaário a informação
	scanf("%s", cargo);					//salva na string
	
	
	file = fopen(arquivo, "a");			//abre o arquivo. "a"== atualizar a informação do arquivo
	fprintf(file, cargo);;				//salva o valor da variável
	fclose(file);						//fecha o arquivo
	
	file = fopen(arquivo, "a");			//abre o arquivo. "a"== atualizar a informação do arquivo
	fprintf(file, "\n\n");				//salva o valor da variável
	fclose(file);						//fecha o arquivo
	
	printf("\nUsuário cadastrado com sucesso!\n\n");			//mensagem ao usuário
	system("pause");
	
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");				//definição de linguagem
	
	char cpf[40];
	char conteudo[200];
	

	
	printf ("Digite o CPF a ser consultado: ");			//pergunta ao usuario qual cpf quer consultar
	scanf ("%s", cpf);
	
	FILE *file;										//consulta o arquivo
	file = fopen(cpf,"r" );							//abre o arquivo, "r"== read == lêr
	
		
	
	if (file == NULL)								//arquivo inexistente
	{	
		printf("\nNão foi possível abrir o arquivo, arquivo não localizado!\n\n");			//mensagem ao usuário
		system("pause");
		system("cls");
	}
	
					
	while (fgets(conteudo, 200, file) != NULL)		//laço de repetição, "enquanto". Enquanto for diferente de NULL
	{	
	
		printf ("%s", conteudo);					//salva o conteúdo dentro da string
	}
	printf ("\nEssas são as informações do usuário:\n");
	fclose(file);
	system ("pause");
	system ("cls");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado:\n");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	printf("Usuário excluido com sucesso!\n\n");
	system("pause");
	system("cls");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!\n\n");
		system("pause");
		system("cls");
	}
	
	fclose(file);
}

int main()
{
	int opcao=0; 											//Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{   
	
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); 					//Definindo a linguagem
	
		printf("--- Cartório da Ebac --- \n\n"); 			//inicio do menu
		printf("Escolha a opção desejada:\n\n");
		printf("\t1 - CADASTRAR NOMES\n");
		printf("\t2 - CONSULTAR NOMES\n");
		printf("\t3 - DELETAR NOMES\n\n"); 
		printf("Opção: "); //fim do menu

		scanf("%d", &opcao); 								//armazenando a escolha do usuário
	
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
				printf("\nEssa opção não está disponível! \nEscolha entre as opções 1, 2 e 3:\n\n");
				system("pause");	
				break;
					
		}
		
}
}
