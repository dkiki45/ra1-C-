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
