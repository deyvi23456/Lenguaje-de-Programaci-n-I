/******************************************************************************

Descripción: Ingresa 2 datos y realiza suma,resta, multiplicación y división
Actividad No.2
Author: Luis David Ruiz Villanueva

*******************************************************************************/
#include <iostream>

int main()
{
    
    float numero1,numero2;
    
    std::cout <<"Escribe el primer número: ";
    std::cin >> numero1;
    
    std::cout <<"Escribe el segundo número: ";
    std::cin >> numero2;
    
    float suma = numero1 + numero2;
    float resta = numero1 - numero2;
    float multiplicación = numero1 * numero2;
    float división = numero1 / numero2;
    
    std::cout << "La suma es: " <<suma<<std::endl;
    std::cout << "La resta es: " <<resta<<std::endl;
    std::cout << "La multiplicación es: " <<multiplicación<<std::endl;
    std::cout << "La división es: " <<división<<std::endl;
    
    return 0;
}
