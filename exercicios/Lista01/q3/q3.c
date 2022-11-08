#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Registro Registro;

struct _Registro 
{
    char cpf[15];
};



int compara(const void *e1, const void *e2)
{
	return strncmp(((Registro*)e1)->cpf,((Registro*)e2)->cpf,15);
}

int main(int argc, char** argv)
{
	FILE *a, *b, *saida;
	Registro ea, eb;

    //Para buscaBinaria
    int meio, tamReg, tamArq, cmp;


	a = fopen("cpf_a.dat","rb");
	b = fopen("cpf_b.dat","rb");
	saida = fopen("saida.dat","wb");

    fseek(b,0,SEEK_END);
    tamArq = ftell(b);
    tamReg = sizeof(Registro);

    /*
	O arquivo "a" são os valores de referência para a busca
    O arquivo "b" é onde será feito a busca Binária
	*/
    

	while(!feof(a) && !feof(b))
	{
		int inicio =0, fim, loop =0;
		fim = (tamArq/tamReg); 
		/*
		- De acordo com o algoritmo do renato
		fim = (tamArq/tamReg) -1;
		Porém, só funciona se a ultima linha do arquivo de busca for desconsiderada,
		não lembro o por quê do "-1", eu não havia percebido antes, visto a quantidade de informações do arquivo do cep.dat
		*/

        fread(&ea,tamReg,1,a);

        //buscaBinaria
		while(inicio<=fim){
            
			meio = (inicio+fim)/2;

			fseek(b, meio*tamReg, SEEK_SET);
			fread(&eb,tamReg,1,b);  

			cmp = compara(&ea,&eb);

			printf("\n eA = %s",ea.cpf);
			printf("\n eB = %s",eb.cpf);
			
			printf("\n Inicio = %i \t meio = %i \t Fim = %i", inicio,meio, fim);

			printf("\n Cmp = %i \t loop = %i", cmp, loop);
			printf("\n ------------------------------------");
			
			if(cmp == 0){
				fwrite(&ea, tamReg ,1,saida);
				break;
			}
			else if(cmp>0)
				inicio = meio+1;
			else 
				fim = meio-1;		
			loop++;
		}		
	}

	fclose(a);
	fclose(b);
	fclose(saida);
}

