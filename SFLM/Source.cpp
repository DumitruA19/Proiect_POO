#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Clasa pentru reprezentarea mașinilor
class Masina {
public:
    string marca;
    string model;
    string culoare;
    int capacitate_cilindrica;
    int an_fabricatie;

    Masina(string mrc, string mdl, string clr, int cap, int an)
        : marca(mrc), model(mdl), culoare(clr), capacitate_cilindrica(cap),an_fabricatie(an) {}
};

// Clasa pentru reprezentarea serviciilor oferite
class Serviciu {
public:
    string nume;
    float pret;

    Serviciu(string n, float p) : nume(n), pret(p) {}
};

// Clasa pentru reprezentarea clienților
class Client {
public:
    string nume;
    string prenume;
    string adresa;
    string numar_telefon;
    vector<Masina> masini;

    Client(string n,string pre, string adr,string t) : nume(n),prenume(pre), adresa(adr) ,numar_telefon(t){}

    void adaugaMasina(Masina m) {
        masini.push_back(m);
    }
};

// Clasa principala a aplicației
class AplicatieServiceAuto {
public:
    vector<Client> clienti;
    vector<Serviciu> servicii;

    // Metoda pentru înregistrarea unui client nou
    void inregistrareClient() {
        string nume, prenume, adresa, numar_telefon;
        cout << "Introduceti numele clientului: ";
        cin >> nume;
        cout << "Introduceti prenumele clientului: ";
        cin >> prenume;
        cout << "Introduceti adresa clientului: ";
        cin >> adresa;
        cout << "Introduceti numarul de telefon al clientului: ";
        cin >> numar_telefon;
        Client c(nume, prenume, adresa, numar_telefon);
        clienti.push_back(c);

        cout << "Client inregistrat cu succes!\n";
    }


    // Metoda pentru înregistrarea unei mașini pentru un client existent
    void inregistrareMasina() {
        string nume;
        cout << "Introduceti numele clientului: ";
        cin >> nume;

        bool client_gasit = false;
        for (auto& client : clienti) {
            if (client.nume == nume) {
                string marca, model, culoare;
                int capacitate_cilindrica, an_fabricatie;

                cout << "Introduceti marca masinii: ";
                cin >> marca;
                cout << "Introduceti modelul masinii: ";
                cin >> model;
                cout << "Introduceti culoarea masinii: ";
                cin >> culoare;
                cout<<  "Introduceti capacitate motor: ";
                cin >> capacitate_cilindrica;
                cout << "Introduceti anul fabricatiei masinii: ";
                cin >> an_fabricatie;

                Masina m(marca, model, culoare,capacitate_cilindrica, an_fabricatie);
                client.adaugaMasina(m);

                cout << "Masina inregistrata cu succes pentru clientul " << client.nume << "!\n";
                client_gasit = true;
                break;
            }
        }

        if (!client_gasit) {
            cout << "Clientul " << nume << " nu a fost gasit!\n";
        }
    }

    // Metoda pentru înregistrarea unui serviciu oferit
    void inregistrareServiciu() {
        string nume;
        float pret;

        cout << "Introduceti numele serviciului: ";
        cin >> nume;
        cout << "Introduceti pretul serviciului: ";
        cin >> pret;

        Serviciu s(nume, pret);
        servicii.push_back(s);

        cout << "Serviciu inregistrat cu succes!\n";
    }

    // Metoda pentru afișarea detaliilor în interfața grafică
    void afisareDetalii() {
        cout << "----- Clienti -----\n";
        for (const auto& client : clienti) {
            cout << "Nume: " << client.nume << endl;
            cout << "Prenume: " << client.prenume << endl;
            cout << "Adresa: " << client.adresa << endl;
            cout << "Numar telefon: " << client.numar_telefon << endl;

            cout << "Masini:\n";
            for (const auto& masina : client.masini) {
                cout << "- Marca: " << masina.marca << endl;
                cout << "  Model: " << masina.model << endl;
                cout << "  Culoare: " << masina.culoare << endl;
                cout << " Capactitate cilindrica: " << masina.capacitate_cilindrica << endl;
                cout << "  An fabricatie: " << masina.an_fabricatie << endl;
            }

            cout << endl;
        }

        cout << "----- Servicii -----\n";
        for (const auto& serviciu : servicii) {
            cout << "Nume: " << serviciu.nume << endl;
            cout << "Pret: " << serviciu.pret << endl;
            cout << endl;
        }
    }
};

int main() {
    AplicatieServiceAuto aplicatie;

    int optiune;
    do {
        cout << "1. Inregistrare client\n";
        cout << "2. Inregistrare masina\n";
        cout << "3. Inregistrare serviciu\n";
        cout << "4. Afisare detalii\n";
        cout << "0. Iesire\n";
        cout << "Introduceti optiunea: ";
        cin >> optiune;

        switch (optiune) {
        case 1:
            aplicatie.inregistrareClient();
            break;
        case 2:
            aplicatie.inregistrareMasina();
            break;
        case 3:
            aplicatie.inregistrareServiciu();
            break;
        case 4:
            aplicatie.afisareDetalii();
            break;
        case 0:
            cout << "La revedere!";
            break;
        default:
            cout << "Optiune invalida!";
            break;
        }

        cout << endl;
    } while (optiune != 0);

    return 0;
}
