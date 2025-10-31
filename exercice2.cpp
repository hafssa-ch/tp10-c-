
#include <iostream>
#include <string>
using namespace std;

class Personne {
private:
    string nom;
    int age;
public:
    Personne(string n, int a) {
        nom = n;
        age = a;
    }
    void afficher() {
        cout << "Nom : " << nom << ", Age : " << age << endl;
    }
};

int main() {
    Personne* p = new Personne("Alice", 25);
    p->afficher();
    delete p;
    return 0;
}
