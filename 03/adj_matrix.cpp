#include <fstream>
#include <iostream>
#include <sstream>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

// Assignment 4, CS 4071, Spring 2018
// Group 13: Robert DiMartino, Jeremiah Leak, Hayden Schiff

//
// Utility functions
//

// vectorMax
// Input: vector v
// Returns value of max item of a vector
template <class T>
T vectorMax(vector<T> v) {
	int max = v[0];
	for (int i=1; i<v.size(); i++) {
		if (max < v[i]) {
			max = v[i];
		}
	}
	return max;
}

// vectorContains
// Inputs: vector v, item
// Return true if v contains item, false otherwise
template <class T>
bool vectorContains(vector<T> v, T item) {
	for (int i=0; i<v.size(); i++) {
		if (v[i] == item) {
			return true;
		}
	}
	return false;
}

//
// Graph class
//

class Graph {
public:
	int size;
	vector< vector<int> > matrix;
	// Constructors
	Graph() { int size = 0; }
	Graph(int n) {
		size = n;
		matrix.resize(size,vector<int>(size));
	}
	~Graph();
	// addEdge
	// Inputs: a, b - int nodes
	// Creates an edge in the adjaceny matrix between
	// nodes a and b
	void addEdge(int a, int b) {
		if (a < 0 || a >= size || b < 0 || b >= size || a == b) {
			throw "Vertex is outside range of vertices";
		}
		matrix[a][b] = 1;
		matrix[b][a] = 1;
	}
	// printMatrix
	// Display the adjacency matrix
	void printMatrix() {
		cout << "[";
		for (int i=0; i<size; i++) {
			cout << "[";
			for (int j=0; j<size; j++) {
				cout << matrix[i][j] << (j < size-1 ? ",\t" : "");
			}
			cout << "]" << (i < size-1 ? "\n" : "");
		}
		cout << "]" << endl;
	}
};

// createGraph
// Input: vector of int instructions. The instructions specification is in the
// program help, run with '--help' or '-h'.
// Output: Graph object G
Graph* createGraph(queue<int>& input) {
	// Check that a size was provided and is valid
	int size;
	if (input.empty()) {
		throw "No graph size provided";
	}
	size = input.front();
	if (size <= 0) {
		throw "Graph size must be greater than 0";
	}
	input.pop();
	Graph* G = new Graph(size);

	// Add an edge for each pair of nodes
	int a,b;
	while(!input.empty()) {
		a = input.front();
		input.pop();
		if (input.empty()) {
			throw "All edges must be specified in pairs";
		}
		b = input.front();
		input.pop();
		G->addEdge(a,b);
	}

	return G;
};

// BFS - breadth first search
// Inputs:
//   G - Graph object to search
//   v - starting node
// Outputs: vector of distances from v to each node to in G
vector<int> BFS(Graph* G, int v) {
	int size = G->size;
	if (v >= size) {
		throw "Vertex not included in the graph";
	}
	queue<int> Q;
	vector<int> visited(size);
	vector<int> d(size, -1);

	Q.push(v);
	visited[v] = 1;
	d[v] = 0;
	int distance = 0;
	int u, w;
	while(!Q.empty()){
		u = Q.front();
		Q.pop();
		distance ++;
		for (int i = 0; i < size; i++) {
			if (G->matrix[u][i] == 1) {
				w = i;
				if (visited[w] == 0) {
					d[w] = distance;
					Q.push(w);
					visited[w] = 1;
				}
			}
		}
	}
	return d;
};

// Diameter
// Input: Graph object G
// Output: Diameter of G if G is connected, -1 otherwise
int Diameter(Graph* G) {
	int size = G->size;
	int diameter = 0, d = 0;
	vector<int> distances;
	// For each node  in G, find the max distance from that node to every other.
	// Update diameter if distance from the node is greater than the current max.
	for (int i = 0; i < size; i++) {
		distances = BFS(G, i);
		// Distances are initialized to -1
		// If any distance is still -1, the Graph is not connected.
		if (vectorContains(distances, -1)) {
			return -1;
		}
		d = vectorMax(distances);
		if (diameter < d) {
			diameter = d;
		}
	}
	return diameter;
};

// Components
// Input: Graph object G
// Output: Vector of vectors of the indices for each node in each connected
// component in G.
vector< vector<int> > Components(Graph* G) {
	int size = G->size;
	vector<int> discovered(size);
	vector<int> distances;

	vector< vector<int> > components;
	vector<int> component;

	// For each node in G, use BFS to find the connected components
	for (int i=0; i < size; i++) {
		// Only perform BFS on undiscovered nodes.
		if (discovered[i] == 0) {
			component.resize(0);
			distances = BFS(G, i);
			// All nodes with non-zero distance are in the same connected component.
			// Add the nodes to the component and flag the nodes as discovered.
			for (int j=0; j < distances.size(); j++) {
				if (distances[j] >= 0) {
					discovered[j] = 1;
					component.push_back(j);
				}
			}
			// Add the component to the vector of components
			components.push_back(component);
		}
	}

	return components;
};

//
// Help
//

// displayHelp
void displayHelp() {
	cout << "usage: graphTool [-h|--help] [filename]" << endl << endl;
	cout << "  -h | --help : print usage instructions" << endl;
	cout << "     filename : name of file containing graph input (uses test input if no filename given)" << endl << endl;
	cout << "graph file input format: n edges... q" << endl << endl;
	cout << "      n : number of vertices" << endl;
	cout << "  edges : zero or more pairs of whitespace delimited vertices between 0 and n-1" << endl;
	cout << "      q : negative integer sentinel to indicate the end of the input" << endl << endl;
	cout << "example file:" << endl << endl;
	cout << "  5 0 1 1 4 2 3 1 3 3 4 -1" << endl << endl;
	cout << "  Produces the graph G = (V,E) given by" << endl;
	cout << "    V = {0,1,2,3,4}" << endl;
	cout << "    E = {{0,1},{1,4},{2,3},{1,3},{3,4}}" << endl << endl;
	cout << "output: the adjacency matrix of the graph, also" << endl;
	cout << "  if the graph G is connected: the diameter" << endl;
	cout << "  if the graph G is not connected: the vertex set of each connected component" << endl << endl;
}

// main
// Inputs:
//   argc - argument count - int of command line arguments, always at least 1 because the program name is an argument
//   argv - argument vector - array of character pointers listing all the arguments, argv[0] is program name
int main(int argc, char* argv[])
{
	queue<int> input;
	Graph* G;

	try {

		string word;
		int num;
		istream *graphInput;

		// Use default string input if no filename given
		if (argc < 2) {
			string defaultInput = "5  0  1  1  4  2  3  1  3  3  4  -1";
			graphInput = new istringstream(defaultInput);
		} else {
			// Exit if help option provided
			if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
				displayHelp();
				return EXIT_SUCCESS;
			}

			// Open input file as stream
			graphInput = new ifstream(argv[1]);
			if (!graphInput) {
				throw "Provided file does not exist";
			}
		}
		// Add ints to input queue until sentinel integer or EOF
		while((*graphInput) >> word) {
			num = stoi(word);
			if (num < 0) {
				break;
			}
			input.push(num);
		}

		// Check input terminated properly
		if (num >= 0) {
			throw "Input not terminated with negative integer sentinel";
		}
	}
	// Catch input errors
	catch(const char* msg) {
		cerr << "Error: " << msg << endl << endl;
		displayHelp();
		return EXIT_FAILURE;
	}
	catch (const invalid_argument& e) {
		cerr << "Invalid input: " << e.what() << endl;
		cerr << "All inputs must be integers" << endl;
		return EXIT_FAILURE;
	}

	try {
		// Build graph from input
		G = createGraph(input);

		// Print results
		cout << "Adjacency matrix:" << endl;
		G->printMatrix();

		int diam = Diameter(G);
		if (diam > -1) {
			cout << "Diameter: " << diam << endl;
		} else {
			cout << "Graph is not connected" << endl;
			cout << "Components:" << endl;
			vector< vector<int> > components = Components(G);
			int cSize = 0;
			for (int i=0; i<components.size(); i++) {
				cout << i << ": {";
				cSize = components[i].size();
				for (int j=0; j<cSize; j++) {
					cout << components[i][j] << (j < cSize-1 ? ", " : "");
				}
				cout << "}" << endl;
			}
		}
	}
	// Catch errors with the Graph
	catch(const char* msg) {
		cerr << "Error: " << msg << endl << endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
