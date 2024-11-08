#ifndef WORD_H
#define WORD_H
#include<string>
using namespace std;
class Word
{
private:
    Word *left,*right;
    string word;
    string part_of_speech;
    string *example_sentence;
    string *meaning;
    string ipa;
public:
    Word();
    Word(const std::string& line);
    ~Word();
};

#endif
