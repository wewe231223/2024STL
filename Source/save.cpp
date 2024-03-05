#include "pch.h"
#include "save.h"

void save(std::string_view FileName) {
	// 간단한 파일 읽기 쓰기 
	std::ifstream in{ FileName.data() };
	if (not in) {
		std::cout << FileName << " : Failed to open" << std::endl;
		return;
	}
	std::ofstream out{ "Log_STL2024.txt",std::ios::app };

	// 파일을 모두 읽어서 덧붙여 쓴다 

	auto now = std::chrono::system_clock::now();
	std::cout << "Now : " << now << std::endl;

	auto time = std::chrono::system_clock::to_time_t(now); // UTC time 
	auto LT = std::localtime(&time); // Make "time" to Local Time


	auto old = out.imbue(std::locale("ko_KR"));
	out << "=========================Time=========================" << std::endl;
	out << FileName << std::put_time(LT, ", Saved Time : %x %a %X") << std::endl;
	out << "======================================================" << std::endl << std::endl;
	out << "========================Source========================" << std::endl << std::endl;
	out.imbue(old);
	std::vector<char> v{ std::istreambuf_iterator{in},{} };
	std::copy(v.begin(), v.end(), std::ostreambuf_iterator<char>{ out });
	out << "======================================================\n\n" << std::endl;

	for (auto& c : v) {
		std::cout << c;		
	}


	out.close();
}

