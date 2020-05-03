/*Ejercicio#2
Una persona desea realizar un muestreo con un numero de personas para determinar el porcentaje de
niños, jóvenes, adultos y adultos mayores que existen en la zona en donde vive.
La categoría se determina en base a la siguiente tabla:
Categoría			Edad
Niños				0-12
Jóvenes				13-29
Adultos				30-59
Adultos Mayores		60 en adelante
Teniendo en cuenta que para el muestreo de personas no será mayor a 50, realice un programa que en
primer lugar reciba como dato el numero de personas del muestreo y luego por cada persona permita el
ingreso de su edad y grabar todo a un archivo. El programa deberá leer los datos del archivo y mostrar
como resultado el porcentaje de personas que hay por cada una de las categorías.*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct muestreo{
	int pobladores;
	int edad;
	
};
void datos();
void porcentajes();
int main(){
	datos();
	//porcentajes();
} 
void datos(){
	int pobladores;
	int edad;
	int n,j,a,am,suma=0,SUMA=0,resultado=0,RESULTADO=0;
	string s;
	int c;
	
	cout<<"-------------Muestreo de Pobladores-------------"<<"\n"<<endl;
	cout<<"Ingrese cantidad de pobladores (De 1 a 50): "<<endl;cin>>pobladores;
	cout<<"Ingrese edades: "<<endl;
	while(c<pobladores){
		c+=1;
		cin>>edad;

		if(edad>=0 && edad<=12){
			n=1;
			suma+=n;
			cout<<"Entra en la categoria NINOS"<<endl;
			
		}
		else if (edad>=13 && edad<=29){
			j=1;
			SUMA+=j;
			cout<<"Entra en la categoria JOVENES"<<endl;
		}
		else if (edad>=30 && edad<=59){
			a=1;
			resultado+=a;
			cout<<"Entra en la categoria ADULTOS"<<endl;
		}
		else if (edad>=60){
			am=1;
			RESULTADO+=am;
			cout<<"Entra en la categoria ADULTOS MAYORES"<<endl;
		}
	}
	
	cout<<"\n Numero de pobladores: "<<pobladores<<"\t"<<"Cant.ninos "<<suma<<"\t"<<"Cant.jovenes "<<SUMA<<"\t"<<"Cant Adultos "<<resultado<<"\t"<<"Cant.Adultos Mayores  "<<RESULTADO<<endl;
	ofstream grabararchivo;
	try {
		grabararchivo.open("HT4_EJERCICIO_O2.txt",ios::app);
		grabararchivo<<pobladores<<"\t"<<"\t"<<suma<<"\t"<<SUMA<<"\t"<<resultado<<"\t"<<RESULTADO<<endl;
		grabararchivo.close();
	}
	catch (exception X){
		cout<<"Error en la manipulación del archivo"<<endl;
	}
	cout<<"\n"<<"--------Muestreo segun las edades ingresadas----------"<<endl;
	cout<<"Cant. \nPobladores 	Ninos	Jovenes	Adultos	AdultosMayores "<<endl;
	ifstream leerarchivo;
	try {
		leerarchivo.open("HT4_EJERCICIO_O2.txt",ios::in);
		while (getline(leerarchivo,s))
		cout<<s<<endl;
		leerarchivo.close();
	}
	catch (exception X){
		cout<<"Error en la manipulación del archivo"<<endl;
	}
	
	
}
