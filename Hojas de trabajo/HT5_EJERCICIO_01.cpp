#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cstdlib>
using namespace std;

void ingresar();
void eliminar();
void modificar();
void mp();

int main(){
	mp();
}
//menu principal
void mp(){
	int R;
	
	do {
		system("CLS");
		cout<<"-------------------"<<"\n";
		cout<<"Menu Principal"<<"\n";
		cout<<"-------------------"<<"\n";
		cout<<"1 - Ingresar Datos "<<"\n";
		cout<<"2 - Eliminar"<<"\n";
		cout<<"3 - Modificar"<<"\n";
		cout<<"4 - Salir"<<"\n";
		cout<<"-------------------\n";
		cout<<"Seleccione su opcion: ";
		cin>>R;
		if (R==1)
			ingresar();
		else if (R==2) 	
			eliminar();
		else if (R==3)
			modificar();			
		else if (R==4)
			break;
		else 
			break;
		
	} while(R!=4);	
}
//ingreso de datos
void ingresar(){
	int i;
	int modelo;
	int cant;
	int m1=0;	//modelo 1
	int m2=0;	//modelo 2
	float m3=0; //modelo 3
	int m4=0;	//modelo 4
	int mm1=0;	//conteo de modelo 1 
	int mm2=0;	//conteo de modelo 2 
	int mm3=0;	//conteo de modelo 3
	int mm4=0;	//conteo de modelo 4	
	string s;
	
	for(i=1; i<31;i++){
//modelo
		cout<<"=========================ESTE PROGRAME LE MOSTRARA SU REPORTE CADA VEZ QUE INGRESE UNA VENTA======================="<<endl;
		cout<<"--------------------------------------Digite el NUMERO del modelo de cuaderno-------------------------------------"<<endl;
		cout<<"Modelo #1 = Q10.00"<<endl;
		cout<<"Modelo #2 = Q15.00"<<endl;
		cout<<"Modelo #3 = Q18.50"<<endl;
        cout<<"Modelo #4 = Q25.00"<<endl;
        cin>>modelo;
//cantidad
        cout<<"Digite la cantidad de unidades: "<<endl;
        cin>>cant;
//calculo para la cantidad recaudada por modelo // sumatoria para ver cual fue el mas vendido 
        if(modelo==1){
        	m1=m1+(cant*10);	
        	mm1=mm1+1;
        }
        if(modelo==2){
        	m2=m2+(cant*15);
			mm2=mm2+1;	
        }
        if(modelo==3){
        	m3=m3+(cant*18.50);	
        	mm3=mm3+1;
        }
        if(modelo==4){
        	m4=m4+(cant*25);	
        	mm4=mm4+1;
        }      
//agregar y leer archivo
	cout<<"-------------------------------------------------------Su pedido fue--------------------------------------------------"<<endl;
	cout<<"DIA: "<<i<<"\n"<<"MODELO: "<<modelo<<"\n"<<"CANTIDAD: "<<cant<<"\n";
	ofstream grabararchivo;
	try {
		grabararchivo.open("planilla.txt",ios::app);
		grabararchivo<<i<<"\t"<<modelo<<"\t"<<cant<<endl;
		grabararchivo.close();
	}
	catch(exception X){
		cout<<"Error en la manipulacion del archivo"<<endl;
	}
//total de ventas 
	cout<<"\n"<<"========================================Todas Las Ventas Actuales==============================================="<<endl;
	cout<<"DIA//MODELO//CANTIDAD"<<endl;
	ifstream leerarchivo;
	try {
		leerarchivo.open("planilla.txt",ios::in);				
		while (getline(leerarchivo, s))
			cout<<s<<endl;		
		leerarchivo.close();
	}
	catch(exception X){
		cout<<"Error en la manipulacion del archivo"<<endl;
	}          
//recaudacion por cada modelo
	cout<<"==============================================Total recaudado por cada modelo========================================="<<endl;
	cout<<"MODELO 1//MODELO 2//MODELO 3//MODELO 4"<<endl;
	cout<<"Q"<<m1<<"\t"<<"\t"<<"Q"<<m2<<"\t"<<"Q"<<m3<<"\t"<<"Q"<<m4<<endl;
//modelo mas vendido 
	cout<<"================================================Modelo mas vendido===================================================="<<endl;
	if(mm1 > mm2 && mm1 > mm3 && mm1 > mm4){
       	cout<<"El mas vendido fue el modelo 1 "<<endl;
    }
	else if(mm2 > mm1 && mm2 > mm3 && mm2 > mm4){
		cout<<"El mas vendido fue el modelo 2 "<<endl;
    }
	else if(mm3 > mm1 && mm3 > mm2 && mm3 > mm4){
		cout<<"El mas vendido fue el modelo 3 "<<endl;
    }
	else{
		cout<<"El mas vendido fue el modelo 4 "<<endl;
	}
}
}
//eliminar datos
void eliminar(){
	ifstream db_a; //archivo anterior
	ofstream db_n; //archivo nuevo
	int aux,i,modelo,canti,flag;
	remove("Temporal.txt");
	
	db_a.open("planilla.txt",ios::in);
	db_n.open("Temporal.txt",ios::app);
	
	cout<<"Ingrese ID que desea borrar: "<<endl;
	cin>>aux;
	
	while (db_a>>i>>modelo>>canti){
		if(aux==i){
			cout<<"Registro Eliminado...."<<endl;
			flag =1;
		}			
		else if(aux!=i)
			db_n<<i<<"\t"<<modelo<<"\t"<<canti<<endl;
		//aux=0;
		//oid=0;					
	}
	db_a.close();
	db_n.close();
	
	if (flag==1){
		remove("planilla.txt");
		rename("Temporal.txt","planilla.txt");
	}	
	system("Pause");
}
//modificar datos
void modificar(){
	ifstream db_a; //archivo anterior
	ofstream db_n; //archivo nuevo
	int i,modelo,cantidad_n,cantidad_a,flag,aux;//Debo declarar cantidad_n y cantidad_a
	char respuesta;
	remove("Temporal.txt");
	
	db_a.open("planilla.txt",ios::in);
	db_n.open("Temporal.txt",ios::app);
	
	cout<<"Ingrese ID al que modificara informacion: "<<endl;
	cin>>aux;
	do {
		cout<<"Ingrese la cantidad de unidades a modificar: "<<endl;
		cin>>cantidad_n;//Modificando cantidad nueva
		cout<<"\n\nEsta Seguro? S/N";
		cin>>respuesta;
		cout<<"\n"<<endl;
		respuesta = toupper(respuesta);		
	} while (respuesta!='S');	
	
	//leer archivo anterior
	while (db_a>>i>>modelo>>cantidad_a){//Recorre el archivo junto con la cantidad anterior sin modificar
		if(aux==i){
			db_n<<i<<"\t"<<modelo<<"\t"<<cantidad_n<<endl;//Manda al archivo la cantidad nueva ya modificada
			cout<<"Archivo Actualizado...."<<endl;
			flag =1;
		}			
		else if(aux!=i)
			db_n<<i<<"\t"<<modelo<<"\t"<<cantidad_a<<endl;
		//aux=0;
		//oid=0;					
	}
	db_a.close();
	db_n.close();
	
	if (flag==1){
		remove("planilla.txt");
		rename("Temporal.txt","planilla.txt");
	}	
	system("Pause");
}
