#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Book.h"
#include "Library.h"

Library readData();
void saveData(std::vector<Book> books);