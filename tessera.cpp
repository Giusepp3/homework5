#include "tessera.h"

namespace cards{
	
	tessera::tessera(){
		nome = new char[1];
		strcpy(nome,"");
		cognome  =new char[1];
		strcpy(cognome,"");
		
	}
	
	tessera::tessera(const char* n, const char* c){
		nome = new char[strlen(n)+1];
		cognome = new char[strlen(c)+1];
		strcpy(nome,n);
		strcpy(cognome,c);
	}
	
	
	tessera::tessera(const tessera & t){
		nome = new char[strlen(t.nome)+1];
		strcpy(nome,t.nome);
		cognome = new char[strlen(t.cognome)+1];
		strcpy(cognome,t.cognome);
	}
	
	const tessera& tessera::operator=(const tessera & t){
		if(this==&t) return *this;
		if(nome) delete [] nome;
		nome = new char[strlen(t.nome)+1];
		strcpy(nome,t.nome);
		if(cognome) delete [] cognome;
		cognome = new char[strlen(t.cognome)+1];
		strcpy(cognome,t.cognome);
		return *this;
	}
	
	
	tessera::~tessera(){
		delete [] nome;
		delete [] cognome;
	}
	
	
	
	void tessera::serialize(ofstream & of)const{
		int len1=strlen(nome),len2=strlen(cognome);
		of.write((char*)&len1,sizeof(len1));
		of.write(nome,len1);
		of.write((char*)&len2,sizeof(len2));
		of.write(cognome,len2);
	}
	
	void tessera::deserialize(ifstream & in){
		int len1,len2;
		char* buff;
		in.read((char*)&len1,sizeof(len1));
		buff=new char[len1+1];
		in.read(buff,len1);
		buff[len1]='\0'; //assegno il terminatore di stringa
		set_nome(buff);
		delete [] buff;
		in.read((char*)&len2,sizeof(len2));
		buff = new char[len2+1];
		in.read(buff,len2);
		buff[len2]='\0';
		set_cognome(buff);
		delete [] buff;
	}
	
	void tessera::set_cognome(const char* c){
		if(cognome) delete [] cognome;
		cognome = new char[strlen(c)+1];
		strcpy(cognome,c);
	
	}
	
	void tessera::set_nome(const char* n){
		if(nome) delete [] nome;
		nome = new char[strlen(n)+1];
		strcpy(nome,n);
	}
	
	void tessera::print(ostream & os)const{
		os << nome << ' ' << cognome << ' ';
	}
	
	ostream & operator<<(ostream & os, const tessera & t){
		t.print(os);
		return os;
	}
	
	void tessera::read(istream & in){
		char buf[800];
		cout << "inserisci il nome: ";
		in.getline(buf,799);
		set_nome(buf);
		cout << "inserisci il cognome: ";
		in.getline(buf,799);
		set_cognome(buf);
	}
	
	
	istream & operator>>(istream & in, tessera & t){
		t.read(in);
		return in;
	}
	
	void tessera::save_bin(const char* nomefile)const throw(const char*){
		cout << "salvataggio su file "<< nomefile<< endl;
		ofstream of(nomefile,ios::binary);
		if(of.fail()) throw FILE_ERR ;
		save_bin(of);
		of.close();
	}
	
	void tessera::save_bin(ofstream & of)const{
		serialize(of);
	}
	
	
	void tessera::save_txt(const char* nomefile)const throw(const char*){
		ofstream of(nomefile);
		cout << "salvataggio su file " << nomefile << endl;
		if(of.fail()) throw FILE_ERR ;
		save_txt(of);
		of.close();
	}
	
	void tessera::save_txt(ofstream & of)const{
		of << nome << ' ' << cognome << ' ';
	}
	
	
	
}


