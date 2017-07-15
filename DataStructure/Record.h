#pragma once

#ifndef __RECORD_H__
#define __RECORD_H__

#include <cstdio>
#include <cstring>

constexpr int MAX_WORD_LENGTH = 40;
constexpr int MAX_MEANING_LENGTH = 200;

class Record {
public:
	Record(char* word = "", char* meaning = "") { set(word, meaning); }
	
	void	set(const char* word, const char* meaning);
	int		compare(const Record* other);
	int		compare(const char* word);
	int		compareMeaning(const char* mean);
	void	copy(const Record* other) { set(other->word, other->meaning); }
	void	display() { printf(" %12s : %-40s\n", word, meaning); }
private:
	char	word[MAX_WORD_LENGTH];
	char	meaning[MAX_MEANING_LENGTH];
};

void Record::set(const char * word, const char * meaning)
{
	strcpy_s(this->word, MAX_WORD_LENGTH, word);
	strcpy_s(this->meaning, MAX_MEANING_LENGTH, meaning);
}

int Record::compare(const Record * other)
{
	return compare(other->word);
}

int Record::compare(const char * word)
{
	return strcmp(this->word, word);
}

int Record::compareMeaning(const char * mean)
{
	return strcmp(meaning, mean);
}
#endif