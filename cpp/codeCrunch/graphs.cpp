#include <vector>
#include <iostream>
#include <string>

using namespace std;

// the goal of this is to implement a translation of a 2d vector representation of a graph into the 3 basic representations and 
// to perform bfs, dfs, and test casees of said traversals. 

// after sufficient time spent on this file and troubleshooting the issues that arose...
// I think I retain sufficient command over the graph structure and the cpp language to proceed. 
//



void print2DGraph( vector< vector<int> * >& source ) {
	for (int i = 0; i < source.size(); i++ ) {
		for (int j = 0; j < source[i]->size(); j++ ) cout << source[i]->at(j);
		cout << endl;
	}


}
// converting a 2d vector into an adjacency matrix is kinda tough lol. 

vector< vector< int> * > * genAdjMatrix( vector< vector< int> *> source) {
	vector< vector< int> * > * adjMatrix = new vector< vector< int> * >();
	int numV = 0;
	for (int i = 0; i < source.size(); i++ ) {
		for (int j = 0; j < source[i]->size(); j++ ) {
			if ( source[i]->at(j) > 0 )  {
				adjMatrix->push_back(new vector<int>());
				numV++;//acts as an id;
				source[i]->at(j) 	= numV;
			
			}
		}
	}
	for( int i = 0; i < numV; i++ ){
		for( int j = 0; j < numV; j++ ) adjMatrix->at(i)->push_back(0);

	}
	cout << "Done Traversing the first pass through the graph 2d vector" << endl;
	for (int i = 0; i < source.size(); i++ ) {
		for (int j = 0; j < source[i]->size(); j++ ) {
			if ( source[i]->at(j) > 0 ) {
				// look right
				if ( j < source[i]->size() - 1 && source[i]->at(j + 1) > 0 )
					adjMatrix->at( source[i]->at(j) - 1 )->at( source[i]->at(j + 1) - 1) = 1; 
				// look left
				if ( j > 0 && source[i]->at(j - 1) > 0 ) 
					adjMatrix->at( source[i]->at(j) - 1 )->at( source[i]->at(j - 1) - 1) = 1; 
				// look down

				if ( i < source.size() - 1 && source[i + 1]->at(j) > 0 ) 
					adjMatrix->at( source[i]->at(j) - 1 )->at( source[i + 1]->at(j) - 1 ) = 1; 
				// look up

				if ( i > 0 && source[i - 1]->at(j) > 0 ) 
					adjMatrix->at( source[i]->at(j) - 1 )->at( source[i - 1]->at(j) - 1 )  = 1; 
			}
		}
	}
	cout << "size of generated adjMatrix is: " << adjMatrix->size() << " by " << adjMatrix->at(0)->size() << endl;
	return adjMatrix;
}

void printAdjMatrix( vector< vector< int> *> * source) {
	for(int i = 0; i < source->size(); i++) 	{
		for(int j = 0; j < source->at(i)->size(); j++ ) {
			cout << source->at(i)->at(j);
		}
		cout << endl;

	}

}

struct node { 
	vector< int > * neighbors;
	int id;
	node() : neighbors( new vector< int >() ), id(-1) { }
	
};

vector< node *> * genGraph( vector< vector<int> * >& source ) {
	int id = 0;
	node * curN;	
	vector< node *> * ans = new vector< node *>();
	for (int i = 0; i < source.size(); i++ ) {
		for (int j = 0; j < source[i]->size(); j++ ) {
			
			curN = new node();
			// potential heuristic here.  
			curN->id = id;
			// look right
			if ( j < source[i]->size() - 1 && source[i]->at(j + 1) == 1 ) curN->neighbors->push_back( id + 1 ); 
			// look left
			if ( j > 0 && source[i]->at(j - 1) == 1 ) curN->neighbors->push_back( id - 1 );
			// look down
			if ( i < source.size() - 1 && source[i + 1]->at(j) == 1 ) curN->neighbors->push_back( id + source[i]->size() ); 
			// look up
			if ( i > 0 && source[i - 1]->at(j) == 1 ) curN->neighbors->push_back( id - source[i]->size() ); 
			id++;
			ans->push_back(curN);
		}
	}	 
	return ans;
}

void printGraphPnts( vector< node * > * source ) {
	for( int i = 0; i < source->size(); i++ ) {
		cout << "Point id: " << source->at(i)->id << endl;
		for( int j = 0; j < source->at(i)->neighbors->size(); j++ ) cout << "    -- " << source->at(i)->neighbors->at(j);
		cout << endl; 
	}

}

int main( int argc, char** argv ) {
	vector< vector < int > * > source = vector< vector< int> * >();
	vector< vector < int > * > sourceB = vector< vector< int> * >();
	for(int i = 0; i < 4; i++ ) source.push_back( new vector< int >() );
	for(int i = 0; i < 4; i++ ) sourceB.push_back( new vector< int >() );

	source[0]->push_back(0);
	source[0]->push_back(0);
	source[0]->push_back(1);
	source[0]->push_back(0);
	source[1]->push_back(0);
	source[1]->push_back(0);
	source[1]->push_back(1);
	source[1]->push_back(1);
	source[2]->push_back(1);
	source[2]->push_back(1);
	source[2]->push_back(1);
	source[2]->push_back(0);
	source[3]->push_back(1);
	source[3]->push_back(1);
	source[3]->push_back(1);
	source[3]->push_back(1);

	print2DGraph(source);

//	vector< vector<int> * > * adjMatrix = genAdjMatrix( source );
//	printAdjMatrix( adjMatrix );
	vector< node * > * graph = genGraph(source);
	printGraphPnts( graph );

	// giving nodes ids for adj. matrix. 
	sourceB[0]->push_back(0);
	sourceB[0]->push_back(0);
	sourceB[0]->push_back(1);
	sourceB[0]->push_back(0);
	sourceB[1]->push_back(0);
	sourceB[1]->push_back(0);
	sourceB[1]->push_back(2);
	sourceB[1]->push_back(3);
	sourceB[2]->push_back(4);
	sourceB[2]->push_back(5);
	sourceB[2]->push_back(6);
	sourceB[2]->push_back(0);
	sourceB[3]->push_back(7);
	sourceB[3]->push_back(8);
	sourceB[3]->push_back(9);
	sourceB[3]->push_back(10);

	vector< vector< int> * > * adjMatrix = genAdjMatrix( sourceB );
	print2DGraph(sourceB);
	printAdjMatrix( adjMatrix );

	return 0;
}
