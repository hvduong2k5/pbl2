#include <Word.h>

Word::Word()
{
}

Word::Word(const std::string& line) : left(NULL), right(NULL) {
    int i = 0;
    std::string buffer;

    while (line[i] != '@') buffer += line[i++];
    i++;
    tu = buffer;
    buffer.clear();

    while (line[i] != '@') buffer += line[i++];
    i++;
    loai = buffer;
    buffer.clear();

    while (line[i] != '@') buffer += line[i++];
    i++;
    dongnghia = buffer;
    buffer.clear();

    for (int j = 0; j < 3; ++j) {
        while (line[i] != '@') buffer += line[i++];
        i++;
        nghia[j] = buffer;
        buffer.clear();
    }

    for (int j = 0; j < 3; ++j) {
        while (line[i] != '@') buffer += line[i++];
        i++;
        vidu[j] = buffer;
        buffer.clear();
    }
}

Word::~Word()
{
}
