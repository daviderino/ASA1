#include <iostream>
#include <vector>
#include <list>

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
	std::vector<vertix> vertices;
public:
	Graph(int V, int E) {
		this->V = V;
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

	int getCorrectedCount() {
        return correctedCount;
	}

	int getIMax() {
	    int m = 0;
	    int index = -1;
	    for(unsigned int i = 0; i < vertices.size(); i++) {
	        if(!vertices[i].corrected && vertices[i].v > m) {
	            m = vertices[i].v;
	            index = i;
	        }
	    }
		max = m;

        return index;
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

	void DFS(int vertex) {
	    DFSAux(getVertix(vertex));
	}
};

int main() {
	std::string inputN, inputM;
	std::string inputVertix;
	std::string inputU, inputV;
    int imax = -1;
	int max = 0;

	getline(std::cin, inputN, ',');
	getline(std::cin, inputM);
	
	const int N = std::stoi(inputN);
	const int M = std::stoi(inputM);

	Graph *graph = new Graph(N, M);

	for(int i = 0; i < N; i++) {
		getline(std::cin, inputVertix);
		const int value = std::stoi(inputVertix);
		graph->addVertix(value);

		if(value >= max) {
		    max = value;
		    imax = i;
		}
	}

	graph->setMax(max);

	for(int i = 0; i < M; i++) {
		getline(std::cin, inputU, ' ');
		getline(std::cin, inputV);
		const int U = std::stoi(inputU);
		const int V = std::stoi(inputV);
		graph->addEdge(V, U);
	}

	while(graph->getCorrectedCount() != graph->getNumberVertices()) {
        graph->DFS(imax);
        imax = graph->getIMax();
    }

	for(int i = 0; i < graph->getNumberVertices(); i++){
		std::cout << graph->getVerticeGrade(i) << std::endl; 
	}

	delete graph;

    return 0;
}
