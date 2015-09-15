#include <iostream>
#include "lista.h"
#include "bild.h"

using namespace std;

///Funkcja wykorzystująca przykład wzorca projektowego budowniczy///
void Product::print(){


	cout << "Product internals dump:" << endl;
	cout << "i: " << this->i << endl;
	cout << "f: " << this->f << endl;
	cout << "c: " << this->c << endl;
}

void Product::doSomething(){}
void Product::doSomethingElse(){}

/*!
 *  \brief     Całkiem zacnie

 *  \author    Paweł Knutelski
 *  \author    Adrian Jarosz


 */
///Program wykonujący proste oblicznia. Autorzy Paweł Knutelski, Adrian Jarosz///
int main(){

    cout << "Wynik dodawania to: " << dodawanie(5,6) << endl;
    cout << "Wynik mnozenia to: " << mnozenie(5,6) << endl;

    ///wykorzystanie wzorca projektowego
    Product p1 = Product::Builder().setI(2).setF(0.5f).setC('x').build();
	p1.print(); // test p1

	// advanced usage
	Product::Builder b;
	b.setProductP();
	Product p2 = b.build(); // get Product P object
	b.setC('!'); // customize Product P
	Product p3 = b.build();
	p2.print(); // test p2
	p3.print(); // test p3
    return 0;
}
