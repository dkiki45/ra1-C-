#include <stdio.h>
#include <string.h>

#define MAX 100   // quantidade máxima de alimentos

// enum das categorias (leitura de dados)
typedef enum {
    CEREAIS = 1,
    VERDURAS = 2,
    FRUTAS = 3,
    CARNES = 4,
    PESCADOS = 5,
    LEITE = 6,
    LEGUMINOSAS = 7,
    NOZES = 8,
    BEBIDAS = 9,
    OVOS = 10
} Categoria;

// struct para armazenar os dados de cada alimento (leitura de dados)
typedef struct {
    int numero;
    char descricao[100];
    float umidade;
    float energia;
    float proteina;
    float carboidrato;
    int categoria; 
} Alimento;

// funcao para mapear número do enum -> string legível
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
        case BEBIDAS: return "Bebidas (alcoólicas e não alcoólicas)";
        case OVOS: return "Ovos e derivados";
        default:       return "Desconhecido";
    }
}

void listarDescricao(Alimento alimentos[], int qtd, int categoria){
    Alimento filtro[MAX];
    int qtdFiltro = 0;

    for (int i = 0; i < qtd; i++) {
        if (alimentos[i].categoria == categoria) {
            filtro[qtdFiltro++] = alimentos[i];
        }
    }

    if (qtdFiltro == 0) {
        printf("\nNenhum alimento encontrado nessa categoria.\n");
        return;
    }

    for (int i = 0; i < qtdFiltro - 1; i++)
        for (int j = 0; j < qtdFiltro - i - 1; j++)
            if (strcmp(filtro[j].descricao, filtro[j+1].descricao) > 0) {
                Alimento temp = filtro[j];
                filtro[j] = filtro[j+1];
                filtro[j+1] = temp;
            }

    // exibe o resultado ordenado por nome (A-Z)
    printf("\n=== %s (A-Z) ===\n", nomeCategoria(categoria));
    
    for (int i = 0; i < qtdFiltro; i++)
        printf("%d - %s | Energia: %.1f kcal\n",
        filtro[i].numero, filtro[i].descricao, filtro[i].energia);

}

void listarCapacidadeEnergetica(Alimento alimentos[], int qtd,  int categoria){
    Alimento filtro[MAX];
    int qtdFiltro = 0;

    for (int i = 0; i < qtd; i++) {
        if (alimentos[i].categoria == categoria) {
            filtro[qtdFiltro++] = alimentos[i];
        }
    }

    if (qtdFiltro == 0) {
        printf("\nNenhum alimento encontrado nessa categoria.\n");
        return;
    }

    for (int i = 0; i < qtdFiltro - 1; i++)
        for (int j = 0; j < qtdFiltro - i - 1; j++)
            if (filtro[j].energia < filtro[j+1].energia) {
                Alimento temp = filtro[j];
                filtro[j] = filtro[j+1];
                filtro[j+1] = temp;
            }

                        
    printf("\n=== %s (por energia) ===\n", nomeCategoria(categoria));
    for (int i = 0; i < qtdFiltro; i++)
        printf("%d - %s | Energia: %.1f kcal\n",
        filtro[i].numero, filtro[i].descricao, filtro[i].energia);

}

void listarMaiorUmidade(Alimento alimentos[], int qtd, int categoria) {
    int N;

    printf("Digite quantos alimentos deseja listar (N): ");
    scanf("%d", &N);

    Alimento filtro[MAX];
    int qtdFiltro = 0;

    for (int i = 0; i < qtd; i++) {
        if (alimentos[i].categoria == categoria) {
            filtro[qtdFiltro++] = alimentos[i];
        }
    }

    if (qtdFiltro == 0) {
        printf("\nNenhum alimento encontrado nessa categoria.\n");
        return;
    }

    // ordena por umidade decrescente
    for (int i = 0; i < qtdFiltro - 1; i++) {
        for (int j = 0; j < qtdFiltro - i - 1; j++) {
            if (filtro[j].umidade < filtro[j + 1].umidade) {
                Alimento temp = filtro[j];
                filtro[j] = filtro[j + 1];
                filtro[j + 1] = temp;
            }
        }
    }

    // limita até o máximo de alimentos disponíveis
    if (N > qtdFiltro) N = qtdFiltro;

    printf("\n=== %d alimentos com maior umidade na categoria %s ===\n",
           N, nomeCategoria(categoria));

    for (int i = 0; i < N; i++) {
        printf("%d - %s | Umidade: %.2f%% | Energia: %.1f kcal\n",
               filtro[i].numero,
               filtro[i].descricao,
               filtro[i].umidade,
               filtro[i].energia);
    }
}


void listarMaiorEnergia(Alimento alimentos[], int qtd, int categoria) {
    int N;

    printf("Digite quantos alimentos deseja listar (N): ");
    scanf("%d", &N);

    Alimento filtro[MAX];
    int qtdFiltro = 0;

    for (int i = 0; i < qtd; i++) {
        if (alimentos[i].categoria == categoria) {
            filtro[qtdFiltro++] = alimentos[i];
        }
    }

    if (qtdFiltro == 0) {
        printf("\nNenhum alimento encontrado nessa categoria.\n");
        return;
    }

    // ordena por energia decrescente
    for (int i = 0; i < qtdFiltro - 1; i++) {
        for (int j = 0; j < qtdFiltro - i - 1; j++) {
            if (filtro[j].energia < filtro[j + 1].energia) {
                Alimento temp = filtro[j];
                filtro[j] = filtro[j + 1];
                filtro[j + 1] = temp;
            }
        }
    }

    // limita até a quantidade de alimentos, no caso 5
    if (N > qtdFiltro) N = qtdFiltro;

    printf("\n=== %d Alimentos com maior capacidade energética na categoria %s ===\n",
           N, nomeCategoria(categoria));

    for (int i = 0; i < N; i++) {
        printf("%d - %s | Energia: %.1f kcal | Umidade: %.2f%%\n",
               filtro[i].numero,
               filtro[i].descricao,
               filtro[i].energia,
               filtro[i].umidade);
    }
}

void listarMaiorProteina(Alimento alimentos[], int qtd,  int categoria) {
    int N;

    printf("Digite quantos alimentos deseja listar (N): ");
    scanf("%d", &N);

    Alimento filtro[MAX];
    int qtdFiltro = 0;

    // filtra apenas os alimentos da categoria escolhida
    for (int i = 0; i < qtd; i++) {
        if (alimentos[i].categoria == categoria) {
            filtro[qtdFiltro++] = alimentos[i];
        }
    }

    if (qtdFiltro == 0) {
        printf("\nNenhum alimento encontrado nessa categoria.\n");
        return;
    }

    // ordena decrescentemente por proteína
    for (int i = 0; i < qtdFiltro - 1; i++) {
        for (int j = 0; j < qtdFiltro - i - 1; j++) {
            if (filtro[j].proteina < filtro[j + 1].proteina) {
                Alimento temp = filtro[j];
                filtro[j] = filtro[j + 1];
                filtro[j + 1] = temp;
            }
        }
    }

    printf("\n=== %d Alimentos com mais proteína na categoria %s ===\n",
           N, nomeCategoria(categoria));


    for (int i = 0; i < N; i++){
        printf("%d - %s | Proteína: %.2f g | Energia: %.1f kcal\n",
               filtro[i].numero,
               filtro[i].descricao,
               filtro[i].proteina,
               filtro[i].energia);
    }
}

void listarMaiorCarboidrato(Alimento alimentos[], int qtd,  int categoria) {
    int N;

    printf("Digite quantos alimentos deseja listar (N): ");
    scanf("%d", &N);

    float relacao[MAX];
    Alimento filtro[MAX];
    int qtdFiltro = 0;

    // filtra apenas os alimentos da categoria escolhida
    for (int i = 0; i < qtd; i++) {
        if (alimentos[i].categoria == categoria) {
            filtro[qtdFiltro++] = alimentos[i];
        }
    }

    if (qtdFiltro == 0) {
        printf("\nNenhum alimento encontrado nessa categoria.\n");
        return;
    }

    // ordena decrescentemente por carboidrato
    for (int i = 0; i < qtdFiltro - 1; i++) {
        for (int j = 0; j < qtdFiltro - i - 1; j++) {
            if (filtro[j].carboidrato < filtro[j + 1].carboidrato) {
                float tmp = relacao[j];
                Alimento temp = filtro[j];
                filtro[j] = filtro[j + 1];
                filtro[j + 1] = temp;
            }
        }
    }

    printf("\n=== %d Alimentos com mais carboidrato na categoria %s \n",
           N, nomeCategoria(categoria));

    for (int i = 0; i < N; i++) {
        printf("%d - %s | Carboidrato: %.2f g | Energia: %.1f kcal\n",
               filtro[i].numero,
               filtro[i].descricao,
               filtro[i].carboidrato,
               filtro[i].energia);
    }
}

void listarRelacaoEnergiaProteina(Alimento alimentos[], int qtd,  int categoria){
    int N;

    printf("Digite quantos alimentos deseja listar (N): ");
    scanf("%d", &N);

    float relacao[MAX];
    Alimento filtro[MAX];
    int qtdFiltro = 0;

    for (int i = 0; i < qtd; i++) {
        if (alimentos[i].categoria == categoria) {
            filtro[qtdFiltro++] = alimentos[i];
        }
    }

    if (qtdFiltro == 0) {
        printf("\nNenhum alimento encontrado nessa categoria.\n");
        return;
    }

    for (int i = 0; i < qtdFiltro; i++) {
            if (filtro[i].proteina > 0)
                relacao[i] = filtro[i].energia / filtro[i].proteina;
            else
                relacao[i] = 0; // evita divisão por zero
        }

    for (int i = 0; i < qtdFiltro - 1; i++) {
        for (int j = 0; j < qtdFiltro - i - 1; j++) {
            if (relacao[j] < relacao[j + 1]) {
                    float tmp = relacao[j];
                    relacao[j] = relacao[j + 1];
                    relacao[j+1] = tmp;
                    Alimento temp = filtro[j];
                    filtro[j] = filtro[j + 1];
                    filtro[j + 1] = temp;
            }
        }
    }

    printf("\n=== %d Alimentos com maior relação Energia/Proteína na categoria %s ===\n", 
                N, nomeCategoria(categoria));

    for (int i = 0; i < N; i++) {
        printf("%d - %s | Energia: %.1f | Proteína: %.2f | Relação: %.2f\n",
                filtro[i].numero,
                filtro[i].descricao,
                filtro[i].energia,
                filtro[i].proteina,
                relacao[i]);
    }
}

void listarRelacaoEnergiaCarboidrato(Alimento alimentos[], int qtd,  int categoria){
    int N;

    printf("Digite quantos alimentos deseja listar (N): ");
    scanf("%d", &N);

    float relacao[MAX];
    Alimento filtro[MAX];
    int qtdFiltro = 0;

    for (int i = 0; i < qtd; i++) {
        if (alimentos[i].categoria == categoria) {
            filtro[qtdFiltro++] = alimentos[i];
        }
    }

    if (qtdFiltro == 0) {
        printf("\nNenhum alimento encontrado nessa categoria.\n");
        return;
    }


    for (int i = 0; i < qtdFiltro; i++) {
        if (filtro[i].carboidrato > 0)
            relacao[i] = filtro[i].energia / filtro[i].carboidrato;
        else
            relacao[i] = 0;
    }
        

    for (int i = 0; i < qtdFiltro - 1; i++) {
        for (int j = 0; j < qtdFiltro - i - 1; j++) {
            if (relacao[j] < relacao[j + 1]) {
                float tmp = relacao[j];
                relacao[j] = relacao[j + 1];
                relacao[j+1] = tmp;
                Alimento temp = filtro[j];
                filtro[j] = filtro[j + 1];
                filtro[j + 1] = temp;
            }
        }
    }


    printf("\n=== %d Alimentos com maior relação Energia/Carboidrato na categoria %s ===\n", 
            N, nomeCategoria(categoria));

    for (int i = 0; i < N; i++) {
        printf("%d - %s | Energia: %.1f | Carboidrato: %.2f | Relação: %.2f\n",
            filtro[i].numero,
            filtro[i].descricao,
            filtro[i].energia,
            filtro[i].carboidrato,
            relacao[i]);
    }
}

int main() {
    FILE *fp; // ponteiro para o arquivo
    Alimento alimentos[MAX]; // armazena varios registros (vetor de structs)
    int qtd = 0;

    // abre o CSV
    fp = fopen("alimentos.csv", "r");
    if (fp == NULL) 
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // ignora o cabeçalho
    char header[200];
    fgets(header, sizeof(header), fp);

    // le linha por linha do arquivo
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

    int opcaoPrincipal = -1; // controla o loop principal

    while (opcaoPrincipal != 0) {
        printf("\n===== MENU PRINCIPAL =====\n");
        printf("1 - Listar categorias\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcaoPrincipal);

        // listar categorias
        if (opcaoPrincipal == 1) {
            int escolhaCategoria = -1;

            // loop interno — permite escolher várias categorias sem sair do menu
            while (escolhaCategoria != 0) {
                printf("\n=== Categorias disponíveis ===\n");

                // mostra todas as categorias numeradas
                for (int i = 1; i <= 10; i++)
                    printf(" %d - %s\n", i, nomeCategoria(i));
                
                printf(" 0 - Voltar\n");
                printf("Escolha uma categoria: ");
                scanf("%d", &escolhaCategoria);

                // se o usuário escolher uma categoria válida (1–10)
                if (escolhaCategoria >= 1 && escolhaCategoria <= 10) {
                    int menuCategoria = -1;

                    // opcoes da categoria 
                    while (menuCategoria != 0) {
                        printf("\n=== %s ===\n", nomeCategoria(escolhaCategoria));
                        printf("1 - Listar alimentos (A-Z)\n");
                        printf("2 - Listar alimentos por energia (decrescente)\n");
                        printf("3 - Listar os N alimentos de certa categoria com maior percentual de umidade, (decrescente)\n");
                        printf("4 - Listar os N alimentos de certa categoria com maior energia , (decrescente)\n");
                        printf("5 - Listar os N alimentos de certa categoria com maior quantidade de proteína, (decrescente)\n");
                        printf("6 - Listar os N alimentos de certa categoria com maior quantidade de carboidrato, (decrescente)\n");
                        printf("7 - Listar os N alimentos de certa categoria que possuam a relação mais alta entre energia e proteína, (decrescente)\n");
                        printf("8 - Listar os N alimentos de certa categoria que possuam a relação mais alta entre energia e carboidrato, (decrescente)\n");
                        printf("0 - Voltar\n");
                        printf("Escolha: ");
                        scanf("%d", &menuCategoria);

                        if (menuCategoria == 0) break; // volta ao menu anterior

                        // Copia apenas os alimentos da categoria escolhida
                        Alimento filtro[MAX];
                        int qtdFiltro = 0;

                        for (int i = 0; i < qtd; i++) {
                            if (alimentos[i].categoria == escolhaCategoria)
                                filtro[qtdFiltro++] = alimentos[i];
                        }

                        if (menuCategoria == 1) {
                            listarDescricao(alimentos, qtd, escolhaCategoria);
                        }
                        else if (menuCategoria == 2) {
                            listarCapacidadeEnergetica(alimentos, qtd, escolhaCategoria); 
                        }
                        else if (menuCategoria == 3) {
                            listarMaiorUmidade(alimentos, qtd, escolhaCategoria);
                        }
                        else if(menuCategoria == 4){
                            listarMaiorEnergia(alimentos, qtd, escolhaCategoria);
                        }
                        else if(menuCategoria == 5){
                            listarMaiorProteina(alimentos, qtd, escolhaCategoria);
                        }
                        else if(menuCategoria == 6){
                            listarMaiorCarboidrato(alimentos, qtd, escolhaCategoria);
                        }
                        else if(menuCategoria == 7){
                            listarRelacaoEnergiaProteina(alimentos, qtd,  escolhaCategoria);
                        }
                        else if(menuCategoria == 8){
                            listarRelacaoEnergiaCarboidrato(alimentos, qtd, escolhaCategoria);
                        }
                    }
                }
            }
        }
    }

    printf("\nEncerrando o programa...\n");
    return 0;
}
