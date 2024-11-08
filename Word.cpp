#include <Word.h>

Word::Word()
{
}

Word::Word(const std::string& line) : left(NULL), right(NULL) {
    int i = 0;
    std::string buffer;

    // Từ tiếng Anh: bắt đầu bằng '@'
    if (line[i] == '@') {
        i++;
        while (i < line.size() && line[i] != ' ' && line[i] != '/') {
            buffer += line[i++];
        }
        tu = buffer;
        buffer.clear();
    }

    // Bỏ qua khoảng trắng sau từ tiếng Anh, nếu có
    if (i < line.size() && line[i] == ' ') i++;

    // Phiên âm IPA: nằm giữa dấu '/', kiểm tra xem có không
    if (i < line.size() && line[i] == '/') {
        i++;
        while (i < line.size() && line[i] != '/') {
            buffer += line[i++];
        }
        phienAmIPA = buffer;
        buffer.clear();
        if (i < line.size()) i++; // Bỏ qua dấu '/' kết thúc
    }

    // Loại từ: bắt đầu bằng '*', kiểm tra xem có không
    if (i < line.size() && line[i] == '*') {
        i++;
        while (i < line.size() && line[i] != '-') {
            buffer += line[i++];
        }
        loai = buffer;
        buffer.clear();
    }

    // Nghĩa tiếng Việt: bắt đầu bằng dấu '-', kiểm tra và thêm tối đa 3 nghĩa
    int nghiaIndex = 0;
    while (i < line.size() && nghiaIndex < 3) {
        if (line[i] == '-') {
            i++;
            while (i < line.size() && line[i] != '=' && line[i] != '-') {
                buffer += line[i++];
            }
            nghia[nghiaIndex++] = buffer;
            buffer.clear();
        } else {
            i++;
        }
    }

    // Đồng nghĩa: bắt đầu bằng dấu '=', kiểm tra và thêm tối đa 3 ví dụ đồng nghĩa
    int viduIndex = 0;
    while (i < line.size() && viduIndex < 3) {
        if (line[i] == '=') {
            i++;
            while (i < line.size() && line[i] != '-') {
                buffer += line[i++];
            }
            vidu[viduIndex++] = buffer;
            buffer.clear();
        } else {
            i++;
        }
    }
}

Word::~Word()
{
}
