#include <iostream>
#include <vector>
#include <list>

struct vertix {
	int v;
	std::list<struct vertix*> adjacencies;
};

class Graph {
private: 
	int V;
	int E;
	std::vector<vertix> vertices;
public:
	Graph(int V, int E) {
		this->V = V;
		this->E = E;
	}

	void addVertix(int value) {
		struct vertix node;
		node.v = value;
		vertices.push_back(node);
	}

	void addEdge(int u, int v) {
		vertices[u-1].adjacencies.push_back(&vertices[v-1]);
	}

	int getNumberVertices(){
		return V;
	}
};


int main() {
	std::string inputN, inputM;
	std::string inputVertix;
	std::string inputU, inputV;

	getline(std::cin, inputN, ',');
	getline(std::cin, inputM);
	
	const int N = std::stoi(inputN);
	const int M = std::stoi(inputM);



	Graph *graph = new Graph(N, M);


	for(int i = 0; i < N; i++) {
		getline(std::cin, inputVertix);
		const int value = std::stoi(inputVertix);
		graph->addVertix(value);
	}

	for(int i = 0; i < M; i++) {
		getline(std::cin, inputU, ' ');
		getline(std::cin, inputV);
		const int U = std::stoi(inputU);
		const int V = std::stoi(inputV);
		graph->addEdge(U, V);
	}

	struct vertix* verticeMaxGrade;
	for(int i = 0; i < graph->getNumberVertices(); i++){
		if(verticeMaxGrade == NULL){
			
		}
	}



    return 0;
}
