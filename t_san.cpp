#include "t_san.h"

namespace cards{
	
	t_sanitaria::t_sanitaria() : tessera(){
		cf = new char[1];
		strcpy(cf,"");
		anno=0;
		giorno=0;
		mese=0;
	}
	
	t_sanitaria::t_sanitaria(const char* nome, const char* cognome, const char* cf, const int dd, const int mm, const int yy) 
							: tessera(nome,cognome){
								this->cf=new char[strlen(cf)+1];
								strcpy(this->cf,cf);
								giorno = dd;
								mese = mm;
								anno = yy;
							}
							
	t_sanitaria::t_sanitaria(const t_sanitaria & t) : tessera(t){
		cf = new char[strlen(t.cf)+1];
		strcpy(cf,t.cf);
		giorno = t.giorno;
		mese = t.mese;
		anno = t.anno;
	}
	
	const t_sanitaria & t_sanitaria::operator=(const t_sanitaria & t){
		if(this==&t) return *this;
		this->tessera::operator=(t);
		if(cf) delete [] cf;
		cf = new char[strlen(t.cf)+1];
		strcpy(cf,t.cf);
		giorno = t.giorno;
		mese = t.mese;
		anno = t.anno;
	}
	
	t_sanitaria::~t_sanitaria(){
		delete [] cf;
	}
	
	void t_sanitaria::set_cf(const char* cod){
		if (cf) delete [] cf;
		cf=new char[strlen(cod)+1];
		strcpy(cf,cod);
	}
	
	void t_sanitaria::set_aa(const int aa){
		anno = aa;	
	}
	
	void t_sanitaria::set_mm(const int mm){
		mese = mm;
	}
	
	void t_sanitaria::set_gg(const int gg){
		giorno = gg;
	}
	
	void t_sanitaria::print(ostream & of)const{
		tessera::print(of);
		of << cf << ' ' << giorno << ' ' << mese << ' ' << anno << ' ';
	}
	
	void t_sanitaria::read(istream & in){
		tessera::read(in);
		cout << "inserisci il codice fiscale: ";
		char buffer [800];
		in.getline(buffer,799);
		set_cf(buffer);
		cout << "inserisci giorno, mese e anno di nascita : ";
		in >> giorno >> mese >> anno;
		in.ignore();
	}
	
	ostream & operator<<(ostream & os, const t_sanitaria & t){
		t.print(os);
		return os;
	}
	
	istream & operator>>(istream & in,t_sanitaria & t){
		t.read(in);
		return in;

	}
	
	void t_sanitaria::save_txt(ofstream & of)const{
		tessera::save_txt(of);
		of << cf << ' ' << giorno << ' ' << mese << ' ' << anno <<' '; 
	}
	
	void t_sanitaria::save_txt(const char* nomefile)const throw (const char*){
		ofstream of(nomefile);
		if(of.fail()) throw FILE_ERR ;
		cout << "salvataggio in corso...";
		save_txt(of);
		of.close();
	}
	
	void t_sanitaria::save_bin(const char* nomefile)const throw (const char*){
		ofstream of(nomefile, ios::binary);
		if(of.fail()) throw FILE_ERR ;
		cout << "salvataggio in corso...";
		save_bin(of);
		of.close();
	}
	
	void t_sanitaria::serialize(ofstream & of)const{
		tessera::serialize(of);
		int len1=strlen(cf);
		of.write((char*)&len1,sizeof(len1));
		of.write(cf,len1);
		of.write((char*)&giorno,sizeof(giorno));
		of.write((char*)&mese,sizeof(mese));
		of.write((char*)&anno,sizeof(anno));
	}
	
	void t_sanitaria::deserialize(ifstream & in){
		tessera::deserialize(in);
		char* buff;
		int len1;
		in.read((char*)&len1,sizeof(len1));
		buff=new char[len1+1];
		in.read(buff,len1);
		buff[len1]='\0';
		set_cf(buff);
		in.read((char*)&giorno,sizeof(giorno));
		in.read((char*)&mese,sizeof(mese));
		in.read((char*)&anno,sizeof(anno));
	}
	
	void t_sanitaria::save_bin(ofstream & of)const{
		serialize(of);
	}
	
	
	
}

