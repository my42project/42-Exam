#include "Warlock.hpp"

int	main( void ) {
	std::cout << "		Constructor		" << std::endl;

	//Warlock bob;                            //Does not compile
	Warlock bob("Bob", "the magnificent");  //Compiles
	Warlock jim("Jim", "the nauseating");   //Compiles
	//bob = jim;                              //Does not compile
	//Warlock jack(jim);                      //Does not compile

	bob.introduce();
	jim.setTitle("test");
	jim.introduce();
}
