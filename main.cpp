#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

class ciagi{
	public:
		fstream plik;
		vector<int> szesciany;
		
		ciagi();
		~ciagi();
		void wczytajLiczby();
		void wypisz();
		bool sprawdz_czy_szescian(int liczba);
		int max(vector<int> szesciany);
		
	private:
};

ciagi::ciagi(){
	if(plik.good())
		plik.open("c:\\ciagi.txt", ios::in);  
	else
		cout<<"Cos poszlo nie tak przy otwieraniu pliku.";
};

ciagi::~ciagi(){
	plik.close();  
}

void ciagi::wczytajLiczby()
{
	while(!plik.eof())  
    {
    	int dlugosc;
    	int liczba;
	    for(int q = 0; q < 100; q++)
	    {
	        plik >> dlugosc;
	        for(int i = 0; i < dlugosc; i++)
	        {
	        	plik >> liczba;
				if(sprawdz_czy_szescian(liczba)) szesciany.push_back(liczba);	
			}		
	    }            
    }
}

void ciagi::wypisz()
{
	cout<<max(szesciany);
}

bool ciagi::sprawdz_czy_szescian(int liczba)
{
	for (int i=0; i<liczba; i++)
	{
	     int szescian= i * i * i;
	     if (szescian == liczba) return true;
	}
	return false;
}

int ciagi::max(vector<int> szesciany)
{
	int max = szesciany[0];
	
	for (int i = 0; i < szesciany.size(); i++)
	{
		if (max < szesciany[i])
			max = szesciany[i];
	}
	return max;
}

int main(int argc, char** argv) {
	ciagi b;
	
	b.wczytajLiczby();
	b.wypisz();
	return 0;
}
