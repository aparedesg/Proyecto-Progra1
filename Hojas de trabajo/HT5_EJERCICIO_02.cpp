/*EJERCICIO#2
Realice un programa que, dado el peso, la altura, la edad y el género (M/F) de un grupo de N personas
que pertenecen a un departamento de la república, obtenga un promedio de peso, altura y edad de esta
población. Los datos deben guardarse de forma ordenada por edad en un archivo de datos. Así mismo
el programa debe ser capaz leer los datos del archivo y generar un reporte con la media del peso, altura
y la edad. */

#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

 //creo mi estructura
struct depto{
	float peso;
	float altura;
	int   edad;
	int   genero;
	float promedio;
	float suma;
};
 //creo mis funciones
void datos();
void reporte();
int main(){
 	 datos();
 	reporte();
 }
 
 //comienzo a utilizar mis funciones
void datos(){
	float  peso;
	float  altura;
	int    edad;
	int    genero;
	//float  promedio;
	float  suma=0;
	float  tp, te, ta, tg;
	//float  pro_p=0, pro_e=0, pro_a=0, pro_g=0;
	string s;
	int    c;
	int    N;
	//int datos;
	
	cout<<"__________________Pobladores del departamento_________________"<<endl;
	cout<<"Ingrese si la persona es de sexo Femenino: 1, o Masculino: 0:  ",cin>>genero;
	//cout<<"Ingrese cantidad de pobladores a registrar: ",cin>>N;
	cout<<"Escriba la edad: ",  cin>>edad;
	cout<<"Ingrese la altura: ",cin>>altura;
	cout<<"Ingrese el peso: ",  cin>>peso;
	
	if (genero==1)
	cout<<"\nSexo femenino"<<endl;
	else if (genero==0)
	cout<<"\nSexo masculino"<<endl;
	else 
	cout<<"Error"<<endl;
	
	cout<<"\nPeso: "<<peso<<"\t"<<"Edades: "<<edad<<"\t"<<"Altura: "<<altura<<"\t"<<"Genero: "<<genero<<endl;
	
//Grabar archivo:
	
	ofstream grabararchivo;
	
	try{
		grabararchivo.open("HT5_EJERCICIO_02.txt", ios::app);
		grabararchivo<<peso<<"\t"<<edad<<"\t"<<altura<<"\t"<<genero<<endl;
		grabararchivo.close();
	}
	catch (exception X){
		cout<<"Error en la manipulación del archivo"<<endl;
	}
	
	cout<<"\n______________Datos Pobladores_________________"<<endl;
	cout<<"\tPeso	Edad Altura Genero"<<endl;

	ifstream leerarchivo;
	try{
		leerarchivo.open("HT5_EJERCICIO_02.txt",ios::in);
		while (getline(leerarchivo,s))
			cout<<"\t"<<s<<endl;
		leerarchivo.close();
	}
	catch(exception X){
		cout<<"Error en la manipulación del archivo"<<endl;
	}
}

	//leer archivo
void reporte(){
	ifstream db;
	int gene, eda;
	std::vector< int > edades;
	float pes, altu;
	float suma=0, cp=0, ce=0, ca=0, cgf=0, cgm=0, sump=0, sume=0, sumaa=0, sumagf=0, sumagm=0;
	int M, F, cantf, cantm;
	float  pro_p=0, pro_e=0, pro_a=0, pro_gf=0, pro_gm=0;
	
		try{
			db.open("HT5_EJERCICIO_02.txt",ios::in);
		 
			while(db>>pes>>eda>>altu>>gene){
				suma+=1;
				if (gene=0){
				gene+=suma;
				}
	   	
	   			if (pes>0){
	   				cp=pes;
	   				pro_p=(sump+=pes)/suma;
		   		}
		   		if (eda>0){
		   			ce=eda;
		   			pro_e=(sume+=eda)/suma;
				}
				if (altu>0){
					ca=altu;
					pro_a=(sumaa+=altu)/suma;
				}
				edades.push_back(eda);
		   	}
		   	
		   		for(int i=0;i<suma;i++){
					for (int j=0;j<suma;j++){
						if(edades[i]<edades[j]){
		        			int temp = edades[i];
		            		edades[i]=edades[j];
		            		edades[j] = temp;
		        		}
		    		}
			//ciclos++;
				}
		   	
			db.close();
			
			cout<<setprecision(10)<<"\nNo. de personas es: "<<suma<<"\t"<<cout<<setprecision(10)<<"Media de peso: "<<pro_p<<endl;
			cout<<setprecision(10)<<"Media de edad: "<<pro_e<<"\t"<<cout<<setprecision(10)<<"Media de altura: "<<pro_a<<endl;
			cout<<setprecision(10)<<"Edades ordenadas:"<<endl;
			for(int i=0;i<suma;i++){
      		cout<<setprecision(10)<<"\t \t"<<edades[i]<<endl;
		}
			
		}
	catch (exception X){		
			cout<<"Error en la manipulación del archivo"<<endl;			
			exit(1);
	}
	
	
	
	
	
	
	
	
	
	
}
		
		
 
