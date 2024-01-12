#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIVRES 50
#define MAX_UTILISATEURS 50


struct Livre {
    char titre[50];
    char auteur[50];
    int disponible;
};


struct Utilisateur {
    char nom[50];
    int id;
    int livreEmprunte;
};


void voirLivres(struct Livre *livres, int nbLivres) {
    printf("Liste des livres:\n");
    for (int i = 0; i < nbLivres; i++) {
        printf("%d. %s par %s - %s\n", i + 1, livres[i].titre, livres[i].auteur,
               livres[i].disponible ? "Disponible" : "Emprunte");
    }
    printf("\n");
}

void voirUtilisateurs(struct Utilisateur *utilisateurs, int nbUtilisateurs) {
    printf("Liste des utilisateurs:\n");
    for (int i = 0; i < nbUtilisateurs; i++) {
        printf("%d. %s\n", i + 1, utilisateurs[i].nom);
    }
    printf("\n");
}

void emprunterLivre(struct Livre *livres, int nbLivres, struct Utilisateur *utilisateurs, int nbUtilisateurs) {
    int idLivre, idUtilisateur;

    voirLivres(livres, nbLivres);
    printf("Entrez l'ID du livre que vous souhaitez emprunter: ");
    scanf("%d", &idLivre);

    if (idLivre < 1 || idLivre > nbLivres || !livres[idLivre - 1].disponible) {
        printf("Livre non disponible ou ID invalide.\n");
        return;
    }

    voirUtilisateurs(utilisateurs, nbUtilisateurs);
    printf("Entrez l'ID de l'utilisateur qui emprunte le livre: ");
    scanf("%d", &idUtilisateur);

    if (idUtilisateur < 1 || idUtilisateur > nbUtilisateurs) {
        printf("ID utilisateur invalide.\n");
        return;
    }

    livres[idLivre - 1].disponible = 0;
    utilisateurs[idUtilisateur - 1].livreEmprunte = idLivre;

    printf("Livre emprunte avec succes!\n");
}


void retournerLivre(struct Livre *livres, int nbLivres, struct Utilisateur *utilisateurs, int nbUtilisateurs) {
    int idUtilisateur;

    voirUtilisateurs(utilisateurs, nbUtilisateurs);
    printf("Entrez l'ID de l'utilisateur qui retourne le livre: ");
    scanf("%d", &idUtilisateur);

    if (idUtilisateur < 1 || idUtilisateur > nbUtilisateurs || utilisateurs[idUtilisateur - 1].livreEmprunte == 0) {
        printf("Aucun livre emprunte par cet utilisateur ou ID invalide.\n");
        return;
    }

    int idLivreEmprunte = utilisateurs[idUtilisateur - 1].livreEmprunte;

    livres[idLivreEmprunte - 1].disponible = 1;
    utilisateurs[idUtilisateur - 1].livreEmprunte = 0;

    printf("Livre retourne avec succes!\n");
}

int main() {
    struct Livre livres[MAX_LIVRES];
    struct Utilisateur utilisateurs[MAX_UTILISATEURS];
    int choix, nbLivres = 0, nbUtilisateurs = 0;


    strcpy(livres[nbLivres].titre, "Le Seigneur des Anneaux");
    strcpy(livres[nbLivres].auteur, "J.R.R. Tolkien");
    livres[nbLivres].disponible = 1;
    nbLivres++;

    strcpy(livres[nbLivres].titre, "1984");
    strcpy(livres[nbLivres].auteur, "George Orwell");
    livres[nbLivres].disponible = 1;
    nbLivres++;

    strcpy(livres[nbLivres].titre, "Harry Potter à l'école des sorciers");
    strcpy(livres[nbLivres].auteur, "J.K. Rowling");
    livres[nbLivres].disponible = 1;
    nbLivres++;

    do {
        printf("Menu:\n");
        printf("1. Voir les livres\n");
        printf("2. Voir les utilisateurs\n");
        printf("3. Emprunter un livre\n");
        printf("4. Retourner un livre\n");
        printf("5. Quitter\n");
        printf("Choix: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                voirLivres(livres, nbLivres);
                break;
            case 2:
                voirUtilisateurs(utilisateurs, nbUtilisateurs);
                break;
            case 3:
                emprunterLivre(livres, nbLivres, utilisateurs, nbUtilisateurs);
                break;
            case 4:
                retournerLivre(livres, nbLivres, utilisateurs, nbUtilisateurs);
                break;
            case 5:
                printf("Au revoir!\n");
                break;
            default:
                printf("Choix invalide. Veuillez entrer un nombre entre 1 et 5.\n");
        }
    } while (choix != 5);

    return 0;
}
