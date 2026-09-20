#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

// =========================================================================
// PROTÓTIPOS DAS FUNÇÕES AUXILIARES DE TRATAMENTO DE ERROS
// =========================================================================
int ler_inteiro_seguro();
double ler_real_seguro();
void ler_string(char *buffer, int tamanho);

int main() {
    // Variáveis usadas para controlar as escolhas dos menus.
    char opcao[10];
    char alternativa[10], decisao[10];
    
    // Laço principal: mantém o sistema funcionando até o usuário escolher sair.
    do {
        printf("\n==============================\n");
        printf("\nSuite de Calculadoras Tecnicas\n");
        printf("\n==============================\n");
        printf("\nSeja bem-vindo(a)! Verifique as alternativas \n");
        printf("\n(1) Para Modulo de associacoes");
        printf("\n(2) Para calculo de retificadores");
        printf("\n(3) Para modulo de temporizacao");
        printf("\n(4) Para modulo digital");
        printf("\n(5) Para modulo de Corrente Alternada");
        printf("\n(6) Para modulo de bases");
        printf("\nEscolha uma opcao (de 1 a 6)");
        printf("\nOBS: Digite o numero 7 para sair\n");
        printf("\nEscolha uma opcao: ");

        ler_string(opcao, 10);

        if (strcmp(opcao, "1") == 0) { printf("\nOpcao bem escolhida!\n"); }
        else if (strcmp(opcao, "2") == 0) { printf("\nOpcao bem escolhida!\n"); }
        else if (strcmp(opcao, "3") == 0) { printf("\nOpcao bem escolhda!\n"); }
        else if (strcmp(opcao, "4") == 0) { printf("\nOpcao bem escolhida!\n"); }
        else if (strcmp(opcao, "5") == 0) { printf("\nOpcao bem escolhida!\n"); }
        else if (strcmp(opcao, "6") == 0) { printf("\nOpcao bem escolhida!\n"); }
        else if (strcmp(opcao, "7") == 0) { printf("\nVoce desejou sair.\n"); }
        else { printf("\nOpcao errada ou inexistente! Tente novamente.\n"); }

        // Direciona o programa para o módulo escolhido pelo usuário.
        switch (atoi(opcao)) {
            case 1: {
                // Módulo responsável pelos cálculos de associações elétricas.
                int quant;
                
                printf("\n ===================== \n");
                printf("\n Modulo de associacoes \n");
                printf("\n ===================== \n");
                printf("\nVerifique a lista dos itens para realizar a associacao.\n");
                printf("\n Digite (1) para Resistencia Equivalente\n");
                printf("\n Digite (2) para Indutancia Equivalente \n");
                printf("\n Digite (3) para Capacitancia Equivalente\n");

                printf("\n Digite a opcao escolhida: ");
                ler_string(alternativa, 10);

                if (strcmp(alternativa, "1") == 0) { printf("\n Primeira opcao escolhida com sucesso!\n"); }
                else if (strcmp(alternativa, "2") == 0) { printf("\n Segunda opcao escolhida com sucesso!\n"); }
                else if (strcmp(alternativa, "3") == 0) { printf("\n Terceira opcao escolhida com sucesso!\n"); }
                else { printf("\n Opcao errada ou inexistente! Tente novamente.\n"); }

                switch (atoi(alternativa)) {
                    case 1: {
                        char associacao[10];
                        printf("\n Insira a quantidade de resistores: ");
                        quant = ler_inteiro_seguro();

                        double resistores[quant];
                        double reqS = 0.0;
                        double reqP = 0.0;
                        double reqPtotal = 0.0;

                        printf("\n Defina se a associacao sera realizada em serie ou em paralelo: \n");
                        printf("\n Digite 'S' para serie ou 'P' para paralelo: ");
                        ler_string(associacao, 10);

                        if (associacao[0] == 's' || associacao[0] == 'S') {
                            for (int i = 0; i < quant; i++) {
                                printf("\n Digite o valor do %d° resistor: ", i + 1);
                                resistores[i] = ler_real_seguro();
                                reqS = reqS + resistores[i];
                            }
                            printf("\n A resistencia equivalente sera igual a: %.2f Ohm's\n", reqS);
                        } else if (associacao[0] == 'p' || associacao[0] == 'P') {
                            for (int i = 0; i < quant; i++) {
                                printf("\n Digite o valor do %d° resistor: ", i + 1);
                                resistores[i] = ler_real_seguro();
                                reqP = reqP + (1.0 / resistores[i]);
                                reqPtotal = 1.0 / reqP;
                            }
                            printf("\n A resistencia equivalente sera igual a: %.2f Ohm's\n", reqPtotal);
                        } else {
                            printf("\n Opcao errada ou inexistente! Tente novamente.\n");
                        }
                        break;
                    }
                    case 2: {
                        char relacao[10];
                        printf("\n Insira a quantidade de indutores: ");
                        quant = ler_inteiro_seguro();

                        double indutores[quant];
                        double leqS = 0.0;
                        double leqP = 0.0;
                        double leqPtotal = 0.0;

                        printf("\n Defina se a associacao sera realizada em serie ou em paralelo: \n");
                        printf("\n Digite 'S' para serie ou 'P' para paralelo: ");
                        ler_string(relacao, 10);

                        if (relacao[0] == 's' || relacao[0] == 'S') {
                            for (int i = 0; i < quant; i++) {
                                printf("\n Digite o valor do %d° indutor: ", i + 1);
                                indutores[i] = ler_real_seguro();
                                leqS = leqS + indutores[i];
                            }
                            printf("\n A indutancia equivalente sera igual a: %.2f Henry\n", leqS);
                        } else if (relacao[0] == 'p' || relacao[0] == 'P') {
                            for (int i = 0; i < quant; i++) {
                                printf("\n Digite o valor do %d° indutor: ", i + 1);
                                indutores[i] = ler_real_seguro();
                                leqP = leqP + (1.0 / indutores[i]);
                                leqPtotal = 1.0 / leqP;
                            }
                            printf("\n A indutancia equivalente sera igual a: %.2f Henry\n", leqPtotal);
                        } else {
                            printf("\n Opcao errada ou inexistente! Tente novamente.\n");
                        }
                        break;
                    }
                    case 3: {
                        char correlacao[10];
                        printf("\n Insira a quantidade de capacitores: ");
                        quant = ler_inteiro_seguro();

                        double capacitores[quant];
                        double ceqS = 0.0;
                        double ceqStotal = 0.0;
                        double ceqP = 0.0;

                        printf("\n Defina se a associacao sera realizada em serie ou em paralelo: \n");
                        printf("\n Digite 'S' para serie ou 'P' para paralelo: ");
                        ler_string(correlacao, 10);

                        if (correlacao[0] == 's' || correlacao[0] == 'S') {
                            for (int i = 0; i < quant; i++) {
                                printf("\n Digite o valor do %d° capacitor: ", i + 1);
                                capacitores[i] = ler_real_seguro();
                                ceqS = ceqS + (1.0 / capacitores[i]);
                                ceqStotal = 1.0 / ceqS;
                            }
                            printf("\n A capacitancia equivalente sera igual a: %.6f Farad\n", ceqStotal);
                        } else if (correlacao[0] == 'p' || correlacao[0] == 'P') {
                            for (int i = 0; i < quant; i++) {
                                printf("\n Digite o valor do %d° capacitor: ", i + 1);
                                capacitores[i] = ler_real_seguro();
                                ceqP = ceqP + capacitores[i];
                            }
                            printf("\n A capacitancia equivalente sera igual a: %.6f Farad\n", ceqP);
                        } else {
                            printf("\n Opcao errada ou inexistente! Tente novamente\n");
                        }
                        break;
                    }
                }
                break;
            }

            case 2: {
                // Módulo de retificadores: calcula tensão, corrente e filtros.
                printf("\n ========================\n");
                printf("\n Calculo de retificadores\n");
                printf("\n ========================\n");

                printf("\n Calculos: Retificadores (meia onda, onda completa, ponte) e filtro.\n");
                printf("\n Observe as opcoes a seguir: \n");
                printf("\n (1) Calculo de meia onda\n");
                printf("\n (2) Calculo de onda completa\n");
                printf("\n (3) Calculo de ponte + filtro capacitivo (preferencial)\n");

                printf("\n Digite a opcao escolhida: ");
                ler_string(decisao, 10);

                if (strcmp(decisao, "1") == 0) { printf("\n Opcao valida!\n"); }
                else if (strcmp(decisao, "2") == 0) { printf("\n Opcao valida!\n"); }
                else if (strcmp(decisao, "3") == 0) { printf("\n Opcao valida!\n"); }
                else { printf("\n Opcao errada ou inexistente! Tente novamente.\n"); }

                double vPCArga = 0.0;
                double corMed = 0.0;

                switch (atoi(decisao)) {
                    case 1: {
                        double vRms, vPicocarga;
                        double tensaomedia, correntemedia, resistor;
                        
                        printf("\n Digite o valor eficaz da tensao: ");
                        vRms = ler_real_seguro();

                        vPicocarga = (vRms * 1.41421356) - 0.7;

                        printf("\n O valor de pico da tensao de entrada e: %.2f\n", vPicocarga);
                        printf("\n Agora, vamos descobrir o valor da tensao media na carga: \n");

                        tensaomedia = vPicocarga / 3.14159;

                        printf("\n A tensao media e: %.2f\n", tensaomedia);

                        printf("\n Insira o valor da resistencia: ");
                        resistor = ler_real_seguro();

                        printf("\n Agora, vamos descobrir o valor da corrente media na carga: \n");

                        correntemedia = tensaomedia / resistor;

                        printf("\n O valor da corrente media e: %.2f\n", correntemedia);
                        break;
                    }
                    case 2: {
                        double tensaodepico, valoreficaz, vMed, correntemed, resistencia;

                        printf("\n Nesse caso em especifico esta sendo utilizado em consideracao o diodo ideal (sem descontar os 0,7V)\n");
                        printf("\n Vamos descobrir a tensao de pico da onda da fonte: \n");
                        printf("\n Primeiramente, digite o valor eficaz (Rms): ");
                        valoreficaz = ler_real_seguro();

                        tensaodepico = valoreficaz * 1.41421356;

                        printf("\n A tensao de pico e: %.2f Volts\n", tensaodepico);
                        printf("\n Agora, vamos descobrir a tensao media: \n");

                        vMed = (2.0 * tensaodepico) / 3.14159;

                        printf("\n A tensao media e: %.2f Volts\n", vMed);
                        printf("\n Por fim, vamos descobrir a corrente media agora: \n");
                        printf("\n Digite o valor do resistor: ");
                        resistencia = ler_real_seguro();

                        correntemed = vMed / resistencia;

                        printf("\n A corrente media e igual a: %.2f Amperes\n", correntemed);
                        break;
                    }
                    case 3: {
                        double eficazvalor, vPIco, vMeD, rEsistor;
                        char diodo[10], decis[10];

                        printf("\n Voce escolheu: Calculo de ponte de diodos\n");
                        printf("\n Primeiro, e necessario descobrir o valor da tensao de pico na onda. Para isso, digite o valor eficaz da tensao: ");
                        eficazvalor = ler_real_seguro();

                        vPIco = eficazvalor * 1.41421356;

                        printf("\n O valor de pico na onda e: %.2f V\n", vPIco);
                        printf("\n Por favor, esclareca se o diodo e do tipo real ou ideal (silicio)\n");
                        printf("\n Digite 'R' para diodo do tipo real ou 'I' para diodo do tipo ideal (silicio): ");
                        ler_string(diodo, 10);

                        if (diodo[0] == 'i' || diodo[0] == 'I') {
                            printf("\n Por ser do tipo ideal, nao ha desconto de barreira de potencial no diodo.\n");
                            vPCArga = vPIco;
                        } else if (diodo[0] == 'r' || diodo[0] == 'R') {
                            printf("\n Por ser do tipo real (Silicio), havera um desconto de 1,4V nos diodos da ponte: \n");
                            vPCArga = vPIco - 1.4;
                            printf("\n O valor de pico na carga com o desconto e de: %.2f Volts\n", vPCArga);
                        } else {
                            printf("\n Opcao de diodo nao encontrada! Tente novamente \n");
                        }

                        printf("\n Agora e o momento de descobrir a tensao media na carga ---> \n");
                        vMeD = (2.0 * vPCArga) / 3.14159;
                        printf("\n O resultado da tensao media na carga e aproximadamente ---> %.2f Volts\n", vMeD);

                        printf("\n Por fim, vamos descobrir o valor da corrente.\n");
                        printf("\n Digite o valor do resistor: ");
                        rEsistor = ler_real_seguro();

                        corMed = vMeD / rEsistor;

                        printf("\n O valor da corrente media e aproximadamente ---> %.2f Amperes\n", corMed);
                        printf("\n DICA DO SISTEMA: Voce pode ir agora calcular o filtro usando estes mesmos valores!\n");

                        printf("\n Voce deseja calcular o filtro capacitivo utilizando esses valores? [S/N]: ");
                        ler_string(decis, 10);

                        if (decis[0] == 's' || decis[0] == 'S') {
                            double vripple, capacitor, vmedcomfiltro;
                            char decision[10];

                            printf("\n Opcao escolhida: Filtro capacitivo.\n");

                            if (corMed > 0.0 && vPCArga > 0.0) {
                                printf("\n [DADOS DETECTADOS]: O sistema reaproveitou a Corrente Media (%.2fA) e a Tensao de Pico (%.2fV) calculadas na Ponte anteriormente!\n", corMed, vPCArga);
                            } else {
                                printf("\n Primeiro, diga qual o valor da corrente media: ");
                                corMed = ler_real_seguro();
                                printf("\n Agora, o valor de pico da tensao na carga: ");
                                vPCArga = ler_real_seguro();
                            }

                            printf("\n Agora, o valor da tensao ripple maxima suportada em volts: ");
                            vripple = ler_real_seguro();

                            printf("\n Nesse momento e importante que informe se e em onda completa (frequencia de 120 Hz) ou se e meia onda (frequencia de 60Hz)\n");
                            printf("\n Digite 'C' para onda completa ou 'M' para meia onda: ");
                            ler_string(decision, 10);

                            if (decision[0] == 'c' || decision[0] == 'C') {
                                printf("\n Inicialmente vamos descobrir o valor do capacitor ideal para o circuito ---> \n");
                                capacitor = corMed / (120.0 * vripple);

                                printf("\n O valor aproximado do capacitor ideal para esse circuito e de %.4f Farad\n", capacitor);
                                printf("\n (Ou seja: %.1f uF)\n", capacitor * 1000000);

                                vmedcomfiltro = vPCArga - (vripple / 2.0);
                                printf("\n A tensao media aproximada e de: %.2f Volts\n", vmedcomfiltro);
                            } else if (decision[0] == 'm' || decision[0] == 'M') {
                                printf("\n Inicialmente vamos descobrir o valor do capacitor ideal para o circuito ---> \n");
                                capacitor = corMed / (60.0 * vripple);

                                printf("\n O valor aproximado do capacitor ideal para esse circuito e de %.4f Farad\n", capacitor);
                                printf("\n (Ou seja: %.1f uF)\n", capacitor * 1000000);

                                vmedcomfiltro = vPCArga - (vripple / 2.0);
                                printf("\n A tensao media aproximada e de: %.2f Volts\n", vmedcomfiltro);
                            } else {
                                printf("\n Opcao invalida ou inexistente! Tente novamente.");
                            }
                        }
                        break;
                    }
                }
                break;
            }

            case 3: {
                // Módulo de temporização: realiza cálculos com resistores e capacitores.
                double frequencia = 0.0, tempototal = 0.0;
                double tb = 0.0, ta = 0.0, hz = 0.0;
                double dutycycle = 0.0;
                char option[10];
               
                printf("\n ======================== \n");
                printf("\n  Modulo de Temporizacao \n");
                printf("\n ======================== \n");
                printf("\n1 - Calcular a frequencia(Circuito Simetrico R2 = R3 e C1 = C3): \n");
                printf("\n2 - Calcular o Duty Cycle e o Periodo Total(Circuito Assimetrico): \n");
                printf("\nEscolha uma alternativa: ");
                ler_string(option, 10);

                if (strcmp(option, "1") == 0) { printf("\n Opcao valida!\n"); } 
                else if (strcmp(option, "2") == 0) { printf("\n Opcao valida!\n"); } 
                else if (strcmp(option, "3") == 0) { printf("\n Opcao valida!\n"); } 
                else { printf("\n Opcao invalida ou inexistente! Tente novamente\n"); }
               
                switch (atoi(option)) {
                    case 1: {
                        int quantidade, quantidade2;
                        double valor_resistor, valor_capacitor;

                        printf("\n Digite a quantidade de resistores: ");
                        quantidade = ler_inteiro_seguro();

                        double resistorR[quantidade];

                        printf("\n Digite o valor do primeiro resistor (Ohm): ");
                        valor_resistor = ler_real_seguro();

                        for (int i = 0; i < quantidade; i++) {
                            resistorR[i] = valor_resistor;
                        }

                        printf("\n Por ser um circuito simetrico, os valores dos resistores sao os mesmos para todos!!\n");
                        printf("\n =========== VALORES DOS RESISTORES =========== \n");
                        for (int i = 0; i < quantidade; i++) {
                            printf("\n Resistor %d: %.2f Ohm's", i + 1, resistorR[i]);
                        }
                        printf("\n");

                        printf("\n Digite a quantidade de capacitores: ");
                        quantidade2 = ler_inteiro_seguro();

                        double capacitorR[quantidade2];

                        printf("\n Digite o valor do Capacitor em Farads (ex: 0.000010 para ser 10uF): ");
                        valor_capacitor = ler_real_seguro();

                        for (int i = 0; i < quantidade2; i++) {
                            capacitorR[i] = valor_capacitor;
                        }

                        tempototal = resistorR[0] * capacitorR[0];
                        printf("\n O resultado do tempo total sera: %fs\n", tempototal);
                        
                        frequencia = 1.0 / tempototal;
                        printf(" O resultado da frequencia sera: %fHz\n", frequencia);
                        break;
                    }
                    case 2: {
                        double r2, c1, r3, c2;

                        printf("\nDigite o valor de R2 (Ohm): ");
                        r2 = ler_real_seguro();
                        printf("Digite o valor de C1 (Farads): ");
                        c1 = ler_real_seguro();
                        printf("Digite o valor de R3 (Ohm): ");
                        r3 = ler_real_seguro();
                        printf("Digite o valor de C2 (Farads): ");
                        c2 = ler_real_seguro();

                        tb = 0.693 * r2 * c1;
                        printf("\nO resultado do tempo de nivel baixo sera: %.2fs\n", tb);
                        
                        ta = 0.693 * r3 * c2;
                        printf("O resultado do tempo de nivel alto sera: %.2fs\n", ta);
                        
                        tempototal = tb + ta;
                        printf("O resultado do periodo total sera: %.4fs\n", tempototal);
                        
                        dutycycle = r3 / (r2 + r3);
                        printf("O resultado do Duty Cycle sera: %.4f\n", dutycycle);
                        break;
                    }
                }
                break;
            }

            case 4: {
                // Módulo digital: simula portas lógicas básicas.
                printf("\n ============== \n");
                printf("\n Modulo digital \n");
                printf("\n ============== \n");

                int a, b;
                int and_val, or_val, not_val, xor_val;

                printf("\n--- Simulador de Portas Logicas ---\n");
                printf("\nDigite o valor da Entrada A (0 ou 1): ");
                a = ler_inteiro_seguro();
                printf("\nDigite o valor da Entrada B (0 ou 1): ");
                b = ler_inteiro_seguro();

                if ((a != 0 && a != 1) || (b != 0 && b != 1)) {
                    printf("\nValores invalidos. Por favor, digite apenas 0 ou 1.\n");
                    break;
                }

                if (a == 1 && b == 1) { and_val = 1; } else { and_val = 0; }
                if (a == 1 || b == 1) { or_val = 1; } else { or_val = 0; }
                if (a == 1) { not_val = 0; } else { not_val = 1; }
                if (a != b) { xor_val = 1; } else { xor_val = 0; }

                printf("\n--- Resultados ---\n");
                printf("Porta AND (A E B) = %d\n", and_val);
                printf("Porta OR (A OU B) = %d\n", or_val);
                printf("Porta XOR (A XOR B) = %d\n", xor_val);
                printf("Porta NOT (NAO A) = %d\n", not_val);
                break;
            }

            case 5: {
                // Módulo de corrente alternada: calcula reatâncias e impedância.
                double resistencia_eq, reat_Capacitiva, capacitor_eq;
                double reat_Indutiva, indutor_eq, reat_resultante, impedancia;
                double frequenciaH;
                double pi = 3.14159;
                char alternativaCa[10];
                
                printf("\n ===================== \n");
                printf("\n    Modulo de C.A. \n");
                printf("\n ===================== \n");
                printf("\n Observe as opcoes a seguir: \n");
                printf("\n Digite (1) para Reatancia Indutiva\n");
                printf("\n Digite (2) para  Reatancia Capacitiva\n");
                printf("\n Digite (3) para Impedancia total\n");
                
                printf("\n Digite a opcao escolhida: ");
                ler_string(alternativaCa, 10);

                switch (atoi(alternativaCa)) {
                    case 1:
                        printf("\nDigite o valor da frequencia em Hz(Hertz):  ");
                        frequenciaH = ler_real_seguro();
                        printf("\nDigite o valor da indutancia equivalente (L) em H(Henry):  ");
                        indutor_eq = ler_real_seguro();
                        
                        reat_Indutiva = 2.0 * pi * frequenciaH * indutor_eq;
                        printf("\nO valor da Reatancia Indutiva sera:  %.2f ohm\n", reat_Indutiva);
                        break;
                    case 2:
                        printf("\nDigite o valor da frequencia em Hz(Hertz):  ");
                        frequenciaH = ler_real_seguro();
                        printf("\nDigite o valor da capacitancia equivalente (C) em F(Farad): ");
                        capacitor_eq = ler_real_seguro();
                        
                        reat_Capacitiva = 1.0 / (2.0 * pi * frequenciaH * capacitor_eq);
                        printf("\nO valor da Reatancia Indutiva sera:  %f ohm\n", reat_Capacitiva);
                        break;
                    case 3:
                        printf("\nDigite o valor da resistencia equivalente em ohm:  ");
                        resistencia_eq = ler_real_seguro();
                        printf("\nDigite o valor da reatancia indutiva em ohm:  ");
                        reat_Indutiva = ler_real_seguro();
                        printf("\nDigite o valor da reatancia capacitiva em ohm:  ");
                        reat_Capacitiva = ler_real_seguro();
                        
                        reat_resultante = reat_Indutiva - reat_Capacitiva;
                        impedancia = sqrt(pow(resistencia_eq, 2) + pow(reat_resultante, 2));
                        printf("\nO valor da impedancia total e igual a: %.2f  ohm\n", impedancia);
                        break;
                }
                break;
            }

            case 6: {
                // Módulo de bases: converte números decimais para binário e hexadecimal.
                int numero, aux, i, j;
                int vetBin[32];
                int vetHex[16];

                printf("=================================\n");
                printf("     CONVERSOR NUMERICO\n");
                printf("=================================\n");
                printf("Digite um numero decimal: ");
                numero = ler_inteiro_seguro();

                if (numero < 0) {
                    printf("Erro: digite um numero positivo!\n");
                } else {
                    if (numero == 0) {
                        printf("\nBinario:     0\n");
                        printf("Hexadecimal: 0\n");
                    } else {
                        // --- Conversão para Binário ---
                        aux = numero;
                        i = 0;
                        while (aux > 0) {
                            vetBin[i] = aux % 2;
                            aux = aux / 2;
                            i++;
                        }
                        printf("\nBinario: ");
                        for (j = i - 1; j >= 0; j--) {
                            printf("%d", vetBin[j]);
                        }
                        printf("\n");

                        // --- Conversão para Hexadecimal ---
                        aux = numero;
                        i = 0;
                        while (aux > 0) {
                            vetHex[i] = aux % 16;
                            aux = aux / 16;
                            i++;
                        }
                        printf("Hexadecimal: ");
                        for (j = i - 1; j >= 0; j--) {
                            if (vetHex[j] < 10) {
                                printf("%d", vetHex[j]);
                            } else {
                                if (vetHex[j] == 10) { printf("A"); }
                                else if (vetHex[j] == 11) { printf("B"); }
                                else if (vetHex[j] == 12) { printf("C"); }
                                else if (vetHex[j] == 13) { printf("D"); }
                                else if (vetHex[j] == 14) { printf("E"); }
                                else if (vetHex[j] == 15) { printf("F"); }
                            }
                        }
                        printf("\n");
                    }
                }
                break;
            }
        }
    } while (strcmp(opcao, "7") != 0);

    return 0;
}

// =========================================================================
// FUNÇÕES AUXILIARES
// =========================================================================

void ler_string(char *buffer, int tamanho) {
    if (fgets(buffer, tamanho, stdin) != NULL) {
        // Remove a quebra de linha (\n) do final da string, se houver
        buffer[strcspn(buffer, "\n")] = '\0';
    }
}

int ler_inteiro_seguro() {
    char buffer[100];
    char *endptr;
    long val;
    
    while (1) {
        ler_string(buffer, sizeof(buffer));
        val = strtol(buffer, &endptr, 10);
        
        // Ignora espaços em branco ao final
        while (isspace((unsigned char)*endptr)) { endptr++; }
        
        // Verifica se houve conversão e se não sobrou lixo (letras) na string
        if (endptr != buffer && *endptr == '\0') {
            return (int)val;
        } else {
            printf("\n[ERRO] Letras/Simbolos nao permitidos! Digite apenas numeros inteiros: ");
        }
    }
}

double ler_real_seguro() {
    char buffer[100];
    char *endptr;
    double val;
    
    while (1) {
        ler_string(buffer, sizeof(buffer));
        val = strtod(buffer, &endptr);
        
        while (isspace((unsigned char)*endptr)) { endptr++; }
        
        if (endptr != buffer && *endptr == '\0') {
            return val;
        } else {
            printf("\n[ERRO] Letras nao permitidas! Digite um numero valido (use ponto para decimais): ");
        }
    }
}