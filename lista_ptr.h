#ifndef lista_h
#define lista_h
#include <iostream>
#include <cstring>
#include "tessera.h"
#include <fstream>
#define FILE_ERR "errore nell'apertura del file, provare ad inserire nuovamente il nome del file: '"
#define POS_ERR "errore, la lista non contiene abbastanza elementi o è piena, indicare nuovamente il valore della posizione : "

using std::cin;
using std::cout;
using std::endl;
using std::fstream;
using std::ifstream;
using std::ofstream;
using std::istream;
using std::ostream;
using std::ios;
using std::bad_alloc;

using namespace cards;


namespace lista_ptr{
	
	typedef tessera T;
	
	struct nodo;
	
	struct nodo{
		T elem;
		nodo* next;
		nodo* prec;	
	};
	
	class lista{
		nodo* testa;
		nodo* coda;
		int sz;
		void print_ptr(const T * e)const{cout << e;}
		bool insert(const int, const T &) throw(const char*);
		public:
		lista();
		lista(const lista &);
		~lista();
		void print()const;
		bool push(const T &);
		bool pop(T &);
		bool top(T &)const;
		bool append(const T &);
		bool insert_at_pos(const int, const T & e);
		bool empty()const{return sz==0;}
		bool full()const{return false;} //lista dinamica
		
	};
	
	
	
	
}

#endif //lista_h
