#include "Dictionary.h"
#include <algorithm>
#include <cctype>
#include <windows.h>
#include <conio.h>

Dictionary::Dictionary() : capnhat(false), currentWord(NULL) {
    bang = new HashTable[26];
    for (int i = 0; i < 26; ++i) {
        bang[i].head = NULL;
        bang[i].tail = NULL;
    }
}

Dictionary::~Dictionary() {
    writef("data.txt");
    delete[] bang;
}

int Dictionary::taptudien(const std::string& tu) {
    if (!tu.empty()) {
        char x = tu[0];
        if (x >= 'a' && x <= 'z') return x - 'a';
    }
    return -1;
}

void Dictionary::tachchuoi(const std::string& line, Word*& newWord) {
    newWord = new Word(line);
}

void Dictionary::addlast(Word*& head, Word*& tail, Word*& newWord) {
    if (!head) {
        head = tail = newWord;
    } else {
        tail->right = newWord;
        newWord->left = tail;
        tail = newWord;
    }
}

void Dictionary::readf(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    if (file.is_open()) {
        while (getline(file, line)) {
            Word* newWord;
            tachchuoi(line, newWord);
            int index = taptudien(newWord->tu);
            addlast(bang[index].head, bang[index].tail, newWord);
        }
        file.close();
    }
    currentWord = findfirstword();
}

void Dictionary::writef(const std::string& filename) {
    if (!capnhat) return;

    std::ofstream file(filename);
    if (file.is_open()) {
        for (int i = 0; i < 26; ++i) {
            Word* word = bang[i].head;
            while (word) {
                file << word->tu << "@" << word->loai << "@" << word->dongnghia << "@"
                     << word->nghia[0] << "@" << word->nghia[1] << "@" << word->nghia[2] << "@"
                     << word->vidu[0] << "@" << word->vidu[1] << "@" << word->vidu[2] << "@\n";
                word = word->right;
            }
        }
        file.close();
    }
}

Word* Dictionary::findfirstword() {
    for (int i = 0; i < 26; ++i) {
        if (bang[i].head) return bang[i].head;
    }
    return NULL;
}

Word* Dictionary::leftword(Word* current) {
    if (!current) return NULL;
    if (current->left) return current->left;

    int index = taptudien(current->tu);
    while (--index >= 0) {
        if (bang[index].tail) return bang[index].tail;
    }
    return NULL;
}

Word* Dictionary::rightword(Word* current) {
    if (!current) return NULL;
    if (current->right) return current->right;

    int index = taptudien(current->tu);
    while (++index < 26) {
        if (bang[index].head) return bang[index].head;
    }
    return NULL;
}

void Dictionary::importword(const std::string& line) {
    Word* newWord = new Word(line);
    int index = taptudien(newWord->tu);
    addlast(bang[index].head, bang[index].tail, newWord);
    capnhat = true;
}

void Dictionary::deletewordcurrent() {
    if (!currentWord) return;

    int index = taptudien(currentWord->tu);
    Word* left = currentWord->left;
    Word* right = currentWord->right;

    if (bang[index].head == currentWord) {
        bang[index].head = right;
        if (right) right->left = NULL;
    } else if (bang[index].tail == currentWord) {
        bang[index].tail = left;
        if (left) left->right = NULL;
    } else {
        if (left) left->right = right;
        if (right) right->left = left;
    }

    delete currentWord;
    currentWord = left ? left : right;
    capnhat = true;
}

void Dictionary::searchbox() {
}

void Dictionary::printscreen(Word* word) {
    if (word) std::cout << word->tu << std::endl;
}

bool Dictionary::search(const std::string& searchword) {
    int index = taptudien(searchword);
    Word* word = bang[index].head;
    while (word) {
        if (word->tu.find(searchword) == 0) {
            currentWord = word;
            return true;
        }
        word = word->right;
    }
    return false;
}

std::string Dictionary::fixtext(const std::string& text) {
    std::string result = text;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    result.erase(result.find_last_not_of(" ") + 1);
    return result;
}
