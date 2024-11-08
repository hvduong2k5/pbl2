#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include <fstream>
#include <string>

class Dictionary {
private:
    struct HashTable {
        Word* head;
        Word* tail;
    } *bang;

    bool capnhat;
    Word* currentWord;

    int taptudien(const std::string& tu);
    void tachchuoi(const std::string& line, Word*& tu);
    void addlast(Word*& head, Word*& tail, Word*& tu);

public:
    Dictionary();
    ~Dictionary();
    void readf(const std::string& filename);
    void writef(const std::string& filename);
    Word* findfirstword();
    Word* leftword(Word* current);
    Word* rightword(Word* current);
    void importword(const std::string& line);
    void deletewordcurrent();
    void searchbox();
    void printscreen(Word* tu);

    bool search(const std::string& searchword);
    std::string fixtext(const std::string& text);
};

#endif // DICTIONARY_H
