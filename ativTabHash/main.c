#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabHash.h"

int main() {
    int opcao, opcao_colisao, matricula, confirmar, TABLE_SIZE = 10;
    char nome[31];
    float n1, n2, n3;
    Hash *ha = criaHash(TABLE_SIZE);
    struct aluno al;
    if (ha == NULL) {
        printf("erro ao criar tabela hash\n");
        return -1;}
    do {

        printf("(1) Inserir aluno\n\n");
        printf("(2) Buscar aluno\n\n");
        printf("(3) Encerrar\n\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite a matricula do aluno: ");
                scanf("%d", &matricula);
                printf("\n\nDigite o nome do aluno: ");
                scanf("%s", nome);
                printf("\nDigite a primeira nota: ");
                scanf(" %f", &n1);
                printf("\nDigite a segunda nota: ");
                scanf(" %f", &n2);
                printf("\nDigite a terceira nota: ");
                scanf(" %f", &n3);

                al.matricula = matricula;
                strcpy(al.nome, nome);
                al.n1 = n1;
                al.n2 = n2;
                al.n3 = n3;

                printf("Deseja realmente inserir esse aluno? \n\n[1] Sim \n\n[2] Nao\n\n");
                scanf("%d", &confirmar);

                if (confirmar == 1) {

                    printf("1.Inserir COM tratamento de colisao\n");
                    printf("2.Inserir SEM colisao\n");
                    printf("Opcao: ");
                    scanf("%d", &opcao_colisao);

                    if (opcao_colisao == 1) {
                        if (insereHash_enderecoAberto(ha, al)) {
                            printf("Aluno inserido com sucesso com tratamento de colisao!\n");
                        } else {
                            printf("Erro ao inserir aluno com tratamento de colisao.\n");
                        }
                    } else {
                        if (insereHash_semColisao(ha, al)) {
                            printf("Aluno inserido com sucesso sem tratamento de colisao!\n");
                        } else {
                            printf("Erro ao inserir aluno sem tratamento de colisao.\n");
                        }
                    }
                } else {
                    printf("insercao cancelada pelo usuario.\n\n");
                }
                break;

            case 2:
                printf("Digite a matricula do aluno: ");
                scanf("%d", &matricula);

                printf("[1] Buscar COM tratamento de colisao\n\n");
                printf("[2] Buscar SEM colisao\n");
                printf("Opcao: ");
                scanf("%d", &opcao_colisao);

                if (opcao_colisao == 1) {
                    if (buscaHash_enderecoAberto(ha, matricula, &al)) {
                        printf("aluno encontrado com tratamento de colisao:\n\n");
                        printf("Nome: %s, Matricula: %d, Notas: %.2f %.2f %.2f\n", al.nome, al.matricula, al.n1, al.n2, al.n3);
                    } else {
                        printf("aluno nao encontrado com tratamento de colisao.\n\n");
                    }
                } else {
                    if (buscaHash_semColisao(ha, matricula, &al)) {
                        printf("aluno encontrado sem tratamento de colisao:\n\n");
                        printf("Nome: %s, Matricula: %d, Notas: %.2f %.2f %.2f\n\n", al.nome, al.matricula, al.n1, al.n2, al.n3);
                    } else {
                        printf("aluno nao encontrado sem tratamento de colisao.\n\n");
                    }
                }
                break;

            case 3:
                printf("encerrando programa\n");
                break;

            default:
                printf("opcao invalida\n");
        }
    } while (opcao != 3);

    liberaHash(ha);

    return 0;
}
