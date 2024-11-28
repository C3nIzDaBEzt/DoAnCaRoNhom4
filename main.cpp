#include "Header.h"
#include "Save.h"

void main() {
	
	//FixConsoleWindow();
	CreateSaveDirectory();
	string filename = "example.txt";
	string content = "This is an example content.";
	SaveToFile(filename, content);
	
	mainmenu();
	
}