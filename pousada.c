#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

struct Cliente {
	char *nome;
	int diasHospedado;
	char *endereco;
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
     
     for (i = 0;i < 1; ++i) {
         printf("Digite o nome do cliente: ");
         scanf("%s", &clientes[i].nome);
         printf("Digite o endereço do cliente: ");
         scanf("%s", &clientes[i].endereco);
         printf("Digite o número de dias de hospedagem:");
         scanf("%i", &diasHospedado);
            
         clientes[i].diasHospedado = diasHospedado;
         clientes[i].valorConta = calcConta(diasHospedado);
     }
}


float calcGanho (struct Cliente clientes[]) {
     int i;
     float total = 0;
     
     for (i = 0;i < 1; ++i) {
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
    system("PAUSE");	
    return 0;
}
