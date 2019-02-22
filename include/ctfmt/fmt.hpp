#ifndef CTFMT__FMT__HPP
#define CTFMT__FMT__HPP

// THIS FILE WAS GENERATED BY DESATOMAT TOOL, DO NOT MODIFY THIS FILE

#include "../ctll/grammars.hpp"

namespace ctfmt {

struct fmt {

// NONTERMINALS:
	struct number2 {};
	struct number {};
	struct s2 {};
	struct s {}; using _start = s;
	struct text2 {};

// 'action' types:
	struct finish: ctll::action {};
	struct push_digit: ctll::action {};
	struct push_text: ctll::action {};
	struct start_digit: ctll::action {};
	struct start_text: ctll::action {};

// (q)LL1 function:
	using _others = ctll::neg_set<'\x7B','\x7D','0','1','2','3','4','5','6','7','8','9'>;
	static constexpr auto rule(s, ctll::epsilon) -> ctll::epsilon;
	static constexpr auto rule(s, ctll::term<'\x7B'>) -> ctll::push<ctll::anything, number, finish, ctll::term<'\x7D'>, s>;
	static constexpr auto rule(s, ctll::set<'0','1','2','3','4','5','6','7','8','9'>) -> ctll::push<ctll::anything, start_text, text2, s2>;
	static constexpr auto rule(s, _others) -> ctll::push<ctll::anything, start_text, text2, s2>;
	static constexpr auto rule(s, ctll::term<'\x7D'>) -> ctll::reject;

	static constexpr auto rule(number2, ctll::term<'\x7D'>) -> ctll::epsilon;
	static constexpr auto rule(number2, ctll::set<'0','1','2','3','4','5','6','7','8','9'>) -> ctll::push<ctll::anything, push_digit, number2>;

	static constexpr auto rule(number, ctll::set<'0','1','2','3','4','5','6','7','8','9'>) -> ctll::push<ctll::anything, start_digit, number2>;

	static constexpr auto rule(s2, ctll::epsilon) -> ctll::epsilon;
	static constexpr auto rule(s2, ctll::term<'\x7B'>) -> ctll::push<ctll::anything, number, finish, ctll::term<'\x7D'>, s>;

	static constexpr auto rule(text2, ctll::set<'0','1','2','3','4','5','6','7','8','9'>) -> ctll::push<ctll::anything, push_text, text2>;
	static constexpr auto rule(text2, _others) -> ctll::push<ctll::anything, push_text, text2>;
	static constexpr auto rule(text2, ctll::term<'\x7B'>) -> ctll::push<finish>;
	static constexpr auto rule(text2, ctll::epsilon) -> ctll::push<finish>;
	static constexpr auto rule(text2, ctll::term<'\x7D'>) -> ctll::reject;

};

}

#endif //CTFMT__FMT__HPP
