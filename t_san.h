#ifndef t_san_h
#define t_san_h
#include "tessera.h"
#include <iostream>
#include <cstring>
#include <fstream>
#define FILE_ERR "errore nell'apertura del file, provare ad inserire nuovamente il nome del file: '"
#define ERR_DATA "errore dato inserito non corretto! riprova ad inserire nuovamente il valore "

using std::cin;
using std::cout;
using std::endl;
using std::fstream;
using std::ifstream;
using std::ofstream;
using std::istream;
using std::ostream;
using std::ios;

namespace cards{
	
	class t_sanitaria : public tessera{
		private: 
			char* cf;
			int anno;
			int giorno;
			int mese;
		public: //dovrebbe essere protected
			void print(ostream & os)const;
			void read(istream & in);
			void serialize(ofstream & of)const;
			void deserialize(ifstream & in);
		public:
			t_sanitaria();
			t_sanitaria(const char* nome, const char* cognome, const char* cf, const int dd, const int mm, const int yy);
			t_sanitaria(const t_sanitaria & t );
			const t_sanitaria& operator=(const t_sanitaria & t);
			~t_sanitaria();
			void set_cf(const char* cf);
			void set_aa(const int aa);
			void set_mm(const int mm);
			void set_gg(const int gg);
			const char* get_cf()const{return cf;}
			int get_aa()const{return anno;}
			int get_mm()const{return mese;}
			int get_gg()const{return giorno;}
			friend ostream & operator<<(ostream & os, const tessera & t);
			friend istream & operator>>(istream & in, tessera & t);
			void save_txt(const char* nomefile)const throw(const char*);
			void save_bin(ofstream & of)const;
			void save_txt(ofstream & of)const;
			void save_bin(const char* nomefile)const throw(const char*);
			
	};
	
	
}



#endif //t_san_h
