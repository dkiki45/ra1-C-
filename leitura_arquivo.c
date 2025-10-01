#include <stdio.h>
#include <stdlib.h>

#define MAX 150   // quantidade máxima de alimentos

// Enum das categorias 
typedef enum {
    CEREAIS = 1,
    VERDURAS = 2,
    FRUTAS = 3,
    CARNES = 4,
    PESCADOS = 5,
    LEITE = 6,
    LEGUMINOSAS = 7,
    NOZES = 8
} Categoria;

// Struct para armazenar os dados de cada alimento
typedef struct {
    int numero;
    char descricao[100];
    float umidade;
    float energia;
    float proteina;
    float carboidrato;
    int categoria; 
} Alimento;

// Função para mapear número do enum -> string legível
const char* nomeCategoria(int cat) {
    switch(cat) {
        case CEREAIS:  return "Cereais e Derivados";
        case VERDURAS: return "Verduras, hortaliças e derivados";
        case FRUTAS:   return "Frutas e Derivados";
        case CARNES:   return "Carnes e Derivados";
        case PESCADOS: return "Pescados e Frutos do Mar";
        case LEITE: return "Leite e derivados";
        case LEGUMINOSAS: return "Leguminosas e derivados";
        case NOZES: return "Nozes e sementes";
        default:       return "Desconhecido";
    }
}

int main() {
    FILE *fp;
    Alimento alimentos[MAX];
    int qtd = 0;

    // Abre o CSV
    fp = fopen("alimentos.csv", "r");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Ignora o cabeçalho
    char header[200];
    fgets(header, sizeof(header), fp);

    // Lê linha por linha do arquivo
    while (fscanf(fp, "%d,%99[^,],%f,%f,%f,%f,%d",
                  &alimentos[qtd].numero,
                  alimentos[qtd].descricao,
                  &alimentos[qtd].umidade,
                  &alimentos[qtd].energia,
                  &alimentos[qtd].proteina,
                  &alimentos[qtd].carboidrato,
                  &alimentos[qtd].categoria) == 7) {
        qtd++;
        if (qtd >= MAX) break;
    }

    fclose(fp);

    printf(" Bem-vindo ao Sistema de Alimentos  \n");

    printf("Categorias disponíveis:\n");
    printf(" %d - %s\n", CEREAIS, nomeCategoria(CEREAIS));
    printf(" %d - %s\n", VERDURAS, nomeCategoria(VERDURAS));
    printf(" %d - %s\n", FRUTAS, nomeCategoria(FRUTAS));
    printf(" %d - %s\n", CARNES, nomeCategoria(CARNES));
    printf(" %d - %s\n", PESCADOS, nomeCategoria(PESCADOS));
    printf(" %d - %s\n", LEITE, nomeCategoria(LEITE));
    printf(" %d - %s\n", LEGUMINOSAS, nomeCategoria(LEGUMINOSAS));
    printf(" %d - %s\n", NOZES, nomeCategoria(NOZES));

    int escolha;
    printf("\nDigite o número da categoria desejada: ");
    scanf("%d", &escolha);

    printf("\n=== Alimentos da categoria %s ===\n", nomeCategoria(escolha));
    for (int i = 0; i < qtd; i++) {
        if (alimentos[i].categoria == escolha) {
            printf("%d - %s | Energia: %.1f kcal | Proteína: %.1fg | Carboidrato: %.1fg\n",
                   alimentos[i].numero,
                   alimentos[i].descricao,
                   alimentos[i].energia,
                   alimentos[i].proteina,
                   alimentos[i].carboidrato);
        }
    }

    return 0;
}
