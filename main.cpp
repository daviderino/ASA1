#include <iostream>
#include <vector>

struct vertix {
	int v;
	struct vertix* next;
};

class Graph {
private: 
	int V;
	int E;
	std::vector<vertix> adj;
public:
	Graph(int V, int E) {
		this->V = V;
		this->E = E;
	}

	void addVertix(int v) {
		struct vertix node;
		node.v = v;
		node.next = nullptr;
		adj.push_back(node);
	}

	void addEdge(int u, int v) {
		adj[u-1].next = &adj[v-1];
	}

};


int main() {
	std::string input1, input2;
	std::string inputVertix;

	getline(std::cin, input1, ',');
	getline(std::cin, input2);
	
	const int N = std::stoi(input1);
	const int M = std::stoi(input2);

	Graph *graph = new Graph(N, M);


	for(int i = 0; i < N; i++) {
		getline(std::cin, inputVertix);
		const int value = std::stoi(inputVertix);
		graph->addVertix(value);
	}

	for(int i = 0; i < M; i++) {

	}

    return 0;
}
