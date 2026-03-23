
#include "Baby.h"
#include <iostream>

int main(){
	Ort hannover {"Hannover", 10 , 10};
	Ort hamburg {"Hamburg", 10 , 10}; 

	Person p = {&hannover, &hamburg, 10, "John doe"};
	Baby b = {&hamburg, &hannover, "Ann-Christin"};

	p.setAlter(26);
	b.setAlter(3); // soll fehler werfen

	std::cout << b.getName() << std::endl;
	return 0;
}