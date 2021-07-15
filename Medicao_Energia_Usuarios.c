#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct nascimento{
    int dia;
    int mes;
    int ano;
};

struct titular {
    char nome[50], sobrenome[50];
    unsigned long contrato, cep, cpf, telefone;
    struct nascimento DataNasc;
    unsigned int numeroCasa, programaBRC;
    char logradouro[20], complemento[50];
    float consumoEnergia;
};


//Calculando o valor do consumo: tipo Baixa Renda
float calcConsumoBR(float consumoBR){
    float baixaRenda = 0;
    if(consumoBR <= 30){
        baixaRenda = 0.20946 * (consumoBR - 0);
    } else if(consumoBR <= 100){
        baixaRenda = (consumoBR - 30) * 0.35908 + 30 * 0.20946;
    } else if(consumoBR <= 220){
        baixaRenda = (consumoBR - 100) * 0.53861 + 70 * 0.35908 + 30 * 0.20946;
    } else if(consumoBR > 220){
        baixaRenda = (consumoBR - 220) * 0.59846 + 100 * 0.53861 + 70 * 0.35908 + 30 * 0.20946;
    }
    return baixaRenda;
}

//Calculando o valor do consumo: tipo Convencional
float calcConsumoCR(float consumoCR){
    float convencional = consumoCR * 0.62861;
    return convencional;
}


int main() {
    int pessoas, cont; //pessoas = quantidade de usuários inseridos; cont = variável contadora para os loops.
    
    while(pessoas <= 0){
        printf("\nSeja bem-vindo(a)!\nInsira o número de pessoas que se deseja registrar: ");
        scanf("%d", &pessoas);
        if (pessoas <= 0) {
            printf("\n***Quantidade inválida! Tente novamente...***\n");
        }
    }
    
    struct titular Titular[pessoas];
    
    printf("\nIniciando a coleta de dados dos usuários...\n");
    printf("\n------------------------------------------------------\n");
    
    for (cont = 0; cont < pessoas; cont++){
        printf("\nNome e sobrenome: ");
        scanf("%s %s", Titular[cont].nome, Titular[cont].sobrenome);
        printf("Número do contrato: ");
        scanf("%ld", &Titular[cont].contrato);
        printf("Data de nascimento (dd mm aaaa): ");
        scanf("%d %d %d", &Titular[cont].DataNasc.dia, &Titular[cont].DataNasc.mes, &Titular[cont].DataNasc.ano);
        printf("CPF: ");
        scanf("%ld", &Titular[cont].cpf);
        printf("Telefone para contato: ");
        scanf("%ld", &Titular[cont].telefone);
        printf("CEP residencial: ");
        scanf("%ld", &Titular[cont].cep);
        printf("Número: ");
        scanf("%d", &Titular[cont].numeroCasa);
        printf("Logradouro: ");
        scanf("%s", Titular[cont].logradouro);
        printf("Complemento: ");
        scanf("%s", Titular[cont].complemento);
        printf("Qual o consumo de energia em kWh? ");
        scanf("%f", &Titular[cont].consumoEnergia);
        printf("De qual programa participa (1 - Baixa renda / 2 - Convencional)? ");
        scanf("%d", &Titular[cont].programaBRC);
        printf("\n\n------------------------------------------------------\n");
    }
    
    printf("\n//////////////////////////////////////////////////////////////////////////////////////////////////////////////\n\n\n");

    
    for (cont = 0; cont < pessoas; cont++){
        printf("\nNº CONTRATO: %ld \n\nNome: %s %s | CPF: %ld \nNascimento: %d / %d / %d | Telefone: %ld \nCEP: %ld | Número: %d | Logradouro: %s | Complemento: %s \nConsumo (kWh): %.1f | Programa participante (1 - Baixa renda / 2 - Convencional): %d ", Titular[cont].contrato, Titular[cont].nome, Titular[cont].sobrenome, Titular[cont].cpf, Titular[cont].DataNasc.dia, Titular[cont].DataNasc.mes, Titular[cont].DataNasc.ano, Titular[cont].telefone, Titular[cont].cep, Titular[cont].numeroCasa, Titular[cont].logradouro, Titular[cont].complemento, Titular[cont].consumoEnergia, Titular[cont].programaBRC); //Usar aqui um do/while para a seleção dos usuários.
        if(Titular[cont].programaBRC == 1){
            printf("\nTotal a pagar: $ %.2f", calcConsumoBR(Titular[cont].consumoEnergia));
        } else if(Titular[cont].programaBRC == 2){
            printf("\nTotal a pagar: $ %.2f", calcConsumoCR(Titular[cont].consumoEnergia));
        } else {
            printf("\n*****Entrada inválida!*****");
        }
        printf("\n\n------------------------------------------------------\n");
    }

    return 0;
}