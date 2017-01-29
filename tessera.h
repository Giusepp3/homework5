#ifndef tessera_h
#define tessera_h
#include <iostream>
#include <cstring>
#include <fstream>
#define FILE_ERR "errore nell'apertura del file, provare ad inserire nuovamente il nome del file: '"

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
	
	class tessera{
		private:
			char* nome;
			char* cognome;
		protected:
			virtual void serialize(ofstream & os)const;
			virtual void deserialize(ifstream & in);
			virtual void read(istream & in);
			virtual void print(ostream & os)const;
		public:
			tessera();
			tessera(const char* nome, const char* cognome);
			tessera(const tessera & t);
			const tessera & operator=(const tessera & t);
			~tessera();
			void set_nome(const char* nome);
			void set_cognome(const char* cognome);
			const char* get_nome()const{return nome;}
			const char* get_cognome()const{return cognome;}
			friend ostream & operator<<(ostream & os, const tessera & t);
			friend istream & operator>>(istream & in, tessera & t);
			void save_txt(const char* nomefile)const throw(const char*);
			void save_bin(ofstream & of)const;
			void save_txt(ofstream & of)const;
			void save_bin(const char* nomefile)const throw(const char*);
			
	};
	
	
	
	
	
}

#endif //tessera_h
