
/*É necessario concertar alguns pontos.
2   - Faz-se necessario a criação de quatro novas funções para melhor funcionamento do código.
3   - O escopo das novas funções já foi criado, cada uma tem sua propria explicação no cabeçalho da mesma
4   - Faz-se necessario criar duas matrizes, 
4.1 - Uma matriz para os usuarios já criados, todos varchar com 70x5.
4.2 - Uma matriz para as datas de 10x2.
5   - Faz-se necessario a retenção a apresentação dos dados da consulta.
6   - Faz-se necessario a verificação dos dados recebidos no cadastro, para que
6.1 - Não se envie numeros em locais em que só podem receber letras.
6.2 - Não se envie letras em locais onde só pode receber valores.
6.3 - Não se envie dados já registrados por outro usuario.
*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#define SIZE 200
//criação de variaveis globais
char nome[SIZE] [70];
char nascimento[SIZE][10];
char email[SIZE] [50];
char cpf[SIZE][50];
int numeroSUS;
int consultaOp, nummedico, unid, op, cpfInt[SIZE];



//mensagem de erro
void Erro(){
	printf("\n________________________________________________________________\n");
	printf("\n__________________________ SUS UniRuy __________________________\n");  
	printf("\n___________________________ !!!Erro!!! _________________________\n");
	printf("\n__                                                            __\n");
	printf("\n__           Valor digitado não confere com as opções         __\n");
	printf("\n__                                                            __\n");
	printf("\n__               Favor digitar um valor coerente	     		__\n");
	printf("\n________________________________________________________________\n");
	printf("\n_______________________ UniRuy Consultas _______________________\n");
	printf("\n________________________________________________________________\n");
}

void Cadastro(){

	static int linha;
	int opCadastro;
	do{//obtenção dos dados do cliente
		fflush(stdin);
		printf("\nPor favor, digite seu nome completo: \n\n\n");
		gets(nome[linha]);
		system("cls");
		fflush(stdin);
		printf("\n \nDigite sua data de nascimento:\n\n\n");
		printf("\nEx.: 25 12 1984 \n\n\n");
		gets(nascimento[linha]);
		system("cls");
		fflush(stdin);
		printf("\n \nDigite seu e-mail:\n\n\n");
		printf("\nEx.: exemplo@email.com \n\n\n");
		gets(email[linha]);
		system("cls");
		fflush(stdin);
		
		printf("\n \nDigite seu CPF: \n\n\n");
		printf("\nEx.: 000.000.000-00 \n\n\n");
		gets(cpf[linha]);
		system("cls");
		printf("\n\n Digite o Seu numero SUS.\n\n\n");
		printf("\nEx.: 123456 Sem Pontos.\n");
		scanf("%d",&numeroSUS);
		cpfInt[linha] = 1;
		
	
				//clausula de saida do looping.
		printf("\n \nDigite 1 para continuar com a marcação, ou outro valor para sair\n \n");
		scanf("%d", &op);
		linha++;
		system("cls");
			//o sistema está terminando aqui, deve ser concertado.
	}while(opCadastro==1);
	
	
}
void Pesquisa() {
	char cpfPesquisa[50];
	char emailPesquisa[50];
	int i;
	int opPesquisa;
	do{
		printf("Digite 1 para pesquisar por CPF ou 2 para pesquisar por email: \n");
		scanf("%d", &opPesquisa);
		switch(opPesquisa) {
			case 1:
				printf("\nDigite o CPF: \n");
				scanf("%s", &cpfPesquisa);
				for(i=0;i<SIZE;i++) {
					if(strcmp(cpf[i], cpfPesquisa)==0) {
						printf("\nNome: %s\nData de Nascimento: %s\nEmail: %s\nCPF: %s", nome[i], nascimento[i], email[i], cpf[i]);
						break;
					}
					if(i==199){
						i+=1;
						//printf("\n%d",i);
					}
					if(strcmp(cpf[i], cpfPesquisa)!=0 && i == SIZE){
						printf("Pessoa não encontrada !");
					}
				}
				break;
			case 2: 
				printf("\nDigite o E-mail: ");
				scanf("%s", emailPesquisa);
				for(i=0; i<SIZE; i++) {
					if(strcmp(email[i], emailPesquisa)==0) {
						printf("\nNome: %s\nData de Nascimento: %s\nEmail: %s\nCPF: %s", nome[i], nascimento[i], email[i], cpf[i]);
					}
					if(i==199){
						i+=1;
						//printf("\n%d",i);
					}
					else if(strcmp(email[i], emailPesquisa)!=0 && i == SIZE){
						printf("Pessoa não encontrada !");
					}
				}
				break;
			default:
				printf("\n Opção invalida");	
				break;
		}
		printf("\n\nDigite 1 para continuar pesquisando ou outro valor para sair: ");
		scanf("%d", &opPesquisa);
		system("cls");
	}while(opPesquisa==1);	
}

// caminhos das consultas(marcações).
void ClinicoGeral(int opcao){
	//Primeira Opção de especialidade.
	printf("\n\n_________________________ ESPECIALISTAS _________________________\n\n");  
  	printf("\n\n_________________________ Clínica Geral _________________________\n\n");
	printf("\n                      1 - Dr. Huberto Castro.\n\n");
    printf("\n                      2 - Drª. Liandra Cerqueira.\n\n");
    printf("\n                      3 - Dr. Magno Florêncio.\n\n");
    printf("\n_________________________ ESPECIALISTAS _________________________\n");
    
    printf("\nEscolha o número da opção correspondente ao médico de sua preferência:\n\n");
	scanf("%d", &nummedico);
	system("cls");
	printf("\n\n1 - Unidade de Saúde da Familia Brotas\n");
	printf("\n\n2 - Unidade de Saúde da Familia Ribeira\n");
	printf("\n\n3 - Unidade de Saúde da Familia Boca do Rio\n");	
	printf("\n\nEscolha o número da opção correspondente a unidade de sua preferência:\n\n");
	scanf("%d", &unid);
	system("cls");
}
void Cardiologia(int opcao){
	//Segunda opção.
	printf("\n\n_________________________ ESPECIALISTAS __________________________\n");  
  	printf("\n\n__________________________ Cardiologia ___________________________\n");
	printf("\n__                      1 - Dr. Pedro Paulo Souza.                __\n");
    printf("\n__                      2 - Dr. Victor Almeida.                   __\n");
    printf("\n__                      3 - Dr. Robert de Jesus.                  __\n");
    printf("\n_________________________ ESPECIALISTAS ____________________________\n");
    
    printf("\nEscolha o número da opção correspondente ao médico de sua preferência:\n\n");
    scanf("%d", &nummedico);
    system("cls");
}
void Oftalmologista(int opcao){
	//Terceira opção
	printf("\n_________________________ ESPECIALISTAS __________________________\n");  
  	printf("\n__________________________ Oftamologia ___________________________\n");
  	printf("\n__                      1 - Drª. Flavia Perelberg.              __\n");
    printf("\n__                      2 - Dr. Matheus Costa.                  __\n");
    printf("\n__                      3 - Dr. Daniel da Cruz.                 __\n");
    printf("\n_________________________ ESPECIALISTAS __________________________\n");
    	
    printf("\nEscolha o número da opção correspondente ao médico de sua preferência:\n\n");
	scanf("%d", &nummedico);
	system("cls");
	switch
	
}
//seleção da unidade
void Unidades (int opcao) {
	
	printf("\n\n1 - Unidade de Saúde da Familia Brotas\n");
	printf("\n\n2 - Unidade de Saúde da Familia Ribeira\n");
	printf("\n\n3 - Unidade de Saúde da Familia Boca do Rio\n");	
	printf("\n\nEscolha o número da opção correspondente a unidade de sua preferência:\n\n");
	scanf("%d", &unid);
	system("cls");
}

//lugar onde os possiveis horarios estarão disponiveis
void Banco(){
	
}
//varificação dos dados de cadastro
void VerificaCadastro(){
	
}
//verificação dos dados de login
void VerificaLogin(){
	
}
//confirmação dos dados da consulta
void CriarConsulta(){
	printf("\n\n_________________________ ESPECIALIDADES _________________________\n\n");
    printf("\n                      1 - Clínico Geral.\n");
    printf("\n                      2 - Cardiologista.\n");
    printf("\n                      3 - Oftalmologista.\n");


	printf("\n Escolha o número da opção correspondente a especialidade desejada:\n\n");
	scanf("%d", &consultaOp);
    system("cls");
    switch (consultaOp){
    	case 01:
    		ClinicoGeral(consultaOp);
    		break;
			case 02:
				Cardiologia(consultaOp);
				break;
				case 03:
					Oftalmologista(consultaOp);
					break;
					default:
						Erro();
						break;
						  		
	}
} 
//criação de arquivode consulta
void Arquivo(){
	
}

int main(void){
setlocale(LC_ALL,"");

    //estrutura de boas vindas.
    
    do{//estrutura de repetição para cadastro, existe um parametro de armazenamento implementado no código.
		printf("\n* --------------------- SISTEMA ---------------------- *\n");
		printf("\n* -------------------- SUS UniRuy -------------------- *\n ");
		printf("\n* Seja bem-vindo(a) ao sistema de marcação de consultas! *\n ");
		printf("\n Para iniciar o atendimento escolha a opção desejada:\n \n");
		printf("\n  1 - Cadastre-se. \n");
		printf("\n  2 - Consultar Cadastros.\n");
		printf("\n  3 - Marcar Consultas\n");
		printf("\n  4 -  Saida. \n");
		scanf("%d", &op);
		system("cls");
		
		//implementação de switch para opções
			switch(op){
				case 01:
					Cadastro();
					break;
					
					case 02:
						Pesquisa();
						break;
						
						case 03:
							CriarConsulta();
							break;
							
							case 04:
								system("exit");
								break;
								
								default:
										Erro();
			}
			}while(op!= 4);
		
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
		/*if(op==4)break;//saida forçada do "do".
		
		switch(op) {
			case 1:
				cadastro();
				system("cls");
				//if já dentro de um outro método, não faz parte do boas vindas
				if (op==1){
					specialist();
					    switch(numspecialist){//condições em cadeia
							case 1:
								specialistMedicos1 ();
								unidades();//não grava o médico!!!
								break;
							case 2:
								specialistMedicos2 ();
								unidades();
								break;
							case 3:
								specialistMedicos3 ();
								unidades();
								break;
							default:
																printf("\n\n__________________________________________________________________\n\n");
								printf("\n\n*_____________________ Opção inválida!!! _____________________* \n\n ");
								printf("\n\n_________________ Por favor, Tente novamente!!! _______________\n\n ");	
    							printf("\n\n__________________________________________________________________\n\n");
							
								specialist();
								
								break;//ele volta para o MENU principal, deveria voltar para especialistas e entrar na opcao!!!
						system("cls");
				}	}
				break;
			case 2:
				pesquisa();
				break;
			case 3:
				system("exit");
				break;
			default:
				printf("\n\n__________________________________________________________________\n\n");
				printf("\n\n*_____________________ Opção inválida!!! _____________________* \n\n ");
				printf("\n\n_________________ Por favor, Tente novamente!!! _______________\n\n ");	
    			printf("\n\n__________________________________________________________________\n\n");
				getchar();
				getchar();
				break;
				}
				system("cls");
		}
	}while(op!=3);
    system("cls");
    
	/*unidades ();//chamando a função unidades para apresentar as opções	
	while(unid>8 || unid<1){//laço de repetição para forçar o usuario digitar um valor validado
	printf("\n \nOpção inválida!!! Tente novamente. \n\n");
	unidades();	
	}*/

}

