#include <iostream>
#include "tessera.h"
#include "t_san.h"
#include "lista_ptr.h"

using namespace std;
using namespace cards;
using namespace lista_ptr;



/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	tessera a,b("giuseppe", "ferrara");
	
	t_sanitaria f,h("giuseppe","ferrara","FRRGPP96E08F839J",8,5,1996);


	lista l;
	
	if(l.push(&b)) cout << "inserito!" << endl;
	else cout << "errore! " <<endl;
	
	if(l.push(&h)) cout << "inserito!" << endl;
	else cout << "errore! " <<endl;
	if(l.append(&h)) cout <<"inserito!" << endl;
	else cout << "errore!" << endl;
	
	l.insert_at_pos(1,&b);
	
	l.insert_at_pos(10,&h);
	
	l.print();
	
	cout << "nella lista ci sono: " << l.get_sz();
	
	return 0;
}
