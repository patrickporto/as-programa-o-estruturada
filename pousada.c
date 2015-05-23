#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

#define NUM_CLIENTES 2

struct Cliente {
	char nome[80];
	int diasHospedado;
	char endereco[255];
	float valorConta;
};


float calcConta (int diasHospedado) {
     float valor = 0;
     valor = 100 * diasHospedado;
     if (diasHospedado < 10) {
        valor += 15;
     } else {
        valor += 8;
     }
     return valor;
}


void carga (struct Cliente * clientes) {
     int i, diasHospedado;
     
     for (i = 0;i < NUM_CLIENTES; ++i) {
         printf("Digite o nome do cliente: ");
         gets(&clientes[i].nome);
         printf("Digite o endereço do cliente: ");
         gets(&clientes[i].endereco);
         printf("Digite o número de dias de hospedagem:");
         scanf("%i", &diasHospedado);
         getc(stdin);
         clientes[i].diasHospedado = diasHospedado;
         clientes[i].valorConta = calcConta(diasHospedado);
     }
}

void gravarDados (struct Cliente clientes[]) {
     FILE *file;
     file = fopen("dados", "wb");
     if (file == NULL) {
        printf("Problemas na gravação dos dados");
        return;
     }
     fseek(file, 0, SEEK_SET);
     fwrite(&clientes[0], sizeof(struct Cliente), NUM_CLIENTES, file);
     fclose(file);
}

void carregarDados () {
     int i, count;
     struct Cliente clientes[NUM_CLIENTES];
     FILE *file;
     file = fopen("dados", "rb");
     if (file == NULL) {
        printf("Problemas na leitura dos dados");
        return;
     }
     count = fread(&clientes[0], sizeof(struct Cliente), NUM_CLIENTES, file);
     for (i = 0; i < count; ++i) {
         printf("Nome: %s\n", clientes[i].nome);
         printf("Endereço: %s\n", clientes[i].endereco);
         printf("Dias de hospedagem: %i\n", clientes[i].diasHospedado);
         printf("Valor da conta: %f\n", clientes[i].valorConta);
     }
     fclose(file);
}

float calcGanho (struct Cliente clientes[]) {
     int i;
     float total = 0;
     
     for (i = 0;i < NUM_CLIENTES; ++i) {
         total += clientes[i].valorConta;
     }
     return total;
}


int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "Portuguese");
    struct Cliente clientes[10];
    carga(clientes);
    printf("Total de ganhos: R$ %.2f\n", calcGanho(clientes));
    gravarDados(clientes);
    carregarDados();
    system("PAUSE");	
    return 0;
}
