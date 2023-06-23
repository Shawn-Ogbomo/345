//Filename: TennisLog.h
//Name:	Shawn Ogbomo
// Student #022609127
// date: 03/25/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#pragma once
#include <iostream>
#include <string>

namespace sdds {
	struct TennisMatch {
	public:
		std::string tournament_id;
		std::string tournament_name;
		unsigned match_id{};
		std::string winner_name;
		std::string loser_name;
	};
	std::ostream& operator << (std::ostream& os, const TennisMatch& t);

	class TennisLog {
	public:
		explicit TennisLog();
		explicit TennisLog(const char* file);
		~TennisLog();
		void addMatch(const TennisMatch& new_tennis_match);
		TennisLog findMatches(const char* player_name) const;
		TennisMatch operator[](size_t index)const;
		explicit operator size_t() const;
	private:
		TennisMatch* matches{};
		size_t num_of_matches{};
	};
}