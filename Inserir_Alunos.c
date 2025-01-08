# include <stdio.h>
# include <string.h>
# include <stdlib.h>


int main(){

    typedef struct Estudantes
    {
        char nome[100], Morada[100], Curso[50], DatadeNascimento[11];
        int NumerodeEstudante;
    }estudantes;
//_____________________________________________________________________________//
    FILE *file = fopen("Alunos.txt", "w");
    
        if (file == NULL){ 
            printf ("ERRO!");
        }
        else{

            fprintf(file,"Base de Dados\n\n");            
    
            fclose(file);
    
        }
/*
        FILE *file1 = fopen("Curso.txt", "w");
    
        if (file1 == NULL){ 
            printf ("ERRO!");
        }
        else{
    
            fclose(file1);
    
        }
*/

    int escolha=0;


    while (escolha!=5)
    {
        
        printf("\n\n ----------------------- ");

        printf("\n Pressione 1 para - Inserir novo estudante ");
        printf("\n           2 - Opcao 2 ");
        printf("\n           3 - Opcao 3 ");
        printf("\n           4 - Opcao 4 ");
        printf("\n           5 - Fechar Programa ");
        printf("\n\n ----------------------- ");
        printf("\n\n Escolha uma opcao: ");

       
        scanf("%d", &escolha);
    
        
    switch (escolha) {

        case 1:
        {

            int x, i;
            printf("\n\n Escolheu 1 - Inserir novo estudante  ");
            printf("\n\n ----------------------- \n\n");
            printf("Quantos novos alunos pretende adicionar?");
            scanf("%d", &x);
            getchar();


            estudantes NovoEstudantes[x];

            for(i=0; i<x; i++){

           
                printf("Nome do %d estudante:\n", i+1); 
                fgets(NovoEstudantes[i].nome, sizeof(NovoEstudantes[i].nome), stdin);
                  
                
                /* 

                sizeof(NovoEstudantes[i].nome): Isto garante que fgets() não excede o tamanho definido para nome.
                
                stdin: é o fluxo de entrada o teclado neste caso. fgets() lerá os caracteres até:

                -O comprimento máximo do buffer é atingido (determinado por sizeof()).
                -É encontrado um caractere de nova linha (\n) (quando o utilizador pressiona "Enter").
                -O fim do ficheiro (EOF) foi atingido.
                
                A função strcspn (definida em <string.h>):

                Navegue pela string até encontrar o caractere especificado aqui, "\n" .
                devolve o índice (posição) do primeiro caractere encontrado ou, 
                se não for encontrado nenhum caractere, o comprimento total da string. 
                Uma vez encontrado o índice, o caractere \n é substituído pelo caractere nulo ('\0'), que marca o fim da string.
                */

                printf("Numero se Estudante do %d estudante:\n", i+1);
                scanf("%d", &NovoEstudantes[i].NumerodeEstudante);
                getchar();

                printf("Data de Nascimento do %d estudante (DD/MM/AAAA)):\n", i+1); 
                fgets(NovoEstudantes[i].DatadeNascimento, sizeof(NovoEstudantes[i].DatadeNascimento), stdin);
                

                printf("Morada do %d estudante:\n", i+1); 
                fgets(NovoEstudantes[i].Morada, sizeof(NovoEstudantes[i].Morada), stdin);
                

                printf("Curso do %d estudante:\n", i+1); 
                fgets(NovoEstudantes[i].Curso, sizeof(NovoEstudantes[i].Curso), stdin);
                NovoEstudantes[i].Curso[strcspn(NovoEstudantes[i].Curso, "\n")] = '\0';

                file = fopen("Alunos.txt", "a");
                if (file == NULL) {
                        printf("Erreur lors de l'ouverture de Alunos.txt !\n");
                        return 1;
                    }
                else{
                    fprintf(file, "%d\t;%s\t;%s\t;%s\t;%s\n", 
                    NovoEstudantes[i].NumerodeEstudante, 
                    NovoEstudantes[i].nome, 
                    NovoEstudantes[i].DatadeNascimento,
                    NovoEstudantes[i].Morada, 
                    NovoEstudantes[i].Curso);

                    fclose(file);
                    printf("\nEstudante inserido com sucesso!\n");
                } 
               

                
                
                fflush(stdin);


            }
        


            break;
        }
    }
    
    }
    return 0;
}