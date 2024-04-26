#include <iostream>
#include <vector>
#include "calculations.h"
using namespace std;

bool creation(vector< vector<string> >& hotel) {
    string ncham, nom, prenom;
    cout << "Tapez le numero du chambre: ";
    cin >> ncham;
    cout << "Tapez le nom du client: ";
    cin >> nom;
    cout << "Tapez le prenom du client: ";
    cin >> prenom;

    for (int i = 0; i < 9; i++) {
        if (hotel[i][0] == ncham) {
            if (hotel[i][3] == "Non") {
                hotel[i][1] = nom;
                hotel[i][2] = prenom;
                hotel[i][3] = "Oui";
                cout << "\nReservation faite au nom de " << prenom << " " << nom << ", en chambre " << ncham << "." << endl;
                return true;
            }
            else {
                cout << "\nChoisissez une autre chambre, car la " << ncham << " est deje occupee ou en cours de maintenance.\n" << endl;
                return false;
            }
        }
    }
    cout << "\nRefaites l'operation, car le numero de chambre choisi n'est pas valide." << "\n\n";
    return false;
}



void annulation(vector< vector<string> >& hotel) {
    string nucham;
    cout << "Entrez le numero de la chambre qui sera annulee: ";
    cin >> nucham;

    for (int i = 0; i < 9; i++) {
        if (hotel[i][0] == nucham) {
            hotel[i][1] = "-";
            hotel[i][2] = "-";
            hotel[i][3] = "Non";

            cout << "\nReservation annulee." << "\nPour l'instant, la chambre " << nucham << " est inoccupee.\n";
            cout << "\nInformez le client par email que la reservation a ete annulee avec succes.\n";
            return;
        }
    }
}

void chanres(vector< vector<string> >& hotel) {
    string nucham, nom2, prenom2;
    cout << "Pour quelle chambre souhaitez-vous modifier la reservation ? ";
    cin >> nucham;

    for (int i = 0; i < 9; i++) {
        if (hotel[i][0] == nucham) {
            cout << "Tapez le nouveau nom de client: ";
            cin >> nom2;
            cout << "Tapez le nouveau prenom de client: ";
            cin >> prenom2;
            hotel[i][1] = nom2;
            hotel[i][2] = prenom2;
            hotel[i][3] = "Oui";

            cout << "\nLa reservation est desormais au nom de: " << prenom2 << " " << nom2 << ".\n";
            return;
        }
    }
}

void changechambre(vector< vector<string> >& hotel) {
    string cham1, cham2;
    int cham1indice = -1, cham2indice = -1;

    cout << "Tapez le numero de chambre que vous voulez changer: ";
    cin >> cham1;
    cout << "Tapez le numero de chambre que recevoir la reservation: ";
    cin >> cham2;

        for (int i = 0; i < 9; i++) {
            if (hotel[i][0] == cham1) {
                cham1indice = i;
            }
            if (hotel[i][0] == cham2) {
                cham2indice = i;
            }
        }
        if (cham1indice == -1) {
            cout << "Choisissez une chambre valide. Le chambre " << cham1 << " n existe pas." << endl;
            return;
        }
        if (cham2indice == -1) {
            cout << "Choisissez une chambre valide. Le chambre " << cham2 << " n existe pas." << endl;
            return;
        }
        if (hotel[cham2indice][3] == "Oui") {
            cout << "Choisissez une chambre valide. Le chambre " << cham2 << " est deja occupee." << endl;
            return;
        }

        hotel[cham2indice][1] = hotel[cham1indice][1];
        hotel[cham2indice][2] = hotel[cham1indice][2];
        hotel[cham2indice][3] = "Oui";

        hotel[cham1indice][1] = "-";
        hotel[cham1indice][2] = "-";
        hotel[cham1indice][3] = "Non";

        cout << "La reservation pour la chambre " << cham1 << " a ete deplacee avec succes a la chambre " << cham2 << ".\n";

}

void liste(vector< vector<string> >& hotel) {
    for (int i = 0; i < 9; ++i) {
        cout << "Chambre " << hotel[i][0] << ", " << hotel[i][1] << " " << hotel[i][2] << endl;

    }
}
void trouver(vector< vector<string> >& hotel) {
    string parcourir;
    bool trouvee = false;
    cout << "Entrez l'un des details (prenom, nom, nº chambre) valides pour rechercher la reservation: ";
    cin >> parcourir;

    for (int i = 0; i < 9; i++) {
        string nom = hotel[i][1];
        string prenom = hotel[i][2];
        string ncham = hotel[i][0];
        
    }
    
    if (!trouvee) {
        cout << "Reservation pour "<<parcourir<< " introuvable.\n";
    }
}