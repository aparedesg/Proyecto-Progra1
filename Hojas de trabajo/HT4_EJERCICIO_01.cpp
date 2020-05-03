/*Ejercicio#1
En la región de la sierra de los Cuchumatanes la compañía Xterminio s.a. , tiene las siguientes tarifas:
Tipo Servicio 	 Costo X Hectárea
 1	Mala hierba	 		10.00
 2	Langostas			20.00
 3	Gusanos				30.00
 4	Todo lo anterior	50.00
Además del área a fumigar es mayor a 500.00 hectáreas se tiene un descuento del 5%. Adicionalmente,
si el total a pagar por el servicio es mayor a Q1500.00 se tiene un descuento adicional del 10% sobre el
excedente.
La compañía necesita las estadísticas de los servicios que ha ofrecido a un grupo de agricultores durante
un periodo de tiempo. Por cada servicio debe ingresar los datos siguientes: Tipo de Fumigación (1 a 4) y
el número de hectáreas, toda esta información deberá almacenarse en una base de datos (archivo plano).
Se le pide que realice un programa en C++ que solicite el ingreso de la información de cada servicio
realizado a un grupo de agricultores. El programa deberá de leer los datos del archivo que tiene la
información antes almacenada y mostrar la cantidad de servicios de cada tipo de fumigación, determinar
el tipo servicio con mayor demanda y el monto total pagado por los clientes.*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

struct fumigar{
	int	tipo_fumi;
	int numero_hect;
	float monto_total;
	float calculo_descuen;
};

//Declaro las funciones que utilizaré
void descuentos();
void reporte();
int main(){
	descuentos();
	reporte();
	
}
//utilizo la función
void descuentos(){
	int tipo_fumi=0;
	int numero_hect;
	float calculo_descuen;
	float total=0;
	string s;
	//int t1,t2,t3,t4,suma=0,SUMA=0,resultado=0,RESULTADO=0;
	fflush(stdin);
	cout<<"-----------------Compania Xterminio S.A--------------------"<<endl;
	cout<<"Hola! Por favor ingrese que tipo de servicio desea: "<<endl;
	cout<<"1	Mala hierba	 		10.00"<<endl;
 	cout<<"2	Langostas			20.00"<<endl;
 	cout<<"3	Gusanos				30.00"<<endl;
 	cout<<"4	Todo lo anterior		50.00"<<"\n"<<endl;
	cin>>tipo_fumi;
	fflush(stdin);
	cout<<"\n"<<"Ingrese el No. de hectareas: ";cin>>numero_hect;

	if (tipo_fumi==1 && numero_hect<=500){
		total=10*numero_hect;
	}
	else if (tipo_fumi==2 && numero_hect<=500){
		total=20*numero_hect;
	}
	else if (tipo_fumi==3 && numero_hect<=500){
		total=30*numero_hect;
	}
	else if (tipo_fumi==4 && numero_hect<=500){
		total=50*numero_hect;
	}
	if (tipo_fumi==1 && numero_hect>500){
		calculo_descuen=(10*numero_hect)*0.05;
		total=calculo_descuen;
	}
	else if (tipo_fumi==2 && numero_hect>500){
		calculo_descuen=(20*numero_hect)*0.05;
		total=calculo_descuen;
	}
	else if (tipo_fumi==3 && numero_hect>500){
		calculo_descuen=(30*numero_hect)*0.05;
		total=calculo_descuen;
	}
	else if (tipo_fumi==4 && numero_hect>500){
		calculo_descuen=(50*numero_hect)*0.05;
		total=calculo_descuen;
	}
	if (total>1500){
		total=total*0.1;
	}
	cout<<"Tipo de servicio: "<<tipo_fumi<<"\t"<<"Numero de hectareas: "<<numero_hect<<"\t"<<"Total a pagar: "<<total<<endl;
	ofstream grabararchivo;
	try {
		grabararchivo.open("HT4_EJERCICIO_O1.txt",ios::app);
		grabararchivo<<tipo_fumi<<"\t"<<numero_hect<<"\t"<<total<<endl;
		grabararchivo.close();
	}
	catch (exception X){
		cout<<"Error en la manipulación del archivo"<<endl;
	}
	cout<<"\n"<<"--------Estadisticas de los Servicios----------"<<endl;
	cout<<"Tipo de fumigacion      Numero de hectareas      Total"<<endl;
	ifstream leerarchivo;
	try {
		leerarchivo.open("HT4_EJERCICIO_O1.txt",ios::in);
		while (getline(leerarchivo,s))
		cout<<s<<endl;
		leerarchivo.close();
	}
	catch (exception X){
		cout<<"Error en la manipulación del archivo"<<endl;
	}
}
void reporte(){
	ifstream db;
	int tipo_f, numhect, totalp=0;
	//int n;
	float sumatotal=0;
	float tipo_f1=0;
	float tipo_f2=0;
	float tipo_f3=0;
	float tipo_f4=0;
	//int c;
	try {
			db.open("Fumigadora.txt",ios::in);
		
		while(db>>tipo_f>>numhect>>totalp){
			sumatotal=totalp+sumatotal;
			if (tipo_f==1)
				tipo_f1+=totalp;
			else if(tipo_f==2)
				tipo_f2+=totalp;
			else if(tipo_f==3)
				tipo_f3+=totalp;	
			else if(tipo_f==4)
				tipo_f4+=totalp;
		}
	
		db.close();
		
		cout<<setprecision(10)<<"Total Servicios "<<sumatotal<<endl;
	}
	catch (exception X){
		cout<<"Fallo al abrir el archivo"<<endl;
		exit(1);
	}
}
