//Filename: TennisLog.cpp
//Name:	Shawn Ogbomo
// Student #022609127
// date: 03/25/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#include <ios>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "TennisLog.h"

namespace sdds {
	TennisLog::TennisLog() = default;

	TennisLog::TennisLog(const char* file) {
		std::ifstream ifs{ file };

		if (!ifs) {
			std::cerr << "The file: " << file << " does not exist...\n";
			ifs.exceptions(ifs.exceptions() | std::ios::badbit);
		}

		std::string s;
		std::getline(ifs, s);
		const auto& begin = ifs.tellg();

		while (!ifs.eof()) {
			std::getline(ifs, s);
			++num_of_matches;
		}

		matches = new TennisMatch[num_of_matches];
		ifs.clear();
		ifs.seekg(begin, std::ios::beg);

		for (size_t i = 0; i < num_of_matches; ++i) {
			std::getline(ifs, matches[i].tournament_id, ',');
			std::getline(ifs, matches[i].tournament_name, ',');
			ifs >> matches[i].match_id;
			ifs.ignore();
			std::getline(ifs, matches[i].winner_name, ',');
			std::getline(ifs, matches[i].loser_name);
		}
	}

	TennisLog::~TennisLog() {
		delete[] matches;
	}

	void TennisLog::addMatch(const TennisMatch& new_tennis_match) {
		auto matches_new = new TennisMatch[num_of_matches + 1];

		for (size_t i = 0; i < num_of_matches; ++i) {
			matches_new[i] = matches[i];
		}

		matches_new[num_of_matches] = new_tennis_match;
		++num_of_matches;
		delete[] matches;
		matches = matches_new;
	}

	TennisLog TennisLog::findMatches(const char* player_name) const {
		TennisLog new_log{};

		for (size_t i = 0; i < num_of_matches; ++i) {
			if (matches[i].winner_name == player_name || matches[i].loser_name == player_name) {
				new_log.addMatch(matches[i]);
			}
		}
		return new_log;
	}

	TennisMatch TennisLog::operator[](size_t index) const {
		const auto sz = this->operator size_t();
		if (!sz || index > sz) {
			return TennisMatch{};
		}

		return matches[index];
	}

	TennisLog::operator size_t() const {
		return num_of_matches;
	}

	std::ostream& operator<<(std::ostream& os, const TennisMatch& t) {
		const auto no_tennis_match = t.tournament_id.empty() && t.tournament_name.empty() && !t.match_id && t.winner_name.empty() && t.loser_name.empty();

		if (no_tennis_match) {
			os << "Empty Match";
		}

		else {
			os << std::right << std::setw(23) << std::setfill('.') << "Tourney ID : " << std::left << std::setw(30) << t.tournament_id << "\n"
				<< std::right << std::setw(23) << "Match ID : " << std::left << std::setw(30) << t.match_id << "\n"
				<< std::right << std::setw(23) << "Tourney : " << std::left << std::setw(30) << t.tournament_name << "\n"
				<< std::right << std::setw(23) << "Winner : " << std::left << std::setw(30) << t.winner_name << "\n"
				<< std::right << std::setw(23) << "Loser : " << std::left << std::setw(30) << t.loser_name << "\n";
		}
		return os;
	}
}