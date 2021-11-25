#include <stdlib.h>
#include <string.h>
#include <stdio.h>
void retourner();
int cmp;
char t_nom[1000][20];
char t_prenom[1000][20];
char t_cin[1000][20];
float t_montant[1000];
char rech_cin[1][20];
int p = 0;

void menu()
{
    printf("\n");
    printf("\t 1) AUTHENTIFICATION\t\t");
    printf(" 2) OPERATIONS\t\t\n");
    printf("\n");
    printf("\t 3) AFFICHAGE\t");
    printf(" \t \t 4) FEDILISATION\t\n");
    printf("\n");
    printf("\t \t----------> 0) QUITTER <----------");
}
void comptes()
{
    printf("\ncreer des nouveaux compts : \n");
    printf("\tcombient de comptes voulez vous creer ?\n\t");
    scanf("%d", &cmp);
    int i;
    int j;
    for (i = p; i < cmp + p; i++)
    {
        printf("\tentrez le prenom  : ");
        scanf("%s", t_nom[i]);
        printf("\tentrez le nom  : ");
        scanf("%s", t_prenom[i]);
        printf("\tentrez CIN  : ");
        scanf("%s", t_cin[i]);
        printf("\tentrez MONTANT : ");
        scanf("%f", &t_montant[i]);
        j++;
        if (i <cmp+p- 1)
        {
            printf("\n\tentrez les autres comptes \n");
        }
    }
    p = p + cmp;
    int a;
    printf("voulez vous retourner au menu  : \n");
    printf("1) OUI \t 2) NON \n");
    scanf("%d", &a);
    if (a == 1)
    {
        retourner();
    }
    else
    {
        printf(" quiter l'operation ");
    }
}
void nvcomptes()
{
    int i;
    for (i = p; i< p+1; i++)
    {
            printf("\tentrez le prenom  : ");
            scanf("%s", t_nom[i]);
            printf("\tentrez le nom  : ");
            scanf("%s", t_prenom[i]);
            printf("\tentrez CIN  : ");
            scanf("%s", t_cin[i]);
            printf("\tentrez MONTANT : ");
            scanf("%f", &t_montant[i]);
            break;
    }
    p = p + 1;
    int a;
    printf("voulez vous retourner au menu  : \n");
    printf("1) OUI \t 2) NON \n");
    scanf("%d", &a);
    if (a == 1)
    {
        retourner();
    }
    else
    {
        printf(" quiter l'operation ");
    }
}
void choixcompte()
{
    int choix;
    printf("\t\t 1)- Pour creer beaucoup de client  ");
    printf("\t\t 2)- Pour creer  un seul  client ");
    printf("\nsaisir votre choix : ");
    scanf("%d", &choix);
    switch (choix)
    {
    case 1:
        comptes();
        break;
    case 2:
        nvcomptes();
        break;
    }
}

int recherche()
{
    int j, i = -1;
    printf("\n\trechercher par CIN\n\t");
    scanf("%s", rech_cin[0]);
    for (j = 0; j < p; j++)
    {
        if (strcmp(t_cin[j], rech_cin[0]) == 0)
        {
            i = j;
            return i;
        }
    }
    return i;
}
void operation()
{
    float nouv_montant;
    int re;
    printf("\nChoisir l'operation : \n");
    printf("\n\t\t 1)Retrait");
    printf("\n\t\t 2) Depot\n");
    int choix;
    printf("Saisir votre choix : \n");
    scanf("%d", &choix);

    switch (choix)
    {
    case 1:
        printf("\n\t\t 1)Retrait\t\n");

        re = recherche();
        if (re != -1)
        {
            printf("\n\tvous etes inscrit\n");
            printf("\n\tt_cin[%d]=%s", re, t_cin[re]);

            printf("\n\tEntrez le montant a retirez  :\n\t");
            scanf("%f", &nouv_montant);
            if (t_montant[re] >= nouv_montant)
            {
                t_montant[re] = t_montant[re] - nouv_montant;
                printf("\n\tNouveau montant %f : \n", t_montant[re]);
            }
            else
            {
                printf("\n\tsolde insuffisant : \n");
            }
        }
        else
        {
            printf("\n\tvous n'etes  pas inscrit\n");
        }
        break;
    case 2:
        printf("\n\t\t 1)Depot\t\n");
        re = recherche();
        if (re != -1)
        {
            printf("\n\tvous etes inscrit\n");
            printf("\n\tt_cin[%d]=%s", re, t_cin[re]);

            printf("\n\tEntrez le montant a ajouter :\n\t");
            scanf("%f", &nouv_montant);

            t_montant[re] = t_montant[re] + nouv_montant;
            printf("\n\tNouveau montant %f : \n", t_montant[re]);
        }
        else
        {
            printf("\n\tvous n'etes  pas inscrit\n");
        }
        break;
    }
    int a;
    printf("voulez vous retourner au menu  : \n");
    printf("1) OUI \t 2) NON \n");
    scanf("%d", &a);
    if (a == 1)
    {
        retourner();
    }
    else
    {
        printf(" quiter l'operation ");
    }
}
void trierA(float test[1000])
{
    int i, j;
    float tmp;
    for (i = 0; i < p - 1; i++)
    {
        for (j = i + 1; j < p; j++)
        {
            if (test[i] > test[j])
            {
                tmp = test[i];
                test[i] = test[j];
                test[j] = tmp;
                //copy NOM
                strcpy(rech_cin[0], t_nom[i]);
                strcpy(t_nom[i], t_nom[j]);
                strcpy(t_nom[j], rech_cin[0]);
                //copy prenom
                strcpy(rech_cin[0], t_prenom[i]);
                strcpy(t_prenom[i], t_prenom[j]);
                strcpy(t_prenom[j], rech_cin[0]);
                //copy cin
                strcpy(rech_cin[0], t_cin[i]);
                strcpy(t_cin[i], t_cin[j]);
                strcpy(t_cin[j], rech_cin[0]);
            }
        }
    }
    printf(" \n");
    printf(" affichage Par Ordre Ascendant \n");
    for (i = 0; i < p; i++)
    {
        printf("%f\t", test[i]);
    }
}
void trierD(float test[1000])
{
    int i, j;
    float tmp;
    for (i = 0; i < p - 1; i++)
    {
        for (j = i + 1; j < p; j++)
        {
            if (test[i] < test[j])
            {
                tmp = test[i];
                test[i] = test[j];
                test[j] = tmp;
                //copy NOM
                strcpy(rech_cin[0], t_nom[i]);
                strcpy(t_nom[i], t_nom[j]);
                strcpy(t_nom[j], rech_cin[0]);
                //copy prenom
                strcpy(rech_cin[0], t_prenom[i]);
                strcpy(t_prenom[i], t_prenom[j]);
                strcpy(t_prenom[j], rech_cin[0]);
                //copy cin
                strcpy(rech_cin[0], t_cin[i]);
                strcpy(t_cin[i], t_cin[j]);
                strcpy(t_cin[j], rech_cin[0]);
            }
        }
    }
    printf(" \n");
    printf(" affichage Par Ordre Descendant \n");
    for (i = 0; i < p; i++)
    {
        printf("%f\t", test[i]);
    }
}
void chiff_trierA(float test[1000])
{
    float montant;
    printf("\n\t\tentrez le montant pour afficher les comptes bancaires ayant un montant superieur a  : ");
    scanf("%f", &montant);
    int i, j;
    float tmp;
    for (i = 0; i < p - 1; i++)
    {
        for (j = i + 1; j < p; j++)
        {
            if (test[i] > test[j])
            {
                tmp = test[i];
                test[i] = test[j];
                test[j] = tmp;
                //copy NOM
                strcpy(rech_cin[0], t_nom[i]);
                strcpy(t_nom[i], t_nom[j]);
                strcpy(t_nom[j], rech_cin[0]);
                //copy prenom
                strcpy(rech_cin[0], t_prenom[i]);
                strcpy(t_prenom[i], t_prenom[j]);
                strcpy(t_prenom[j], rech_cin[0]);
                //copy cin
                strcpy(rech_cin[0], t_cin[i]);
                strcpy(t_cin[i], t_cin[j]);
                strcpy(t_cin[j], rech_cin[0]);
            }
        }
    }
    printf(" \n");
    printf(" afficher les comptes bancaires ayant un montant superieur  a le  montant entree   : \n");
    for (i = 0; i < p; i++)
    {
        if (test[i] > montant)
        {
            printf("%f\t\n", test[i]);
        }
    }
}
void chiff_trierD(float test[1000])
{
    float montant;
    printf("\n\t\tentrez le montant pour afficher les comptes bancaires ayant un montant superieur a  : ");
    scanf("%f", &montant);
    int i, j;
    float tmp;
    for (i = 0; i < p - 1; i++)
    {
        for (j = i + 1; j < p; j++)
        {
            if (test[i] < test[j])
            {
                tmp = test[i];
                test[i] = test[j];
                test[j] = tmp;
                //copy NOM
                strcpy(rech_cin[0], t_nom[i]);
                strcpy(t_nom[i], t_nom[j]);
                strcpy(t_nom[j], rech_cin[0]);
                //copy prenom
                strcpy(rech_cin[0], t_prenom[i]);
                strcpy(t_prenom[i], t_prenom[j]);
                strcpy(t_prenom[j], rech_cin[0]);
                //copy cin
                strcpy(rech_cin[0], t_cin[i]);
                strcpy(t_cin[i], t_cin[j]);
                strcpy(t_cin[j], rech_cin[0]);
            }
        }
    }
    printf(" \n");
    printf(" afficher les comptes bancaires ayant un montant superieur  a le  montant entree   : \n");
    for (i = 0; i < p; i++)
    {
        if (test[i] > montant)
        {
            printf("%f\t\n", test[i]);
        }
    }
}

void affichage()
{
    printf("\nChoisir le type d'affichage : \n");
    printf("\n\t\t 1)affichage Ascendant\n");
    printf("\n\t\t 2)affichage Descendant\n");
    printf("\n\t\t 3)affichage Ascendant(les comptes bancaires ayant un montant superieur à un chiffre introduit)\n");
    printf("\n\t\t 4)affichage Descendant(les comptes bancaires ayant un montant superieur à un chiffre introduit)\n");
    int choix;
    printf("Saisir votre choix : \n");
    scanf("%d", &choix);
    switch (choix)
    {
    case 1:
        trierA(t_montant);
        break;
    case 2:
        trierD(t_montant);
        break;
    case 3:
        chiff_trierA(t_montant);
        break;
    case 4:
        chiff_trierD(t_montant);
        break;
    }
    int a;
    printf("\nvoulez vous retourner au menu  : \n");
    printf("1) OUI \t 2) NON \n");
    scanf("%d", &a);
    if (a == 1)
    {
        retourner();
    }
}
void fedilisation(float fidel[1000])
{
    int i, j;
    float tmp;
    for (i = 0; i < p - 1; i++)
    {
        for (j = i + 1; j < p; j++)
        {
            if (fidel[i] < fidel[j])
            {
                tmp = fidel[i];
                fidel[i] = fidel[j];
                fidel[j] = tmp;
            }
            //copy NOM
            strcpy(rech_cin[0], t_nom[i]);
            strcpy(t_nom[i], t_nom[j]);
            strcpy(t_nom[j], rech_cin[0]);
            //copy prenom
            strcpy(rech_cin[0], t_prenom[i]);
            strcpy(t_prenom[i], t_prenom[j]);
            strcpy(t_prenom[j], rech_cin[0]);
            //copy cin
            strcpy(rech_cin[0], t_cin[i]);
            strcpy(t_cin[i], t_cin[j]);
            strcpy(t_cin[j], rech_cin[0]);
        }
    }
    for (i = 0, j=0; i < p; i++)
    {
        if (j < 3)
        {
            if (fidel[i] == fidel[i+1])
            {
                fidel[i] = fidel[i] + (fidel[i] * 0.013);
                printf("%f\t\n", fidel[i]);
            }else
            {
                fidel[i] = fidel[i] + (fidel[i] * 0.013);
                printf("%f\t\n", fidel[i]);
                j++;
            }
        }
    }
    int a;
    printf("\nvoulez vous retourner au menu  : \n");
    printf("1) OUI \t 2) NON \n");
    scanf("%d", &a);
    if (a == 1)
    {
        retourner();
    }
    else
    {
        printf(" quiter l'operation ");
    }
}

void retourner()
{
    printf("choisir dans le menu suivant \n");
    int choix;
    menu();
    printf("\nsaisir votre choix  : \t");
    scanf("%d", &choix);
    switch (choix)
    {
    case 1:
        choixcompte();
        break;
    case 2:
        operation();
        break;
    case 3:
        affichage();
        break;
    case 4:
        fedilisation(t_montant);
        break;
    case 0:
        break;
    }
}

int main()
{
    printf("------------- APPLICATION GESTION BANCAIRE ------------- \n");
    printf("\t ---------- MENU PRINCIPAL ----------\n");
    printf("\n");
    retourner();

    return 0;
}