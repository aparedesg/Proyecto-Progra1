/*En la Pizzeria "Gran sabor" se tienen las siguientes ofertas:
Por la compra de una pizza grande (Q80.00), recibe un descuento de 10%
Por la compra de una pizza familiar (Q115.00), recibe un descuento de 15%
Por la compra de una pizza fiesta(Q100.00), recibe un descuento de 20%

Solicitar el tipo de pizza, el precio unitario y hallar el precio a pagar.

Grabar los datos a un archivo y mostrar el total global de la venta del dia y
determinar el total de lo vendido por producto, mostrando tambien el porcentaje
con relacion al total.*/

#include <fstream>
#include <iostream>
#include <string>
using namespace std;
//Creo mi Estructura Principal
struct pizzeria{
	int tipo_pizza;
	int cantidad;
	float calculo;
	float total_a_pagar;
	//float c_p_g = 0;

};
//Llamo a las funciones con las que trabajaré
//void mp();
void leer_archivo();
void grabar_archivo();
//Dentro del programa mando a llamar al Menú Principal
int main(){
	//mp();
}
//Creo mi función del Menú Principal
/*void mp(){
	int resp;
	do {
		system("CLS");
		cout<<"-------------------------------------"<<"\n";
		cout<<" Menu Principal Pizzeria Gran Sabor"<<"\n";
		cout<<"-------------------------------------"<<"\n";
		cout<<" 1 - Nueva venta de pizza "<<"\n";
		cout<<" 2 - Mostrar la venta del dia "<<"\n";
		cout<<" 3 - Salir"<<"\n";
		cout<<"-------------------------------------"<<"\n";
		cout<<" Seleccione su opcion: ";
		cin>>resp;
		if (resp==1){		
			system("CLS");
			grabar_archivo();			
		}
		else if (resp==2){		
			system("CLS");
			leer_archivo();
		}			
		else if (resp==3)
			break;
		else 
			break;
		
	} while(resp!=3);
}*/
//Creo mi funcion para grabar datos al archivo
void grabar_archivo(){
	//variables basadas en la estructura
	int tipo_pizza;
	int cantidad_pizzas;
	float calculo;
	float total_a_pagar;
	
	fflush(stdin);
	cout<<"Ingrese el tipo de pizza que desea: "<<endl<<"1:Grande"<<"\t"<<"2:Familiar"<<"\t"<<"3:Fiesta"<<endl;
	cin>>tipo_pizza;
	fflush(stdin);
	cout<<"Ingrese la cantidad de pizzas que desea: "<<endl;
	cin>>cantidad_pizzas;
//Establezco las condiciones planteadas
	if (tipo_pizza == 1) {
      	calculo=cantidad_pizzas*80;
      	total_a_pagar=calculo-(calculo*0.10);
      	cout<<total_a_pagar;
      	}
	else if (tipo_pizza == 2){
	  	calculo=cantidad_pizzas*115;
      	total_a_pagar=calculo-(calculo*0.15);
      	cout<<total_a_pagar;	
	   }
	else{
	  	calculo=cantidad_pizzas*100;
      	total_a_pagar=calculo-(calculo*0.20);
      	cout<<total_a_pagar;	
	   }

	
//Agregamos datos al archivo
	ofstream archivo; 
	archivo.open("pizzeria.txt",ios::app);
	archivo<<tipo_pizza<<"\t"<<cantidad_pizzas<<"\t"<<total_a_pagar<<endl;
	archivo.close();
}
//Creo mi funcion para leer el archivo
void leer_archivo(){
	ifstream archivo; //leer archivo 
	archivo.open("pizzeria.txt",ios::in);
	cout << "---------------------------------------------" << endl;
	cout << "TIPO DE PIZZA"<< "\t" << "CANTIDAD" << "\t" <<"\t"<< "TOTAL EN DINERO Q." << endl;
	cout << "---------------------------------------------" << endl; 
	int lineas,i=0;
	string s,linea;
	float sumatoriaventa=0.00;	
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo!!!";
		exit(1); //break;
	}
	while (getline(archivo, s))
        lineas++;
	archivo.close();
	
	pizzeria recordset[lineas];
	
	archivo.open("pizzeria.txt",ios::in);
		if(archivo.fail()){
		cout<<"No se pudo abrir el archivo!!!";
		exit(1);
	}	
//Leer datos del archivo
	for (int i = 0; i < lineas; i++)
    {
        if (!archivo)
        {                                               
            cerr << "No se puede abrir el archivo " << endl;
            system("PAUSE");
        }
        archivo>>recordset[i].tipo_pizza>>recordset[i].cantidad>>recordset[i].total_a_pagar;
    }
    archivo.close(); 
    for(int i = 0; i < lineas; i++){
    	cout<<recordset[i].tipo_pizza<<"\t"<<"\t"<<recordset[i].cantidad<<"\t"<<"\t"<<"\t"<<recordset[i].total_a_pagar<<endl;
    	
    	sumatoriaventa+=recordset[i].total_a_pagar;
	}
	cout<<endl<<"Total Venta del Dia: "<<"Q."<<sumatoriaventa<<endl<<endl;
	
	system("PAUSE");
}
