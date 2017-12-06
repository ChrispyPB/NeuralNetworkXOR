#include "CLA.h"

bool CLA::verbose = false;
vector<int> CLA::layers = vector<int>();

void CLA::parse(int argc, char** argv) {
	try {
		po::options_description desc{"Options"};
		desc.add_options()
			("help,h", "Print help messages")
			("verbose,v", "Execute verbose")
			("layers,l", po::value<vector<int> >()->multitoken(), "Set layer count")
		;

		po::variables_map vm;
		po::store(po::parse_command_line(argc, argv, desc), vm);
		po::notify(vm);

		if (vm.count("help")) {
			cout << desc << endl;
		}

		if (vm.count("verbose")) {
			CLA::verbose = true;
		}

		if (vm.count("layers")) {
			CLA::layers = vm["layers"].as<vector<int> >();
		}
	}
	catch (const po::error &err) {
		cerr << err.what() << endl;
	}
}
