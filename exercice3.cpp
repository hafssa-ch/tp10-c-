
#include <iostream>
#include <string>
using namespace std;

class Livre {
private:
    string titre;
    float prix;
public:
    Livre() {}
    Livre(string t, float p) {
        titre = t;
        prix = p;
    }
    void saisir() {
        cout << "Titre : ";
        getline(cin, titre);
        cout << "Prix : ";
        cin >> prix;
        cin.ignore();
    }
    void afficher() {
        cout << "Titre : " << titre << ", Prix : " << prix << " DH" << endl;
    }
};

int main() {
    int n;
    cout << "Combien de livres voulez-vous créer ? ";
    cin >> n;
    cin.ignore();

    Livre* livres = new Livre[n];

    for (int i = 0; i < n; i++) {
        cout << "\nLivre " << i + 1 << " :" << endl;
        livres[i].saisir();
    }

    cout << "\n--- Liste des livres ---" << endl;
    for (int i = 0; i < n; i++) {
        livres[i].afficher();
    }

    delete[] livres;
    return 0;
}
