#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <random>

std::mutex coutMutex;
std::vector<std::string> rank;

void carRace(int carId, int raceDistance){
	int actualDistance = 0;
	
	// Inicializar un generador de números aleatorios independiente para cada hilo
	srand(std::time(0) + carId);
    	
	while(true){
		//Calcular la distancia a avanzar y dormir
    	int avanzar = rand() % 9 + 1;
    	int dormir = rand() % 400 + 100;

		//Duerme para variar la velocidad del auto
		std::this_thread::sleep_for(std::chrono::milliseconds(dormir));		
		
		//Define la distancia actual del auto
		actualDistance = actualDistance + avanzar;		
		
		//Bloquea la salida para evitar que se mezclen los mensajes
		std::lock_guard<std::mutex> lock(coutMutex);

		if(actualDistance >= raceDistance){
			//Estandariza la distancia del auto para evitar que sobrepase la distancia total
			actualDistance = raceDistance;
			int ranking = rank.size() + 1;
			std::cout << "Auto" << carId << " avanza " << avanzar << " metros y ha terminado la carrera en el lugar " << ranking << "!" << std::endl;
			//Añade el auto al ranking final
			rank.push_back("Auto" + std::to_string(carId));
			break;
		}
		
		//Imprime la distancia actual del auto
		std::cout << "Auto" << carId << " avanza " << avanzar << " metros (total: " << actualDistance << " metros)" << std::endl;

	}
}


int main(int argc, char* argv[]){

	if(argc != 3){std::cerr <<"Debe de introducir los parametros <num_autos> <distancia_total>" << std::endl;return 1;}
	
    int distancia = std::stoi(argv[1]);
    int cant_autos = std::stoi(argv[2]);

    if(cant_autos < 2 && distancia < 50){std::cerr <<"La cantidad de autos debe ser mayor o igual a 2 y la distancia debe ser mayor o igual a 50" << std::endl;return 1;}
	if(cant_autos < 2){std::cerr <<"La cantidad de autos debe ser mayor o igual a 2" << std::endl;return 1;}
    if(distancia < 50){std::cerr <<"La distancia debe ser mayor o igual a 50" << std::endl;return 1;}

	std::vector<std::thread> autos;//crea el vector al cual se le asignaran hilos
	
	for(int i=0; i<cant_autos; i++){
		autos.emplace_back(carRace, i+1, distancia);//se le asigna al final del vector creado antriormente un hilo a cada auto
	}

	for (auto& AUTO : autos) {//se itera sobre el propio hilo para confirmar que alguno acabo su proceso
	    AUTO.join();  // Esperar a que cada hilo termine
	}
	
	std::cout << "\n\n..:: ORDEN DE LLEGADA ::.." << std::endl;
	for(int i=0;i<rank.size();i++){
		std::cout << (i + 1) << ". " << rank[i] << std::endl;
	}
	return 0;
}



