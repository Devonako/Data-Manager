#include <string>
#include <fstream>
#include <iostream>
enum log_type {
	FILE_T, ROLLING, SPLUNK, DATADOG
};



class logger {
private:
	void handleOutput(std::string data, std::string fileName, std::ios_base::openmode mode) {
		// Create and open a text file
		if (fileName.compare("stdout") == 0) {
			fprintf(stdout, "%s\n", data.c_str());
		}
		else
		{
			std::ofstream MyFile(fileName, mode);

			// Write to the file
			MyFile << data << "\n";

			// Close the file
			MyFile.close();
		}

	}
	std::string rollover_file(std::string initial_file) {
		// Check date of initial file
		// IF it is time to rollover, rol
	}
	log_type logT;
	std::string file_name;
public:
	logger() {
		logT = log_type::FILE_T;
		file_name = "log.txt";
	}
	logger(log_type lt) {
		logT = lt;
		file_name = "log.txt";
	}
	logger(std::string fname) {
		file_name = fname;
	}
	void log_it(std::string message) {
		switch (logT)
		{
		case FILE_T:
			handleOutput(message, file_name, std::ios::app);
			break;
		case ROLLING:
			break;
		case SPLUNK:
			break;
		case DATADOG:
			break;
		default:
			break;
		}
	}
};
