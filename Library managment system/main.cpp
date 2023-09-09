#include <iostream>
#include <string>
#include "Book.h"
#include "FileIO.h"
#include "Library.h"
int main() {
	Library MyLib = readData();
	MyLib.ShowBooks();
	return 0;
}