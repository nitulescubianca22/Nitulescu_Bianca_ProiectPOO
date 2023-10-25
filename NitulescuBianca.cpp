#include<iostream>

using namespace std;

class Bautura {
public:
	static int cantitate;
	const int pret;
	string denumire;
	float mililitriAlcool;
	int nrIngrediente;
	string* ingrediente;

	static int getCantitate() {
		return cantitate;
	}

	Bautura(): pret(cantitate++) {
		this->denumire = "Hugo";
		this->mililitriAlcool = 40;
		this->nrIngrediente = 0;
		this->ingrediente = NULL;
		
		
	}

	Bautura(string denumire, float mililitriAlcool) : pret(cantitate) {
		cantitate++;
		this->denumire = denumire;
		this->mililitriAlcool = mililitriAlcool;
		this->nrIngrediente = 0;
		this->ingrediente = NULL;
	}



	Bautura(string denumire, float militriAlcool, int nrIngrediente, string* ingrediente) : pret(cantitate) {
		cantitate++;
		this->denumire = denumire;
		this->mililitriAlcool = militriAlcool;
		this->nrIngrediente = nrIngrediente;
		this->ingrediente = new string[nrIngrediente];
		for (int i = 0; i < nrIngrediente; i++) {
			this->ingrediente[i] = ingrediente[i];
		}
	}

	~Bautura() {
		if (this->ingrediente != NULL) {
			delete[]this->ingrediente;
		}
	}

	void afisareBautura() {
		cout << "Bautura: " << denumire << " are ca mililitrii de alcool: " << mililitriAlcool << " si numarul de ingrediente este: " << nrIngrediente << " acestea fiind: ";
		if (nrIngrediente > 0) {
			for (int i = 0; i < nrIngrediente; i++) {
				cout << ingrediente[i] << ", ";
			}
		}
		else {
			cout << "NA";
		}
		cout << endl;
	}

};
int Bautura::cantitate = 400;

class Barman {
public:
	static int nrZileLucratoare;
	const int oreLucratePeZi;
	string nume;
	float salariu;
	int nrBauturiOriginale;
	string* numeBauturiOriginale;

	static int getNrZileLucratoare() {
		return nrZileLucratoare;
	}

	Barman() : oreLucratePeZi(nrZileLucratoare++) {
		this->nume = "Toni";
		this->salariu = 2600;
		this->nrBauturiOriginale = 0;
		this->numeBauturiOriginale = NULL;


	}

	Barman(string nume, float salariu) : oreLucratePeZi(nrZileLucratoare) {
		nrZileLucratoare++;
		this->nume = nume;
		this->salariu = salariu;
		this->nrBauturiOriginale = 0;
		this->numeBauturiOriginale = NULL;
	}



	Barman(string nume, float salariu, int nrBauturiOriginale, string* numeBauturiOriginale) : oreLucratePeZi(nrZileLucratoare) {
		nrZileLucratoare++;
		this->nume = nume;
		this->salariu = salariu;
		this->nrBauturiOriginale = nrBauturiOriginale;
		this->numeBauturiOriginale = new string[nrBauturiOriginale];
		for (int i = 0; i < nrBauturiOriginale; i++) {
			this->numeBauturiOriginale[i] = numeBauturiOriginale[i];
		}
	}

	~Barman() {
		if (this->numeBauturiOriginale != NULL) {
			delete[]this->numeBauturiOriginale;
		}
	}

	void afisareBarman() {
		cout << "Barmanul pe nume: " << nume << " are un salariu de: " << salariu << " si un numar de bauturi originale de: " << nrBauturiOriginale << " cu denumirile: ";
		if (nrBauturiOriginale > 0) {
			for (int i = 0; i < nrBauturiOriginale; i++) {
				cout << numeBauturiOriginale[i] << ", ";
			}
		}
		else {
			cout << "NA";
		}
		cout << endl;
	}

};
int Barman::nrZileLucratoare = 5;

class Client {
public:
	static int nrNoptiInBar;
	const int orePeNoapteInBar;
	string nume;
	float venit;
	int nrBauturiPreferate;
	string* numeBauturiPreferate;

	static int getNrNoptiInBar() {
		return nrNoptiInBar;
	}

	Client() : orePeNoapteInBar(nrNoptiInBar++) {
		this->nume = "Bianca";
		this->venit = 5400;
		this->nrBauturiPreferate = 0;
		this->numeBauturiPreferate = NULL;


	}

	Client(string nume, float venit) : orePeNoapteInBar(nrNoptiInBar) {
		nrNoptiInBar++;
		this->nume = nume;
		this->venit = venit;
		this->nrBauturiPreferate = 0;
		this->numeBauturiPreferate = NULL;
	}



	Client(string nume, float venit, int nrBauturiPreferate, string* numeBauturiPreferate) : orePeNoapteInBar(nrNoptiInBar) {
		nrNoptiInBar++;
		this->nume = nume;
		this->venit = venit;
		this->nrBauturiPreferate = nrBauturiPreferate;
		this->numeBauturiPreferate = new string[nrBauturiPreferate];
		for (int i = 0; i < nrBauturiPreferate; i++) {
			this->numeBauturiPreferate[i] = numeBauturiPreferate[i];
		}
	}

	~Client() {
		if (this->numeBauturiPreferate != NULL) {
			delete[]this->numeBauturiPreferate;
		}
	}

	void afisareClient() {
		cout << "Clientul pe nume: " << nume << " are un venit de: " << venit << " si un numar de bauturi preferate de: " << nrBauturiPreferate << " cu denumirile: ";
		if (nrBauturiPreferate > 0) {
			for (int i = 0; i < nrBauturiPreferate; i++) {
				cout << numeBauturiPreferate[i] << ", ";
			}
		}
		else {
			cout << "NA";
		}
		cout << endl;
	}

};
int Client::nrNoptiInBar = 2;

void main() {
	Bautura bautura;
	bautura.afisareBautura();

	string* ingrediente =new string[3];
	ingrediente[0] = "Rom";
	ingrediente[1] = "Lamaie";
	ingrediente[2] = "Apa";

	Bautura bautura2("Mojito", 30, 3, ingrediente);
	bautura2.afisareBautura();

	Bautura bautura3("Martini", 50);
	bautura3.afisareBautura();

	/*cout << bautura2.getCantitate() << endl;*/
	cout << Bautura::getCantitate() << endl;

	Barman barman;
	barman.afisareBarman();

	string* numeBauturiOriginale = new string[3];
	numeBauturiOriginale[0] = "Running Jack";
	numeBauturiOriginale[1] = "Mediteranean Gin";
	numeBauturiOriginale[2] = "Tipsy Vodka";

	Barman barman2("Vlad", 2500, 3, numeBauturiOriginale);
	barman2.afisareBarman();

	Barman barman3("Dani", 3000);
	barman3.afisareBarman();

	/*cout << barman2.getNrZileLucratoare() << endl;*/
	cout << Barman::getNrZileLucratoare() << endl;

	Client client;
	client.afisareClient();

	string* numeBauturiPreferate = new string[3];
	numeBauturiPreferate[0] = "Bere";
	numeBauturiPreferate[1] = "Gin";
	numeBauturiPreferate[2] = "Vin";

	Client client2("Ana", 2900, 3, numeBauturiPreferate);
	client2.afisareClient();

	Client client3("Alice", 4000);
	client3.afisareClient();

	/*cout << client2.getNrNoptiInBar() << endl;*/
	cout << Client::getNrNoptiInBar() << endl;
}
