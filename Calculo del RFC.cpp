/******************************************************************************
 
Author: Luis David Ruiz Villanueva
Programa: Calculo del RFC
Fecha: 29/11/2025

*******************************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>


// Diccionario de palabras No permitidas
const std::vector<std::string> palabrasProhibidas = {
    "PEDO","POPO","PENE","LOCO"
};

// Verificar y modificar palabras prohibidas del diccionario
std::string corregirRFC(const std::string& rfc) {
   for (const std::string& palabra : palabrasProhibidas) {
        if(rfc == palabra) {
            return rfc.substr(0,3) + "X"; // Remplaza la ultima letra por 'X'
        }
   }
return rfc;
}

// Función para obtener la primera vocal interna de una cadena
char obtenerPrimeraVocalInterna(const std::string& str) 
{
    for(size_t i = 1;i < str.length(); ++i)
    {
        char c = str[i];
        if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            return c;
    }
    return 'X'; // Si no encuentra ninguna vocal interna, se usa una X
    
        

}

//Función principal para calcular el RFC del empleado
std::string calcularRFC(const std::string& nombre, const std::string& apellidoPaterno,
const std::string& apellidoMaterno, const std::string& fechaNacimiento)
{
    
    //Se declara la variable donde guardaremos el RFC
    std::string rfc;
    
    //Se obtiene la letra incial y la primera vocal interna del apellido paterno
    char letraInicial = apellidoPaterno[0];
    char PrimeraVocalInterna = obtenerPrimeraVocalInterna(apellidoPaterno);
    
    // Se obtiene la inicial del apellido materno o se usa una 'X' si no existe
    char inicialApellidoMaterno = (!apellidoMaterno.empty()) ? apellidoMaterno[0] : 'X';
    
    // Se obtiene la inicial del primer nombre
    char inicialNombre = nombre[0];
    
    // Se obtiene los dos ultimos digitos del año de fechaNacimiento
    std::string anio = fechaNacimiento.substr(2, 2);
    
    // Se obtiene el mes y dia de nacimiento
    std::string mes = fechaNacimiento.substr(5, 2);
    std::string dia = fechaNacimiento.substr(8, 2);
    
    // Se construye el RFC sumando el texto de la información proporcionada
    rfc = letraInicial;
    rfc += PrimeraVocalInterna;
    rfc += inicialApellidoMaterno;
    rfc += inicialNombre;
    
    // Aqui se ejecuta la comparación de malas palabras en el diccionario y se sustituye con una X
    rfc = corregirRFC(rfc);
    
    // Realizar la corrección y se continua creando el rfc
    rfc += anio;
    rfc += mes;
    rfc += dia;
    
    return rfc;
}
int main()
{
    //Escribe en consola los pasos a seguir y espera los datos en mayúsculas
    std::string nombre, apellidoPaterno, apellidoMaterno, fechaNacimiento;
    std::cout <<"Introduce tu nombre: ";
    std::getline(std::cin, nombre);
    std::transform(nombre.begin(), nombre.end(), nombre.begin(), 
    [](unsigned char c){ return std::toupper(c); });
    std::cout <<"Introduce tu apellido paterno: ";
    std::getline(std::cin, apellidoPaterno);
    std::transform(apellidoPaterno.begin(), apellidoPaterno.end(), apellidoPaterno.begin(), 
    [](unsigned char c){ return std::toupper(c); });
    std::cout <<"Introduce tu apellido materno(Si no cuenta con apellido materno, presione ENTER): ";
    std::getline(std::cin, apellidoMaterno);
    std::transform(apellidoMaterno.begin(), apellidoMaterno.end(), apellidoMaterno.begin(), 
    [](unsigned char c){ return std::toupper(c); });
    std::cout << "Introduce tu fecha de nacimiento en el siguiente formato (YYYY-MM-DD): ";
    std::getline(std::cin, fechaNacimiento);
    std::string rfc = calcularRFC(nombre, apellidoPaterno, apellidoMaterno, fechaNacimiento);
    std::cout << "RFC: " << rfc << std::endl;
    
    return 0;
}
