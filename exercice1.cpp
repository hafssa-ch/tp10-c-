
#include <iostream>
using namespace std;

int main() {
    int taille;

    cout << "Entrez la taille du tableau : ";
    cin >> taille;

    if (taille <= 0) {
        cout << "La taille doit être positive." << endl;
        return 1;
    }

    int* tableau = new int[taille];

  
    cout << "Entrez les " << taille << " valeurs du tableau :" << endl;
    for (int i = 0; i < taille; i++) {
        cout << "Valeur " << i + 1 << " : ";
        cin >> tableau[i];
    }

    
    cout << "\nLes valeurs saisies sont :" << endl;
    for (int i = 0; i < taille; i++) {
        cout << "tableau[" << i << "] = " << tableau[i] << endl;
    }

   
    delete[] tableau;
    tableau = nullptr; 

    cout << "\nMémoire libérée avec succès." << endl;

    return 0;
}
