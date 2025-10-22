#include <stdio.h>
#include <stdlib.h>
#include "Formes/structure.h"
#include "Formes/Liste/liste.h"
#include "Formes/Create/create.h"
#define RED "\033[31m"
#define RESET "\033[0m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"


/**
 * @brief Point d'entrée principal du programme
 * 
 * Initialise la liste de formes et lance la boucle principale du menu.
 * L'utilisateur peut créer, afficher, modifier et supprimer des formes
 * de manière interactive. Le programme se termine proprement en libérant
 * toute la mémoire allouée.
 * 
 * @return 0 en cas de succès
 * 
 * @note La boucle continue jusqu'à ce que l'utilisateur choisisse de quitter (option 0)
 */
int main(void)
{
    Liste *liste = create_liste();
    
    printf(BLUE "\n╔════════════════════════════════════════╗\n" RESET);
    printf(BLUE "║    Bienvenue dans l'éditeur SVG !      ║\n" RESET);
    printf(BLUE "╚════════════════════════════════════════╝\n" RESET);
    
    while (1) {
        menu_principal();
        int choix = getint(0, 5);
        
        switch (choix) {
            case 0:
                printf(YELLOW "\nAu revoir !\n" RESET);
                free_liste(liste);
                return 0;
                
            case 1: {
                Shape *nouvelle_forme = creer_forme();
                if (nouvelle_forme != NULL) {
                    add_shape(liste, nouvelle_forme);
                }
                break;
            }
            
            case 2:
                display_all_shapes(liste);
                break;
                
            case 3:
                modifier_forme(liste);
                break;

            /*case 4:
                change_color(liste);
                break;
            */
            case 5:
                supprimer_forme(liste);
                break;
                
            default:
                printf(RED "Choix invalide! Réessaie.\n" RESET);
                break;
        }
    }
    
    return 0;
}