#include <stdio.h>
#include<stdlib.h>
#include <string.h>

#define MAX_ETUDIANTS 100
char listeDeDepart[3][9]={"physique" , "math" , "chimie"};
typedef struct {
    int num;
    char nom[50];
    char prenom[50];
    char date_naissance[11];
    char departement[9];
   float note_generale;
} Etudiant;

Etudiant etudiants[100];
int nbr_etud = 9;
//Fonction ajouter etudiant
void ajouter_etudiant() {
     
    if (nbr_etud >= MAX_ETUDIANTS) {
        printf("La liste d'etudiants est pleine!\n");

    }else{
    
    Etudiant e;
    int deptNum;
    e.num = nbr_etud+1;
    printf("Numero unique attribue: %d\n", e.num);
    printf("Entrez le nom: ");
    scanf("%s",e.nom);
    printf("Entrez le prenom: ");
    scanf("%s", e.prenom);
    printf("Entrez la date de naissance (jj/mm/aaaa): ");
    scanf("%s", e.date_naissance);
    printf("Entrez le departement ( 1-physique, 2-math, 3-chimie): ");
    scanf("%d",&deptNum);
    strcpy(e.departement , listeDeDepart[deptNum-1]);
    printf("Entrez la note generale: ");
    scanf("%f", &e.note_generale);
    etudiants[nbr_etud] = e;
    nbr_etud++;
    printf("etudiant ajoute avec succes!\n");
    }
}
//Fonction afficher un etudiant AVec numero
void afficher_etudiant(int numero) {
    int tr=0;
    for(int i=0;i< nbr_etud;i++){
        if(etudiants[i].num == numero){
            printf("Numero: %d \n", etudiants[i].num);
            printf("Nom: %s\n", etudiants[i].nom);
            printf("Prenom: %s\n", etudiants[i].prenom);
            printf("Date de naissance: %s\n", etudiants[i].date_naissance);
            printf("Departement: %s\n", etudiants[i].departement);
            printf("Note generale: %.2f\n", etudiants[i].note_generale);
            tr=1;
            break;
            if (!tr) {
        printf("aucun etudiant avec ce numero\n");
    }
}
    }
    }
//Fonction afficher un etudiant
void afficher_etudiant2(Etudiant e) {
    
            printf("Numero: %d \n", e.num);
            printf("Nom: %s\n", e.nom);
            printf("Prenom: %s\n", e.prenom);
            printf("Date de naissance: %s\n", e.date_naissance);
            printf("Departement: %s\n", e.departement);
            printf("Note generale: %.2f\n", e.note_generale);
            
       
    }
//Fonction modifier les informations   d'un etudiant
void modifier_etudiant(int numero) {
    for (int i = 0; i < nbr_etud; i++) {
        if (etudiants[i].num == numero) {
            printf("Modifier les informations de l'etudiant:\n");
            printf("Entrez le nom (actuel : %s): ", etudiants[i].nom);
            scanf("%s", etudiants[i].nom);
            printf("Entrez le prenom (actuel : %s): ", etudiants[i].prenom);
            scanf("%s", etudiants[i].prenom);

            printf("Entrez la date de naissance (jj/mm/aaaa) (actuelle : %s): ", etudiants[i].date_naissance);
            scanf("%s", etudiants[i].date_naissance);
            printf("Choisissez un nouveau departement:\n");
            for (int j = 0; j < 3; j++) {
                printf("%d - %s\n", j + 1, listeDeDepart[j]);
            }
            int deptNum;
            printf("Entrez le numero du nouveau departement: ");
            scanf("%d", &deptNum);
            if (deptNum >= 1 && deptNum <= 3) {
                strcpy(etudiants[i].departement, listeDeDepart[deptNum - 1]);
                printf("Departement modifie avec succes!\n");
            } else {
                printf("Numero de departement invalide!\n");
            }
            printf("Entrez la note generale (actuelle : %.2f): ", etudiants[i].note_generale);
            scanf("%f", &etudiants[i].note_generale);

        }
    }

}
//Fonction pour supprimer un etudiant
void supprimer_etudiant(int numero) {
    int tr=0;
    for (int i = 0; i < nbr_etud; i++) {
        if (etudiants[i].num == numero) {
            afficher_etudiant(numero);
            char confirmation;
            printf("Voulez-vous vraiment supprimer cet etudiant ? (1 pour Oui / 0 pour Non) : ");
            scanf(" %c", &confirmation);

            if (confirmation == '1') {
                for (int j = i; j < nbr_etud - 1; j++) {
                    etudiants[j] = etudiants[j + 1];
                }
                nbr_etud--;
                printf("L'etudiant a ete supprime.\n");
            } else {
                printf("Suppression rejetee.\n");
            }
        tr=1;
        break;
    }
}
}
//Afficher Tous les etudiants
void affichertousEtu() {
     for(int i=0;i< nbr_etud;i++){
            printf("Numero: %d \n", etudiants[i].num);
            printf("Nom: %s\n", etudiants[i].nom);
            printf("Prenom: %s\n", etudiants[i].prenom);
            printf("Date de naissance: %s\n", etudiants[i].date_naissance);
            printf("Departement: %s\n", etudiants[i].departement);
            printf("Note generale: %.2f\n", etudiants[i].note_generale);
        }
    }
//calculer la moyenne de chaque departement
void calculer_moydept() {
    float somme[3] = {0};
    int count[3] = {0};
    for (int i = 0; i < nbr_etud; i++) {
        for (int j = 0; j < 3; j++) {
            if (strcmp(etudiants[i].departement, listeDeDepart[j]) == 0) {
                somme[j] += etudiants[i].note_generale;
                count[j]++;
                break;
            }
        }
    }
    for (int j = 0; j < 3; j++) {
        if (count[j] > 0) {
            printf("Moyenne generale pour le departement %s: %.2f\n", listeDeDepart[j], somme[j] / count[j]);
        } else {
            printf("Aucun etudiant dans le departement %s.\n", listeDeDepart[j]);
        }
    }
}
//Calculer le moyenne de l'universite
void calculer_moyuniv() {
    if (nbr_etud == 0) {
        printf("Aucun etudiant inscrit.\n");

    }else{
    float s = 0;
    for (int i = 0; i < nbr_etud; i++) {
        s += etudiants[i].note_generale;
    }
    printf("La moyenne generale de l'universite est de %.2f\n", s / nbr_etud);
}
}
//Affichage des etudiants inscrits
void afficher_etu_inscr(){
    printf("Nombre total d'etudiants inscrits: %d\n", nbr_etud);
}
void afficher_nbr_etudep() {
    int count = 0;
    int x;

    printf("Entrez le departement ( ( 1-physique, 2-math, 3-chimie)): ");
    scanf("%d", &x);
    for (int i = 0; i < nbr_etud; i++) {
        if (strcmp(etudiants[i].departement, listeDeDepart[x-1]) == 0) {
           count ++;

        }
    }
        printf("Nombre d'etudiants dans le departement %s: %d\n", listeDeDepart[x - 1], count);

}
//Afficher les  3 etudiants ayant une meilleure note
void afficher_etu_meilleurnote() {
    int i, j;
    Etudiant temp;

    // Tri des étudiants par note décroissante
    for (i = 0; i < nbr_etud - 1; i++) {
        for (j = i + 1; j < nbr_etud; j++) {
            if (etudiants[i].note_generale < etudiants[j].note_generale) {
                temp = etudiants[i];
                etudiants[i] = etudiants[j];
                etudiants[j] = temp;
            }
        }
    }

    printf("Les 3 etudiants ayant les meilleures notes:\n");
    for (i = 0; i < 3 && i < nbr_etud; i++)
    {
     afficher_etudiant(etudiants[i].num);


    }
        }



//Afficher les etudiants ayant une moyenne superieure à un seuil
void afficher_etud_moy_sup() {
    float seuil;
    int tr = 0;

    printf("Entrez le seuil de la moyenne generale: ");
    scanf("%f", &seuil);

    printf("etudiants ayant une moyenne generale superieure a %.2f:\n", seuil);

    for (int i = 0; i < nbr_etud; i++) {
        if (etudiants[i].note_generale > seuil) {
         afficher_etudiant(etudiants[i].num);

            tr++;
        }
    }


    if (tr == 0) {
        printf("Aucun etudiant n'a une moyenne generale superieure à %.2f\n", seuil);
    }
}

//Afficher les etudiants reussi dans chaque departement
void afficher_nbr_etud_reus() {
    int count = 0;
    for (int i = 0; i < nbr_etud; i++) {
        if (etudiants[i].note_generale >= 10.0) {
            count++;
        }
    }
    printf("Nombre d'etudiants ayant reussi: %d\n", count);
}
//Rechercher par le nom
void rechercher_nom() {
    char nom_rechercher[50];
    printf("Entrez le nom de l'etudiant a rechercher: ");
    scanf("%s", nom_rechercher);

    for (int i = 0; i < nbr_etud; i++) {
        if (strcmp(etudiants[i].nom, nom_rechercher) == 0) {
         afficher_etudiant2(etudiants[i]);
        }
    }
}
//tri par nom
void trier_etud_nom(int ordre) {
    int i, j;
    Etudiant temp;
    for (i = 0; i < nbr_etud - 1; i++) {
        for (j = i + 1; j < nbr_etud; j++) {
            if ((ordre == 1 && strcmp(etudiants[i].nom, etudiants[j].nom) > 0) ||
                (ordre == 2 && strcmp(etudiants[i].nom, etudiants[j].nom) < 0)) {
                temp = etudiants[i];
                etudiants[i] = etudiants[j];
                etudiants[j] = temp;
            }
        }
    }
    printf("etudiants tries par nom.\n");
    affichertousEtu();
}
//tri par moyenne
void trier_etud_moy(int ordre) {
    int i, j;
    Etudiant temp;
    for (i = 0; i < nbr_etud - 1; i++) {
        for (j = i + 1; j < nbr_etud; j++) {
            if ((ordre == 1 && etudiants[i].note_generale < etudiants[j].note_generale) ||
                (ordre == 2 && etudiants[i].note_generale > etudiants[j].note_generale)) {
                temp = etudiants[i];
                etudiants[i] = etudiants[j];
                etudiants[j] = temp;
            }
        }
    }
    printf("Etudiants tries par moyenne.\n");
    affichertousEtu();
}
//tri par statut de reussite1
void trier_statut_reu() {
    int i, j;
    Etudiant temp;
    for (i = 0; i < nbr_etud - 1; i++) {
        for (j = i + 1; j < nbr_etud; j++) {
            if (etudiants[i].note_generale < 10 && etudiants[j].note_generale >= 10) {
                temp = etudiants[i];
                etudiants[i] = etudiants[j];
                etudiants[j] = temp;
            }
        }
    }

    printf("Etudiants tries par statut de reussite.\n");
    affichertousEtu();
}
//tri par statut de reussite1
/*void trier_statut_reu2() {
    Etudiant reu[MAX_ETUDIANTS];
    Etudiant  non_reu[MAX_ETUDIANTS];
    int count_reu = 0, count_non_reu = 0;
    for (int i = 0; i < nbr_etud; i++) {
        if (etudiants[i].note_generale >= 10) {
            reu[count_reu++] = etudiants[i];
        } else {
            non_reu[count_non_reu++] = etudiants[i];
        }
    }
    trier_etud_moy(reu,count_reu,1);
    printf("Etudiants reussis tries par moyenne:\n");
    affichertousEtu(reu, count_reu);
    printf("Etudiants non reussis:\n");
    affichertousEtu(non_reu, count_non_reu);
}*/

void quitter() {
    printf("Merci d'avoir utilise le gestionnaire des etudiants.\n");
    exit(0);  // Quitte le programme avec un code de succès
}

int main() {
    int choix;
    int num;
    float seuil;
    etudiants[0] = (Etudiant){1, "CHETTIR", "Meriem", "12/04/1998", "physique", 15.5};
    etudiants[1] = (Etudiant){2, "ALAMI", "Ahmed", "08/06/2000", "math", 12.3};
    etudiants[2] = (Etudiant){3, "HAMZAOUI", "Mourad", "23/11/1999", "chimie", 17.0};
    etudiants[3] = (Etudiant){4, "BICHRI", "Mourad", "23/10/1995", "chimie", 9.0};
    etudiants[4] = (Etudiant){5, "CHAOUIQi", "Soufiane", "12/11/2001", "math", 11.0};
    etudiants[5] = (Etudiant){6, "ZALZOULI", "ACHRAF", "10/05/2002", "physique", 10.0};
    etudiants[6] = (Etudiant){7, "BOUDARBALA", "Mounir", "15/11/2003", "math", 18.0};
    etudiants[7] = (Etudiant){8, "ESSMAILI", "Noura", "15/01/2000", "physique", 14.5};
    etudiants[8] = (Etudiant){9, "HAMZAOUI", "SOUMIA", "23/11/2001", "physique", 15.0};

    do {
 printf("\nMenu Principal:\n");
    printf("1.  Ajouter un etudiant\n");
    printf("2.  Afficher les details d'un etudiant\n");
    printf("3.  Afficher tous les etudiants\n");
    printf("4.  Calculer la nombre des etudiants inscrits\n");
    printf("5.  Modifier un etudiant\n");
    printf("6.  Supprimer un etudiant\n");
    printf("7.  Calculer la moyenne generale de chaque departement\n");
    printf("8.  Calculer la moyenne generale de toute universite\n");
    printf("9.  Afficher le nombre d'etudiants par departement\n");
    printf("10. Afficher les etudiants ayant les meilleures notes\n");
    printf("11. Afficher les etudiants ayant une moyenne generale superieure a un certain seuil\n");
    printf("12. Afficher le nombre d'etudiants ayant reussi\n");
    printf("13. Rechercher un etudiant par nom\n");
    printf("14. Trier les etudiants par nom\n");
    printf("15. Trier les etudiants par moyenne generale\n");
    printf("16. Trier les etudiants par Statut de reussite\n");
    printf("17. Quitter\n");
    printf("Quelle est votre choix:\n ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouter_etudiant();
                break;
            case 2:
            printf("Entrez le numero de l'etudiant a afficher: ");
            scanf("%d", &num);
            afficher_etudiant(num);
                        break;
            case 3:
                affichertousEtu();
                break;
            case 4:
                   afficher_etu_inscr();
                   break;
            case 5:
                printf("Entrez le numero de l'etudiant a modifier: ");
                scanf("%d", &num);
                modifier_etudiant(num);
                break;
            case 6:
                printf("Entrez le numero de l'etudiant a supprimer: ");
                scanf("%d", &num);
                supprimer_etudiant(num);
                break;
             case 7:
                   calculer_moydept();
                   break;
            case 8:
                calculer_moyuniv();
                break;

            case 9:
                afficher_nbr_etudep();
                break;
            case 10:
            afficher_etu_meilleurnote();
             break;
            case 11:
                afficher_etud_moy_sup(&seuil);
                 break;
            case 12:
                afficher_nbr_etud_reus();
                break;
            case 13:
                rechercher_nom();
                break;
            case 14: {
                int ordre;
                printf("Choisissez l'ordre de tri (1 = A-Z, 2 = Z-A): ");
                scanf("%d", &ordre);
              trier_etud_nom(ordre);
                break;
            }
            case 15: {
                int ordre;
                printf("Choisissez l'ordre de tri (1 = du plus eleve au plus faible, 2 = du plus faible au plus eleve): ");
                scanf("%d", &ordre);
                trier_etud_moy(ordre);
                break;
            }
            case 16:
                trier_statut_reu();
                break;
            case 17:
                quitter();
                break;
            default:
                printf("Option invalide, veuillez reessayer.\n");
        }
    } while (choix != 0);

    return 0;
}