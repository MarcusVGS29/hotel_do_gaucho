
#include <iostream>
#include <vector>
#include <string>
using namespace std;


bool creation(vector<vector<string> >& hotel);

void annulation(vector<vector<string> >& hotel);

void chanres(vector< vector<string> >& hotel);

void changechambre(vector< vector<string> >& hotel);

void liste(vector< vector<string> >& hotel);

void trouver(vector< vector<string> >& hotel);

void echanResChambres(vector< vector<string> >& hotel);

bool CroissantNom(const vector<string>& nom1, const vector<string>& nom2);

bool DecroissantNom(const vector<string>& nom1, const vector<string>& nom2);

bool CroissantPrenom(const vector<string>& prenom1, const vector<string>& prenom2);

bool DecroissantPrenom(const vector<string>& prenom1, const vector<string>& prenom2);

bool CroissantChambre(const vector<string>& cham1, const vector<string>& cham2);

void croissantDecroissant(vector<vector<string>>& hotel);

void statsRes(vector< vector<string> >& hotel);