#include <iostream>
#include <vector>

struct vertix {
	int v;
	bool visited = false;
	bool corrected = false;
	std::vector<struct vertix*> adjacencies;
};

class Graph {
private: 
	int V;
	int max;
	int correctedCount = 0;
	int iterator;
	vertix* vertices;
public:
	Graph(int V) {
		this->V = V;
		vertices = new vertix[V];
	}

	void addVertix(int value) {
		vertices[iterator].v = value;
		iterator++;
	}

	void addEdge(int u, int v) {
		vertices[u-1].adjacencies.push_back(&vertices[v-1]);
	}

	int getNumberVertices(){
		return V;
	}

	int getCorrectedCount() {
        return correctedCount;
	}

	struct vertix* getVertix(int i) {
        return &vertices[i];
	}

	void setMax(int m) {
	    max = m;
	}

	int getVerticeGrade(int i){
		return vertices[i].v;
	}

    void DFSAux(struct vertix* v) {
        v->visited = true;
        v->corrected = true;
        v->v = max;
        correctedCount++;

        for(struct vertix* u: v->adjacencies) {
            if(!u->visited && !u->corrected) {
                DFSAux(u);
            }
        }
    }

	void DFS(struct vertix* v) {
		max = v->v;
	    DFSAux(v);
	}
};

int main() {
	std::string inputN, inputM;
	std::string inputVertix;
	std::string inputU, inputV;
	std::vector<struct vertix*> orderedVertices[21];

	getline(std::cin, inputN, ',');
	getline(std::cin, inputM);
	
	const int N = std::stoi(inputN);
	const int M = std::stoi(inputM);

	Graph *graph = new Graph(N);

	for(int i = 0; i < N; i++) {
		getline(std::cin, inputVertix);
		const int value = std::stoi(inputVertix);
		graph->addVertix(value);

		orderedVertices[value].push_back(graph->getVertix(i));
	}

	for(int i = 0; i < M; i++) {
		getline(std::cin, inputU, ' ');
		getline(std::cin, inputV);
		const int U = std::stoi(inputU);
		const int V = std::stoi(inputV);
		graph->addEdge(V, U);
	}

	for(int a = 20; a >= 0; a--) {
		for(vertix* v: orderedVertices[a]) {
			if(graph->getCorrectedCount() == graph->getNumberVertices()) {
				a = -1;
				break;
			}
			if(!v->corrected){
				graph->DFS(v);
			}
		}
	}

	for(int i = 0; i < graph->getNumberVertices(); i++){
		std::cout << graph->getVerticeGrade(i) << std::endl; 
	}

    return 0;
}
