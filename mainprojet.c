#include <stdio.h>
#include <stdlib.h>
#include "Formes/structure.h"
#include "Formes/Liste/liste.h"
#include "Formes/Create/create.h"
#define RED "\033[31m"
#define RESET "\033[0m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"

int main(void)
{
    Liste *liste = create_liste();
    
    printf(BLUE "\n╔════════════════════════════════════════╗\n" RESET);
    printf(BLUE "║    Bienvenue dans l'éditeur SVG !     ║\n" RESET);
    printf(BLUE "╚════════════════════════════════════════╝\n" RESET);
    
    while (1) {
        menu_principal();
        int choix = getint(0, 4);
        
        switch (choix) {
            case 0:
                printf(YELLOW "\nAu revoir! 👋\n" RESET);
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
                
            case 4:
                supprimer_forme(liste);
                break;
                
            default:
                printf(RED "Choix invalide! Réessaie.\n" RESET);
                break;
        }
    }
    
    return 0;
}


//yokoso watashi no soul soceity