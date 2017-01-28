#include "lista_ptr.h"

namespace lista_ptr{
	
	lista::lista(){
		sz=0;
		testa = coda = 0;
	}
	
	lista::lista(const lista & l){
		
	}
	
	lista::~lista(){
		nodo* t = testa;
		while(t){
			nodo *t2=t->next;
			delete t;
			t=t2;
		}
	}
	
	void lista::print()const{
		nodo* t=testa;
		while(t){
			print_ptr(&t->elem);
			t=t->next;
		}
	}
	
	bool lista::push(const T & e){
		if(full()) return false;
		try{
			nodo * t = new nodo;
			t->elem=e;
			if(empty()){
			testa = coda = t;
			t->next=0;
			t->prec=0;
		}
		else {
			testa->prec=t;
			t->next=testa;
			testa=t;
			t->prec=0;
		}
		
		return true;

		}catch(bad_alloc & b){
			cout << "rilevato errore: " << b.what() << endl;
		}
	}

	
	
	bool lista::pop(T & e){
		if(empty()) return false;
		e=testa->elem;
		nodo* t=testa;
		testa=testa->next;
		delete t;
		return true;
	}
	
	bool lista::top(T & e)const{
		if(empty()) return false;
		e=testa->elem;
		return true;
	}
	
	bool lista::append(const T & e){
		if(full()) return false;
		try{
			nodo* t=new nodo;
			t->elem=e;
			
			if(empty()){
			testa = coda = t;
			t->next=t->prec=0;
		}
		else{
			coda->next=t;
			t->next=0;
			t->prec=coda;
		}
		} catch(bad_alloc & b){
			cout << "Rilevato errore " << b.what();
		}
	}
	
	
	bool lista::insert(const int pos, const T & e)throw (const char*){
		if(pos<0) throw POS_ERR ;
		if(empty() && pos>1) throw POS_ERR ;
		if(empty() && pos==0) {
		push(e);
		return true;
		}
		if(full()) return false;
		if(pos>sz) throw POS_ERR ;
		if(pos<=sz){
			nodo * t=testa;
			for(int i=0;i<pos;i++){
				t=t->next;
			}
			nodo*t1=t->next;
			try{
				nodo* n=new nodo;
				n->elem=e;
				
					
			t->next=n;
			n->prec=t;
			t1->prec=n;
			n->next=t1;
			return true;
				
			} catch(bad_alloc){
				cout << "rilevato errore! "<< endl;
			}
		}
	}
		
		bool lista::insert_at_pos(const int p, const T & e){
			try{
				insert(p,e);
			} catch(const char* err){
				cout << "errore nell'inserimento nella posizione indicata " << p << endl << " : " << err << endl;
				cout <<"\n\n riprovare l'inserimento: " ;
				int p1;
				cin >> p1;
				insert_at_pos(p1,e);
			}
		}
	

	
	
	
}
