#include "utils.h"
#include <iostream>

using namespace std;

void logInfo(string message) {
	cout << json{{"type", "log"}, {"data", message}} << endl;
}