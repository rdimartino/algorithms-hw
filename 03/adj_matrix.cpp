#include <fstream>
#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

class Graph {
public:
  int size;
  vector< vector<int> > matrix;
  Graph();
  Graph(int n) {
    size = n;
    matrix.resize(size,vector<int>(size));
  }
  ~Graph();
  void addEdge(int a, int b) {
    if (a < 0 || a >= size || b < 0 || b >= size || a == b)
      throw "Vertex is outside range of vertices";
    matrix[a][b] = 1;
    matrix[b][a] = 1;
  }
  void printMatrix() {
    cout << "[";
    for(int i=0; i<size; i++) {
      cout << "[";
      for(int j=0; j<size; j++)
        cout << matrix[i][j] << (j < size-1 ? ",\t" : "");
      cout << "]" << (i < size-1 ? "\n" : "");
    }
    cout << "]" << endl;
  }
};

Graph* createGraph(queue<int>& input) {
  int size;
  if (input.empty())
    throw "No graph size provided";
  size = input.front();
  if (size <= 0)
    throw "Graph size must be greater than 0";
  input.pop();
  Graph* G = new Graph(size);

  int a,b;
  while(!input.empty()) {
    a = input.front();
    input.pop();
    if (input.empty())
      throw "All edges must be specified in pairs";
    b = input.front();
    input.pop();
    G->addEdge(a,b);
  }

  return G;
}

void displayHelp() {
  cout << "usage: graphTool [-h|--help] filename" << endl << endl;
  cout << "  -h | --help : print usage instructions" << endl;
  cout << "     filename : name of file containing graph input" << endl << endl;
  cout << "graph file input format: n edge... q" << endl << endl;
  cout << "     n : number of vertices" << endl;
  cout << "  edge : pairs of whitespace delimited vertices between 0 and n-1" << endl;
  cout << "     q : negative integer sentinel to indicate the end of the input" << endl << endl;
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
//  argc - argument count - int of command line arguments, always at least 1 because the program name is an argument
//  argv - argument vector - array of character pointers listing all the arguments, argv[0] is program name
int main(int argc, char* argv[])
{
  queue<int> input;
  Graph* G;

  try {
    // Not passed enough arguments or passed help option
    if (argc < 2)
      throw "No filename provided";

    // Exit if help option provided
    if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
      displayHelp();
      return EXIT_SUCCESS;
    }

    // Open input file as stream
    ifstream graphFile(argv[1]);
    string word;
    int num;
    if (!graphFile)
      throw "Provided file does not exist";

    // Add ints to input queue until sentinel integer or EOF
    while(graphFile >> word) {
      num = stoi(word);
      if (num < 0)
        break;
      input.push(num);
    }

    // Check input terminated properly
    if (num >= 0)
      throw "Input not terminated with negative integer sentinel";
  }
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

  // Build graph from input
  try {
    G = createGraph(input);
  }
  catch(const char* msg) {
    cerr << "Error: " << msg << endl << endl;
    return EXIT_FAILURE;
  }
  G->printMatrix();

  return EXIT_SUCCESS;
}
