#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <random>

std::mutex coutMutex;
std::vector<std::string> rank;

void funcionHebra(int id){
	std::cout << "Hebra" << id << " esta ejecutandose.\n";
}

void carRace(int carId, int raceDistance){
	int actualDistance = 0;
	
	// Inicializar un generador de números aleatorios independiente para cada hilo
	srand(std::time(0) + carId);
    	
    	
	while(true){
		//Calcular la distancia a avanzar
    	int avanzar = rand() % 9 + 1;
    	int dormir = rand() % 400 + 100;
		
		actualDistance = actualDistance + avanzar;
		
		std::lock_guard<std::mutex> lock(coutMutex);
		
		if(actualDistance >= raceDistance){
			actualDistance = raceDistance;
			std::cout << "Auto " << carId << " ha terminado la carrera!" << std::endl;
			rank.push_back("Auto" + std::to_string(carId));

			break;
		}
		
		std::cout << "Auto " << carId << ": " << actualDistance << " metros." << std::endl;
		
		std::this_thread::sleep_for(std::chrono::milliseconds(dormir));
	}
}

int main(int argc, char* argv[]){

	if(argc != 3){std::cerr <<"Debe de introducir los parametros <num_autos> <distancia_total>" << std::endl;return 1;}
	
    int cant_autos = std::stoi(argv[1]);
	int distancia = std::stoi(argv[2]);
	
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



