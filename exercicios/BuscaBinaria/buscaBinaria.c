#include <stdio.h>
#include <string.h>

typedef struct _Endereco Endereco;

struct _Endereco {
	char logradouro[72];
	char bairro[72];
	char cidade[72];
	char uf[72];
	char sigla[2];
	char cep[8];
	char lixo[2];
};

int main(int argc, char** argv)
{
	if(argc != 2)
	{
		fprintf(stderr,"Erro ao utilizar %s\n", argv[0]);
		fprintf(stderr,"USO: %s [CEP PARA BUSCA]\n",argv[0]);
		return 1;
	}
	
	FILE *f;
	Endereco e;
	int total, cmp, tamarq, tamreg, inicio, meio, fim;

	f = fopen("cep_ordenado.dat","r");
	
	fseek(f,0,SEEK_END);

	tamarq = ftell(f);
	tamreg = sizeof(Endereco);

	inicio = 0;
	fim = (tamarq/tamreg) - 1;
	total = 0;
	

	printf("CEP não encontrado! =(\n");
	fclose(f);
	return 1;	
}