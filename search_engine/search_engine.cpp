// search_engine.cpp: определяет точку входа для приложения.
//

#include "include/search_engine.h"

using namespace std;

int main()
{
	//cout << "Hello CMake." << endl;
	cj->createConfJson();
	cj->createRequestDoc();
	cj->GetRequests();

	ii->accesToDocs();
	ii->showWords();
	ii->createJsonReport();
	ii->compileData();
	return 0;
}
