/*
Crie uma estrutura para representar um aluno, contendo nome, matrícula, nota AV1, nota AV2 e nota AV3. 
Essa estrutura deve armazenar 3 alunos.
Obs.: O primeiro aluno deverá ter  o seu nome.
Crie uma outra estrutura para representar uma turma, contendo nome, código da disciplina e um vetor de alunos. 
OBS.: o código da turma será digitado pro você e deve corresponder ao criado no SIA. 
Use typedef para criar novos tipos para essas estruturas.
Escreva funções para calcular a média (deverá ser desconsiderada a menor nota entre a AV1, AV2 e AV3). 
As notas só poderão ir de 0 a 10.
Escreva a situação final (aprovado ou reprovado) de cada aluno. Lembrando que para aprovação a média deverá ser maior do que 6.

É obrigatório o envio dos prints da resolução.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
    
typedef struct aluno
{
    char nome[50];
    char matricula[13];
    float av1, av2, av3;
}Aluno;
typedef struct turma
{
    char nome[50];
    char codigo_diciplina[50];
    Aluno alunos[3];
}turma;
float media_notas(float av1, float av2, float av3){
    float media;
    
    if (av1 > av2 && av2 > av3){
        media = (av1 + av2) / 2;
    }
    else if (av2 > av1 && av3 > av1){
        media = (av2 + av3) / 2;
    }
    else{
        media = (av1 + av3) / 2;
    }
    return media;
}

int main()
{
    turma turma1;

    sprintf(turma1.nome , "Estrutura de Dados");
    sprintf(turma1.codigo_diciplina , "ARA0098");

    sprintf(turma1.alunos[0].nome , "Matheus Felipe Braga");
    sprintf(turma1.alunos[0].matricula , "202204465981");
    turma1.alunos[0].av1 = 9.0;
    turma1.alunos[0].av2 = 9.0;
    turma1.alunos[0].av3 = 9.0;
    sprintf(turma1.alunos[1].nome , "João");
    sprintf(turma1.alunos[1].matricula , "202204465980");
    turma1.alunos[1].av1 = 5.0;
    turma1.alunos[1].av2 = 5.0;
    turma1.alunos[1].av3 = 7.0;
    sprintf(turma1.alunos[2].nome , "Maria");
    sprintf(turma1.alunos[2].matricula , "202204465982");
    turma1.alunos[2].av1 = 3.0;
    turma1.alunos[2].av2 = 2.0;
    turma1.alunos[2].av3 = 1.0;
    float media;
    for(int i = 0; i < 3; i++)
    {
        printf("--------------------------------------------------------------------\n\n");
        media = media_notas(turma1.alunos[i].av1,turma1.alunos[i].av2,turma1.alunos[i].av3);
        printf("O aluno %s, cuja matricula é: %s, tirou %.1f, %.1f e %.1f nas provas de %s da turma %s\n", turma1.alunos[i].nome, turma1.alunos[i].matricula, turma1.alunos[i].av1, turma1.alunos[i].av2, turma1.alunos[i].av3, turma1.nome, turma1.codigo_diciplina);
        printf("Segundo as regras do SIA, sua média foi de %.1f nas provas\n\n", media);
        if(media > 5.9){
            printf("APROVADO!\n");
        }
        else{
            printf("REPROVADO!\n");
        }
    }
    
    return 0;
}