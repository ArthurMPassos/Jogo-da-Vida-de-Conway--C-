/*
Autor: 
Arthur Moreira Passos
*/

#include <stdio.h>
#include <unistd.h>

//Imprime o numero certo de "=" 
void ImprimeIguais(int tamanho){
    printf("\n");
    for(int i = 0; i<(tamanho*2-1);i++){
        printf("=");
    }
}


int main(void) {
    //tamanho da matriz
    #define tamanho 15

    //criando a matriz[linha][coluna]
    int mat[tamanho][tamanho];
    for(int linha = 0; linha<tamanho; linha++){
        for(int coluna = 0; coluna<tamanho; coluna++){
            mat[linha][coluna] = 0;
        }
    }
    
    //definindo configuração inicial: o EXPLODER
    mat[5][5] = 1;
    mat[5][7] = 1;
    mat[5][9] = 1;
    mat[6][5] = 1;
    mat[6][9] = 1;
    mat[7][5] = 1;
    mat[7][9] = 1;
    mat[8][5] = 1;
    mat[8][9] = 1;
    mat[9][5] = 1;
    mat[9][7] = 1;
    mat[9][9] = 1;
    
    //cria copia da mat
    int matCopia[tamanho][tamanho];
    for(int linha = 0; linha<tamanho; linha++){
        for(int coluna = 0; coluna<tamanho; coluna++){
            matCopia[linha][coluna] = mat[linha][coluna];
        }
    }

    printf("\nJogo da Vida de Conway (EXPLODER)");

    ImprimeIguais(tamanho);

    //Imprime matriz
    for(int linha = 0; linha<tamanho; linha++)
    {
        printf("\n");
        for(int coluna = 0; coluna<tamanho; coluna++)
        {
            if(mat[linha][coluna]==1) printf("X ");
            else printf("- ");
        }
    }

    ImprimeIguais(tamanho);

    int opc;
    printf("\n[1] Printar um passo da matriz");
    printf("\n[2] Printar passos da matriz continuamente");
    printf("\n[3] Fechar programa (ou com Ctrl + C)\n");
    scanf("%d", &opc);

    //While True
    while(1>0)
    {
        if (opc ==3) break;
        if(opc==1)
        {
            //int passador;  
            printf("\nDigite 1 para o proximo passo: ");

            scanf("%d",&opc);
        }
        else sleep(1);
        {
            int linhaViz;
            int colunaViz;
            int nDeVivos = 0;
            //For para cada celula da matriz
            for(int linha = 0; linha<tamanho; linha++)
            {
                for(int coluna = 0; coluna<tamanho; coluna++)
                {   
                    nDeVivos = 0;
                    //for para cada celula ao redor de cada celula da matriz
                    for(int k = -1; k<2; k++)
                    {
                        for(int p = -1; p<2; p++)
                        {
                            linhaViz = k + linha;
                            colunaViz = p + coluna;
                            //if para considerar as bordas como "não populadas"
                            if(linhaViz<0||colunaViz<0||linhaViz>14||colunaViz>14||(linhaViz ==linha && colunaViz == coluna)) continue;
                            if(mat[linhaViz][colunaViz]== 1) nDeVivos++;
                        }
                        
                    }
                    //Contador de numero de celulas "populadas" decisao
                    if(mat[linha][coluna] == 0 && nDeVivos == 3) matCopia[linha][coluna] = 1;
                    if(mat[linha][coluna] == 1)
                    {
                        if(nDeVivos<=1||nDeVivos>=4) matCopia[linha][coluna] = 0;
                    }
                }
            }
        }
        
        //devolve os valores de matCopia para mat
        for(int linha = 0; linha<tamanho; linha++)
        {
            for(int coluna = 0; coluna<tamanho; coluna++)
            {
                mat[linha][coluna] = matCopia[linha][coluna];
            }
        }

        ImprimeIguais(tamanho);

        for(int linha = 0; linha<tamanho; linha++)
        {
            printf("\n");
            for(int coluna = 0; coluna<tamanho; coluna++)
            {
                if(mat[linha][coluna]==1) printf("X ");
                else printf("- ");
            }
        }

        ImprimeIguais(tamanho);

    }

    return 0;
}
