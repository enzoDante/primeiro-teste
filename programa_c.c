//projetos 2° bimestre
// Enzo Dante, Isaac de Oliveira e Rafael Paroni
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
int pacotes, tempo, envios, pacE, i, max, min, c;
float media, perda, pacP;
char site[100], p[10];
main(){
	srand(time(NULL));
	
	printf("==============SIMULADOR DE PING==============\n=====COMANDOS DISPONIVEIS: [ping] E [cls]=====\n");
	do{
		media = 0;
		perda = 0;
		pacE = 0;
		pacP = 0;
		printf("C:/Users>");
		scanf("%c", &p);
		fflush(stdin);
		while(strcmp(p, "c") == 0){
			system("cls");
			printf("C:/Users>");
			scanf("%c", &p);
			fflush(stdin);
		}
		while(strcmp(p, "p") != 0){
			printf("valor nao encontrado!! o sistema nao tem essa funcao, tente colocar ping\n essa eh a unica funcao do sistema\n");
			printf("C:/Users>");
			scanf("%c", &p);
			fflush(stdin);
		}
		
		printf("C:/Users>ping-site: ");
		scanf("%s", &site);
		fflush(stdin);
		printf("C:/Users>ping %s quantidadePacotes: ", site);
		scanf("%d", &pacotes);
		printf("\nDisparando os pacotes %s [172.217.30.163] com 32 bytes de dados:\n", site);
		for(i = 1; i <= pacotes; i++){
			envios = (rand()%10) + 1;
			if(envios%2 == 0){
				c++;
				pacE++;
				tempo = (rand()%500) + 1;
				printf("Resposta de 172.217.30.163: bytes=32 tempo=%dms\n", tempo);
				media = tempo + media;
				if(c == 1){
					max = tempo;
					min = tempo;
				}
				else{
					if(tempo < min){
						min = tempo;
					}
					else{
						if(tempo > max){
							max = tempo;
						}
					}
				}			
			}
			else{
				pacP++;
				printf("Resposta de 172.217.30.163: bytes=32 perdido\n");
			}	
		}
		perda = (pacP/pacotes) * 100;
		media = media/pacotes;
		printf("\nestatistica do ping para 172.217.30.163\n");
		printf("pacotes: Enviados = %d, Recebidos = %d, Perdidos = %.0f (%.1f%% de perda)\n", pacotes, pacE, pacP, perda);
		printf("Aproximar um numero redondo de vezes em milissegundos:\n");
		printf("minimo = %dms, Maximo = %dms, Media = %.2f\n\n", min, max, media);
		fflush(stdin);	
	}while(true);
	
	
	
	
}
