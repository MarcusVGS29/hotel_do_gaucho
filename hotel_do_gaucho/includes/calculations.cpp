#include <iostream>
#include <vector>
#include <iomanip>
#include "calculations.h"
#include <algorithm>
using namespace std;


//option 1 - pour creer une reservation
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


//option 2 - pour annuller uns reservation
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

//option 3 - pour changer  la persone quel sera le nom de la chambre.
void chanres(vector< vector<string> >& hotel) {
    string nucham, nom2, prenom2;
    cout << "Pour quelle chambre souhaitez-vous modifier la reservation? ";
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

            cout << "\n\nLa reservation de la chambre " << nucham << " est desormais au nom de : " << prenom2 << " " << nom2 << ".\n";
            return;
        }
    }
}

//option 4 - pour changer la reservation de chambre, à cause d'un problème dans la chambre.
//Seules les modifications apportées à une chambre vide seront autorisées.
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
//option 5 - lister l'état des chambres d'hôtel
void liste(vector< vector<string> >& hotel) {
    cout << setw(13) << left<<"Chambre: Num"<< setw(10) << left<<"Nom" << setw(15) << left << "Prenom" << setw(9) << left << "Reservee" << endl;
    for (int i = 0; i < 9; ++i) {
        cout << setw(4) << left<< "Chambre: " << hotel[i][0]<<" " << setw(10) << left << hotel[i][1] << setw(15) << left << hotel[i][2] << setw(9) << left << hotel[i][3] << endl;

    }
}




//option 6 - Recherchez une réservation valide ou informez-la qu'il n'y a pas de réservation.
string lowercase(string str) {
    string lowercasestr = str;
    for (char& c : lowercasestr) {
        c = tolower(c);
    }
    return lowercasestr;
}
void trouver(vector< vector<string> >& hotel) {
    bool trouve = false;
    string recherche, recherchelower;
    cout << "Pour rechercher une reservation, veuillez taper le nom ou le prenom ou la chambre: ";
    cin >> recherche;
    recherchelower = lowercase(recherche);

    cout << setw(13) << left << "\nChambre: Num" << setw(10) << left << "Nom" << setw(15) << left << "Prenom" << setw(9) << left << "Reservee\n" << endl;
    for (const auto& hotel : hotel) {
        string nomlower = lowercase(hotel[1]);
        string prenomlower = lowercase(hotel[2]);
        string chambre = lowercase(hotel[0]);
        if (nomlower == recherchelower || prenomlower == recherchelower || chambre == recherchelower) {
            cout << setw(4) << left <<"Chambre: " << hotel[0] << " " << setw(10) << left << hotel[1] << setw(15) << left << hotel[2] << setw(9) << left << hotel[3] << endl;
            trouve = true;
        }
    }
    if (!trouve) {
        cout << "Aucune reservation trouvee pour '" << recherche << "'" << endl;
    }
}

 

//option 7 - échanger de VRAIES réserves. change d'une chambre à l'autre.
void echanResChambres(vector< vector<string> >& hotel) {
    string Q1, Q2;
    bool found1 = false, found2 = false;

    cout << "Entrez la premiere chambre qui sera echangee: ";
    cin >> Q1;
    cout << "Entrez la deuxieme chambre qui sera echangee: ";
    cin >> Q2;

    // Parcourez la matrice hôtelière et trouvez les positions des deux réservations
    int t1 = -1, t2 = -1;
    for (int i = 0; i < 9; i++) {
        if (hotel[i][0] == Q1) {
            t1 = i;
            found1 = true;
        }
        if (hotel[i][0] == Q2) {
            t2 = i;
            found2 = true;
        }
        if (found1 && found2) {
            break;
        }
    }

    // Vérifiez si les deux réservations ont été trouvées
    if (!found1) {
        cout << "Reservation pour la chambre " << Q1 << " non trouvee." << endl;
        return;
    }
    if (!found2) {
        cout << "Reservation pour la chambre " << Q2 << " non trouvee." << endl;
        return;
    }

    // Stocker temporairement les premières informations de réservation
    string tempNom = hotel[t1][1];
    string tempPrenom = hotel[t1][2];
    string tempEtat = hotel[t1][3];

    // Mettre à jour la première réservation avec les informations de la deuxième réservation
    hotel[t1][1] = hotel[t2][1];
    hotel[t1][2] = hotel[t2][2];
    hotel[t1][3] = hotel[t2][3];

    // Mettre à jour la deuxième réservation avec les informations temporairement stockées
    hotel[t2][1] = tempNom;
    hotel[t2][2] = tempPrenom;
    hotel[t2][3] = tempEtat;

    cout << "Les reservations pour les chambres " << Q1 << " et " << Q2 << " ont ete echangees avec succes." << endl;

}

//Option 8 - Affiche les réservations dans l'ordre

bool CroissantNom(const vector<string>& nom1, const vector<string>& nom2) {
    return nom1[1] < nom2[1];
}

bool DecroissantNom(const vector<string>& nom1, const vector<string>& nom2) {
    return nom1[1] > nom2[1];
}

bool CroissantPrenom(const vector<string>& prenom1, const vector<string>& prenom2) {
    return prenom1[2] < prenom2[2];
}

bool DecroissantPrenom(const vector<string>& prenom1, const vector<string>& prenom2) {
    return prenom1[2] > prenom2[2];
}
bool CroissantChambre(const vector<string>& cham1, const vector<string>& cham2) {
    return cham1[0] < cham2[0];
}

void croissantDecroissant(vector<vector<string>>& hotel) {


    cout << "\nChoisir un ordre de lister les chambres. Croissant ou decroissant ?\n Tapez 'c' ou 'd': ";
    char resp;
    cin >> resp;
    cout << "\nListe par Nom ou Prenom?\n Tapez 'n' ou 'p': \n";
    char resp1;
    cin >> resp1;
    cout << setw(13) << left << "Chambre: Num" << setw(10) << left << "Nom" << setw(15) << left << "Prenom" << setw(9) << left << "Reservee" << endl;
    if ((resp == 'c' || resp == 'C') && (resp1 == 'n' || resp1 == 'N')) {
        sort(hotel.begin(), hotel.end(), CroissantNom);

        for (int i = 0; i < 9; i++) {
            cout << setw(4) << left << "Chambre: " << hotel[i][0] << " " << setw(10) << left << hotel[i][1] << setw(15) << left << hotel[i][2] << setw(9) << left << hotel[i][3] << endl;
        }

        sort(hotel.begin(), hotel.end(), CroissantChambre);
    }
    else if ((resp == 'd' || resp == 'D') && (resp1 == 'n' || resp1 == 'N')) {
        sort(hotel.begin(), hotel.end(), DecroissantNom);

        for (int i = 0; i < 9; i++) {
            cout << setw(4) << left << "Chambre: " << hotel[i][0] << " " << setw(10) << left << hotel[i][1] << setw(15) << left << hotel[i][2] << setw(9) << left << hotel[i][3] << endl;
        }

        sort(hotel.begin(), hotel.end(), CroissantChambre);
    }
    else if ((resp == 'c' || resp == 'C') && (resp1 == 'p' || resp1 == 'P')) {
        sort(hotel.begin(), hotel.end(), CroissantPrenom);

        for (int i = 0; i < 9; i++) {
            cout << setw(4) << left << "Chambre: " << hotel[i][0] << " " << setw(10) << left << hotel[i][1] << setw(15) << left << hotel[i][2] << setw(9) << left << hotel[i][3] << endl;
        }

        sort(hotel.begin(), hotel.end(), CroissantChambre);
    }
    else if ((resp == 'd' || resp == 'D') && (resp1 == 'p' || resp1 == 'P')) {
        sort(hotel.begin(), hotel.end(), DecroissantPrenom);

        for (int i = 0; i < 9; i++) {
            cout << setw(4) << left << "Chambre: " << hotel[i][0] << " " << setw(10) << left << hotel[i][1] << setw(15) << left << hotel[i][2] << setw(9) << left << hotel[i][3] << endl;
        }

        sort(hotel.begin(), hotel.end(), CroissantChambre);


    }
    else {
        cout << "Choix invalide!" << endl;

        for (const auto& reservation : hotel) {
            for (const auto& list : reservation) {
                cout << list << " ";
            }
            cout << endl;
        }
    }
}

//option 9 - Affiche, en pourcentage, le nombre de pièces occupées.
void statsRes(vector< vector<string> >& hotel) {
    int TTL = 9; // Total de chambres na matriz hotel
    int comb = 0;
    for (int i = 0; i < TTL; ++i) {
        if (hotel[i][3] == "Oui") {
            comb++;
        }
    }

    double pourcentageOccupation = (comb * 100.0) / TTL;

    cout << "Nous avons au total "<< pourcentageOccupation <<"% chambres occupees : " << endl;
}