#include<iostream>
using namespace std;


class Bautura {
private:

	static int cantitate;
	const int pret;
	string denumire;
	float mililitriAlcool;
	int nrIngrediente;
	string* ingrediente;

public:

	static int getCantitate() {
		return Bautura::cantitate;
	}

	const int getPret() {
		return pret;
	}

	string getDenumire() {
		return denumire;
	}

	float getMililitriAlcool() {
		return mililitriAlcool;
	}

	int getNrIngrediente() {
		return nrIngrediente;
	}

	string* getIngrediente() {
		return ingrediente;
	}

	void setDenumire(string denumireNou) {
		if (denumireNou.length() > 2) {
			denumire = denumireNou;
		}
	}

	void setMililitriAlcool(float mililitriAlcoolNou) {
		if (mililitriAlcool >= 30.0) {
			mililitriAlcool = mililitriAlcoolNou;
		}
	}

	void setNrIngrediente(int nrIngredienteNou) {
		if (nrIngredienteNou > 0) {
			nrIngrediente = nrIngredienteNou;
			delete[] ingrediente;
			ingrediente = new string[nrIngrediente];
		}
	}

	void setIngrediente(int nrIngrediente, string* ingrediente) {
		if (nrIngrediente > 0) {
			this->nrIngrediente = nrIngrediente;
			if (this->ingrediente != NULL) {
				delete[]this->ingrediente;
			}
			this->ingrediente = new string[nrIngrediente];
			for (int i = 0; i < nrIngrediente; i++) {
				this->ingrediente[i] = ingrediente[i];
			}
		}
	}

	Bautura() : pret(cantitate++) {
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

	Bautura(string denumire, float mililitriAlcool, int nrIngrediente, string* ingrediente) : pret(cantitate) {
		cantitate++;
		this->denumire = denumire;
		this->mililitriAlcool = mililitriAlcool;
		this->nrIngrediente = nrIngrediente;
		this->ingrediente = new string[nrIngrediente];
		for (int i = 0; i < nrIngrediente; i++) {
			this->ingrediente[i] = ingrediente[i];
		}
	}

	Bautura(const Bautura& b) :pret(b.pret) {
		this->denumire = b.denumire;
		this->mililitriAlcool = b.mililitriAlcool;
		this->nrIngrediente = b.nrIngrediente;
		this->ingrediente = new string[b.nrIngrediente];
		for (int i = 0; i < b.nrIngrediente; i++) {
			this->ingrediente[i] = b.ingrediente[i];
		}
	}

	~Bautura() {
		if (this->ingrediente != NULL) {
			delete[]this->ingrediente;
			this->ingrediente = nullptr;
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

	friend string getIngrediente(const Bautura& b);
};
int Bautura::cantitate = 400;

string getIngrediente(const Bautura& in) {
	string aux = ", ";
	for (int i = 0; i < in.nrIngrediente; i++) {
		aux += in.ingrediente[i] + ", ";
	}
	return aux;
}

class Barman {
private:

	static int nrZileLucratoare;
	const int oreLucratePeZi;
	string nume;
	float salariu;
	int nrBauturiOriginale;
	string* numeBauturiOriginale;

public:

	static int getNrZileLucratoare() {
		return Barman::nrZileLucratoare;
	}

	const int getOreLucratePeZi() {
		return oreLucratePeZi;
	}

	string getNume() {
		return nume;
	}

	float getSalariu() {
		return salariu;
	}

	int getNrBauturiOriginale() {
		return nrBauturiOriginale;
	}

	string* getNumeBauturiOriginale() {
		return numeBauturiOriginale;
	}

	void setNume(const string& numeNou) {
		if (numeNou.length() > 3)
			nume = numeNou;
	}

	void setSalariu(float salariuNou) {
		if (salariuNou >= 2000)
			salariu = salariuNou;
	}

	void setNrBauturiOriginale(int nrBauturiOriginaleNou) {
		if (nrBauturiOriginaleNou > 0) {
			nrBauturiOriginale = nrBauturiOriginaleNou;
			delete[] numeBauturiOriginale;
			numeBauturiOriginale = new string[nrBauturiOriginale];
		}
	}

	void setNumeBauturiOriginale(const string* numeBauturiOriginaleNou, int nrBauturiOriginaleNou) {
		if (nrBauturiOriginale == nrBauturiOriginaleNou) {
			for (int i = 0; i < nrBauturiOriginale; ++i) {
				numeBauturiOriginale[i] = numeBauturiOriginaleNou[i];
			}
		}
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

	Barman(const Barman& bb) :oreLucratePeZi(bb.oreLucratePeZi) {
		this->nume = bb.nume;
		this->salariu = bb.salariu;
		this->nrBauturiOriginale = bb.nrBauturiOriginale;
		this->numeBauturiOriginale = new string[bb.nrBauturiOriginale];
		for (int i = 0; i < bb.nrBauturiOriginale; i++) {
			this->numeBauturiOriginale[i] = bb.numeBauturiOriginale[i];
		}
	}

	~Barman() {
		if (this->numeBauturiOriginale != NULL) {
			delete[] this->numeBauturiOriginale;
			this->numeBauturiOriginale = nullptr;
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

	friend string getBautura(const Barman& b);
};
int Barman::nrZileLucratoare = 5;

string getBautura(const Barman& b) {
	string aux = ", ";
	for (int i = 0; i < b.nrBauturiOriginale; i++) {
		aux += b.numeBauturiOriginale[i] + ", ";
	}
	return aux;
}

class Client {
private:

	static int nrNoptiInBar;
	const int orePeNoapteInBar;
	string nume;
	float venit;
	int nrBauturiPreferate;
	string* numeBauturiPreferate;

public:

	static int getNrNoptiInBar() {
		return Client::nrNoptiInBar;
	}

	const int getOrePeNoapteInBar() {
		return orePeNoapteInBar;
	}

	string getNume() {
		return nume;
	}

	float getVenit() {
		return venit;
	}

	int getNrBauturiPreferate() {
		return nrBauturiPreferate;
	}

	string* getNumeBauturiPreferate() {
		return numeBauturiPreferate;
	}

	void setNume(const string& numeNou) {
		if (numeNou.length() > 3)
			nume = numeNou;
	}

	void setVenit(float venitNou) {
		if (venitNou >= 2000)
			venit = venitNou;
	}

	void setNrBauturiPreferate(int nrBauturiPreferateNou) {
		if (nrBauturiPreferateNou > 0) {
			nrBauturiPreferate = nrBauturiPreferateNou;
			delete[] numeBauturiPreferate;
			numeBauturiPreferate = new string[nrBauturiPreferate];
		}
	}

	void setNumeBauturiPreferate(const string* numeBauturiPreferateNou, int nrBauturiPreferateNou) {
		if (nrBauturiPreferate == nrBauturiPreferateNou)
			for (int i = 0; i < nrBauturiPreferate; ++i) {
				numeBauturiPreferate[i] = numeBauturiPreferateNou[i];
			}
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

	Client(const Client& c) :orePeNoapteInBar(c.orePeNoapteInBar) {
		this->nume = c.nume;
		this->venit = c.venit;
		this->nrBauturiPreferate = c.nrBauturiPreferate;
		this->numeBauturiPreferate = new string[c.nrBauturiPreferate];
		for (int i = 0; i < c.nrBauturiPreferate; i++) {
			this->numeBauturiPreferate[i] = c.numeBauturiPreferate[i];
		}
	}

	~Client() {
		if (this->numeBauturiPreferate != NULL) {
			delete[]this->numeBauturiPreferate;
			this->numeBauturiPreferate = nullptr;
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
	Bautura ba;
	ba.afisareBautura();
	string* ingrediente = new string[3];
	ingrediente[0] = "Rom";
	ingrediente[1] = "Lamaie";
	ingrediente[2] = "Apa";
	Bautura bautura2("Mojito", 30, 3, ingrediente);
	bautura2.afisareBautura();
	Bautura bautura3("Martini", 50);
	bautura3.afisareBautura();
	Bautura b1 = bautura2;
	bautura2.afisareBautura();
	//Getteri
	cout << "Valori initiale:" << endl;
	cout << "Cantitate: " << ba.getCantitate() << endl;
	cout << "Pret: " << ba.getPret() << endl;
	cout << "Denumire: " << ba.getDenumire() << endl;
	cout << "MililitriAlcool: " << ba.getMililitriAlcool() << endl;
	cout << "NrIngrediente: " << ba.getNrIngrediente() << endl;
	cout << "Ingrediente: ";
	string* ingrediente = ba.getIngrediente();
	for (int i = 0; i < ba.getNrIngrediente(); i++) {
		cout << (i > 0 ? ", " : "") << (ingrediente[i]);
	}
	cout << endl;

	//Setteri
	ba.setDenumire("Mojito");
	ba.setMililitriAlcool(50);
	ba.setNrIngrediente(3);
	string ingredientList[] = { "Lime", "Mint", "Sugar" };
	ba.setIngrediente(3, ingredientList);

	cout << "\nValori noi::" << endl;
	cout << "Denumire: " << ba.getDenumire() << endl;
	cout << "MililitriAlcool: " << ba.getMililitriAlcool() << endl;
	cout << "NrIngrediente: " << ba.getNrIngrediente() << endl;
	cout << "Ingrediente: ";
	ingrediente = ba.getIngrediente();
	for (int i = 0; i < ba.getNrIngrediente(); i++) {
		cout << (i > 0 ? ", " : "") << (ingrediente[i]);
	}
	cout << endl;
	/// cout << bautura2.getCantitate() << endl; /
		cout << Bautura::getCantitate() << endl;

	Barman b;
	b.afisareBarman();
	string* numeBauturiOriginale = new string[3];
	numeBauturiOriginale[0] = "Running Jack";
	numeBauturiOriginale[1] = "Mediteranean Gin";
	numeBauturiOriginale[2] = "Tipsy Vodka";
	Barman barman2("Vlad", 2500, 3, numeBauturiOriginale);
	barman2.afisareBarman();
	Barman barman3("Dani", 3000);
	barman3.afisareBarman();

	//Getteri
	cout << endl;
	cout << "NrZileLucratoare: " << b.getNrZileLucratoare() << endl;
	cout << "OreLucratePeZi: " << b.getOreLucratePeZi() << endl;
	cout << "Nume: " << b.getNume() << endl;
	cout << "Salariu: " << b.getSalariu() << endl;
	cout << "NrBauturiOriginale: " << b.getNrBauturiOriginale() << endl;
	cout << "NumeBauturiOriginale: ";
	string* numeBauturiOriginale = b.getNumeBauturiOriginale();
	for (int i = 0; i < b.getNrBauturiOriginale(); i++) {
		cout << (i > 0 ? ", " : "") << (numeBauturiOriginale[i]);
	}
	cout << endl;

	//Setteri
	b.setNume("John");
	b.setSalariu(3000);
	b.setNrBauturiOriginale(3);
	string bauturi[] = { "Mojito", "Cosmopolitan", "Margarita" };
	b.setNumeBauturiOriginale(bauturi, 3);

	cout << "\nValori noi:" << endl;
	cout << "Nume: " << b.getNume() << endl;
	cout << "Salariu: " << b.getSalariu() << endl;
	cout << "Nr Bauturi Originale: " << b.getNrBauturiOriginale() << endl;
	cout << "Nume Bauturi Originale: ";
	numeBauturiOriginale = b.getNumeBauturiOriginale();
	for (int i = 0; i < b.getNrBauturiOriginale(); i++) {
		cout << (i > 0 ? ", " : "") << (numeBauturiOriginale[i]);
	}
	cout << endl;

	///*/ cout << barman2.getNrZileLucratoare() << endl; /*/
	cout << b.getNrZileLucratoare() << endl;

	Client c;
	c.afisareClient();
	string* numeBauturiPreferate = new string[3];
	numeBauturiPreferate[0] = "Bere";
	numeBauturiPreferate[1] = "Gin";
	numeBauturiPreferate[2] = "Vin";
	Client client2("Ana", 2900, 3, numeBauturiPreferate);
	client2.afisareClient();
	Client client3("Alice", 4000);
	client3.afisareClient();
	//Getteri
	cout << "Valori initiale:" << endl;
	cout << "NrNoptiInBar: " << c.getNrNoptiInBar() << endl;
	cout << "OrePeNoapteInBar: " << c.getOrePeNoapteInBar() << endl;
	cout << "Nume: " << c.getNume() << endl;
	cout << "Venit: " << c.getVenit() << endl;
	cout << "NrBauturiPreferate: " << c.getNrBauturiPreferate() << endl;
	cout << "NumeBauturiPreferate: ";
	string* numeBauturiPreferate = c.getNumeBauturiPreferate();
	for (int i = 0; i < c.getNrBauturiPreferate(); i++) {
		cout << (i > 0 ? ", " : "") << (numeBauturiPreferate[i]);
	}
	cout << endl;

	//Setteri
	c.setNume("Alice");
	c.setVenit(3000);
	c.setNrBauturiPreferate(3);
	string bauturi[] = { "Martini", "Negroni", "Old Fashioned" };
	c.setNumeBauturiPreferate(bauturi, 3);
	cout << "\nValori finale:" << endl;
	cout << "Nume: " << c.getNume() << endl;
	cout << "Venit: " << c.getVenit() << endl;
	cout << "NrBauturiPreferate: " << c.getNrBauturiPreferate() << endl;
	cout << "NumeBauturiPreferate: ";
	numeBauturiPreferate = c.getNumeBauturiPreferate();
	for (int i = 0; i < c.getNrBauturiPreferate(); i++) {
		cout << (i > 0 ? ", " : "") << (numeBauturiPreferate[i]);
	}
	cout << endl;

	/// cout << client2.getNrNoptiInBar() << endl; /
		cout << Client::getNrNoptiInBar() << endl;
}
