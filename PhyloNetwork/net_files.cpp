#include "net_files.h"

void read_file(vector<string>& cont)
{
	ifstream fin("D:\\nets.nex");

	string line;

	while (getline(fin, line) && !fin.eof())
		cont.push_back(line);

	cont.push_back(line);

	fin.close();
}

void upd_file(vector<string>& cont, string net)
{
	for (int i = 0; i < cont.size(); i++)
	{
		size_t found = cont[i].find("Network net = ");
		if (found != -1)
		{
			string old = cont[i].substr(found + 14);
			cont[i].replace(cont[i].find(old), old.length(), net);
		}
	}
}

void write_file(vector<string> cont)
{
	ofstream fout("D:\\nets.nex");

	int i = 0;

	while (!fout.eof() && i < cont.size())
	{
		fout << cont[i] << endl;
		i++;
	}

	fout.close();
}

string execute(string cmd)
{
	string file_name = "result.txt";
	system((cmd + " > " + file_name).c_str()); // redirect output to file

													// open file for input, return string containing characters in the file
	ifstream file(file_name);
	return { istreambuf_iterator<char>(file), istreambuf_iterator<char>() };
}

string exec(const char* cmd) {
	array<char, 128> buffer;
	string result;
	unique_ptr<FILE, decltype(&_pclose)> pipe(_popen(cmd, "r"), _pclose);
	if (!pipe) {
		throw std::runtime_error("popen() failed!");
	}
	while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
		result += buffer.data();
	}
	return result;
}

void get_prob(string net, double& prob)
{
	vector<string> lines;

	read_file(lines);
	upd_file(lines, net);
	write_file(lines);

	string tmp = exec("java -jar D:\\PhyloNet\\PhyloNet_3.8.0.jar D:\\nets.nex");

	size_t found = tmp.find("probability: ");
	if (found != -1)
	{
		string p = tmp.substr(found + 13, 10);
		prob = stod(p);
	}
}
