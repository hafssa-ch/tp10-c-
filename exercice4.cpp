
#include <iostream>
#include <string>
using namespace std;

class Contact {
private:
    string nom;
    string telephone;
    string email;
public:
    Contact(string n = "", string t = "", string e = "") {
        nom = n;
        telephone = t;
        email = e;
    }
    string getNom() { return nom; }
    void afficher() {
        cout << "Nom : " << nom << ", Téléphone : " << telephone << ", Email : " << email << endl;
    }
};

void supprimerContact(Contact**& carnet, int& taille, string nom) {
    int index = -1;
    for (int i = 0; i < taille; i++) {
        if (carnet[i]->getNom() == nom) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Contact introuvable." << endl;
        return;
    }

    delete carnet[index];
    for (int i = index; i < taille - 1; i++) {
        carnet[i] = carnet[i + 1];
    }
    taille--;

    Contact** nouveauCarnet = new Contact*[taille];
    for (int i = 0; i < taille; i++) {
        nouveauCarnet[i] = carnet[i];
    }
    delete[] carnet;
    carnet = nouveauCarnet;

    cout << "Contact supprimé avec succès." << endl;
}

int main() {
    int taille = 0;
    Contact** carnet = nullptr;

    int choix;
    do {
        cout << "\n1. Ajouter un contact";
        cout << "\n2. Afficher tous les contacts";
        cout << "\n3. Supprimer un contact";
        cout << "\n4. Quitter";
        cout << "\nVotre choix : ";
        cin >> choix;
        cin.ignore();

        if (choix == 1) {
            string nom, tel, email;
            cout << "Nom : ";
            getline(cin, nom);
            cout << "Téléphone : ";
            getline(cin, tel);
            cout << "Email : ";
            getline(cin, email);

            Contact** nouveauCarnet = new Contact*[taille + 1];
            for (int i = 0; i < taille; i++) {
                nouveauCarnet[i] = carnet[i];
            }
            nouveauCarnet[taille] = new Contact(nom, tel, email);
            delete[] carnet;
            carnet = nouveauCarnet;
            taille++;
        }
        else if (choix == 2) {
            if (taille == 0)
                cout << "Carnet vide." << endl;
            else
                for (int i = 0; i < taille; i++)
                    carnet[i]->afficher();
        }
        else if (choix == 3) {
            string nom;
            cout << "Entrez le nom du contact à supprimer : ";
            getline(cin, nom);
            supprimerContact(carnet, taille, nom);
        }
    } while (choix != 4);

    for (int i = 0; i < taille; i++) {
        delete carnet[i];
    }
    delete[] carnet;

    return 0;
}
