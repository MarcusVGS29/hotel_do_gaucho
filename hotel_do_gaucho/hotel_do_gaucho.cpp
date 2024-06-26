#include <iostream>
#include <vector>
#include <string>
#include "includes/calculations.h"
#include <algorithm>
using namespace std;

int main() {
    char option;
    vector<vector<string>> hotel(9, vector<string>(4)); //creation de vector pour l'hotel

    // Initialisation des chambres
    int ncham = 101;
    for (int i = 0; i < 9; ++i) {

        hotel[i][0] = to_string(ncham); 
        hotel[i][1] = "-";
        hotel[i][2] = "-";
        hotel[i][3] = "Non";
        ncham++;
    }
    /*cout << "\nHotel du Gaucho - Etage 1\n";
    for (int i = 0; i < 9; ++i) {
        cout << "Chambre: " << hotel[i][0] << ", " << hotel[i][1] << hotel[i][2] << " " << hotel[i][3] << endl;

    }*/
    do {
        cout <<"\nHotel du Gaucho.\nOu vous vivrez des experiences du sud du Bresil.";
        cout << "\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n";
        cout << "Menu des Options:" << endl;
        cout << "1. Creer une reservation." << endl;
        cout << "2. Annuler une reservation." << endl;
        cout << "3. Changer le proprietaire de la reservation." << endl;
        cout << "4. Changer la reservation de la chambre." << endl;
        cout << "5. Afficher les chambres reservees." << endl;
        cout << "6. Trouver une reservation." << endl;
        cout << "7. Echanger chambres." << endl;
        cout << "8. Trier las reservations." << endl;
        cout << "9. Statistique (% de chambres occupes)." << endl;
        cout << "0. Quitter." << endl;

        cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-";

        cout << "\nEntrez le numero de l'option souhaitee: ";
        cin >> option;
        cout << "\n";
        
        if (option == '0') {
            string resposta;
            cout << "Etes-vous sur de vouloir quitter?? (oui/non): ";
            cin >> resposta;

            if (resposta == "oui" || resposta == "OUI") {
                // Confirma a saida
                option = 0; // aqui nao precisa fazer mais nada, pois ja confirmou a saida.
            }
            else if (resposta == "non" || resposta == "NON") {
                // aqui, caso se arrependa de sair
                cout << "\nVous serez a nouveau dirige vers le menu principal.\n\n";
                system("pause");
                option = 10; // entra na opção 10 que é invisivel, so com o break.
            }
            else{
                cout << "\nOption invalide. \n\nVous serez a nouveau dirige vers le menu principal.\n\n";
                option = 10;
                system("pause");
            }
        }
        system("cls");
        

        switch (option) {
        case '1':
            cout << "Creer une reservation " << endl;
            creation(hotel);
            cout << endl;

            system("pause");
            system("cls");
            
            break;

        case '2':
            cout << "Annuler reservation." << endl;
            annulation(hotel);
            cout << endl;
            system("pause");
            system("cls");

            break;

        case '3':
            cout << "Modifier la reservation" << endl;
            chanres(hotel);
            cout << endl;
            system("pause");
            system("cls");

            break;

        case '4':
            cout << "Modifier client de chambre" << endl;
            changechambre(hotel);
            cout << endl;

            system("pause");
            system("cls");

            break;

        case '5':
            
            cout << "Liste des chambres" << endl;
            liste(hotel);

            system("pause");            

            break;

        case '6':
            
            cout << "Trouver une reservation" << endl;
            trouver(hotel);
            cout << endl;

            system("pause");
            system("cls");

            break;

        case '7':
            
            cout << "Echanger les chambres des reservations" << endl;
            echanResChambres(hotel);
            cout << endl;

            system("pause");
            system("cls");

            break;
        case '8':
            
            cout << "Trier pour une reservation" << endl;
            croissantDecroissant(hotel);
            cout << endl;

            system("pause");
            system("cls");

            break;
        case '9':
            
            cout << "Statistique de chambres " << endl;
            statsRes(hotel);
            cout << endl;
            system("pause");
            system("cls");

            break;
            
        case 10: //Cette option a été créée pour que, lorsqu'il y a une erreur dans le menu, 
                 //le programme soit dirigé ici et revienne ensuite au menu principal.
            break;

        case 0:
            cout << "\nQuitter le programme.\n";
            cout << "\nMerci pour utiliser notre system de gestion.\n";
            cout << "\nSi vous avez des questions, veuillez contacter le DEV responsable.\n\n";
            
            break;
        default:
            cout << "\nOption invalide. Essayer a nouveau.\n";
            break;
        }
    } while (option != 0);

    return 0;
}


