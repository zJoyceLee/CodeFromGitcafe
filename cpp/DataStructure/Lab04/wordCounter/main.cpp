// STL
#include <algorithm>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

template <typename UnaryFunc>
std::vector<std::string> split(const std::string & s, UnaryFunc isSeperator) {
	std::vector<std::string> ret;

    std::string::size_type wordStart = 0;
    std::string::size_type wordEnd = 0;
    std::string::size_type sLength = s.length();

    while(wordStart < sLength) {
        wordStart = wordEnd;
        while(wordStart < sLength && isSeperator(s[wordStart]))
            ++wordStart;
        wordEnd = wordStart;
        while(wordEnd < sLength && !isSeperator(s[wordEnd]))
            ++wordEnd;

        if(wordStart < wordEnd)
            ret.push_back(s.substr(wordStart, wordEnd - wordStart));
    }

    return ret;
}

std::vector<std::string> readAllInLines(const std::string & path) {
    std::vector<std::string> ret;

    // open file to read
    std::ifstream ifs(path);
    if(!ifs)
        throw std::runtime_error("cannot open file: " + path);

    std::string line;
    while(true) {
        std::getline(ifs, line);
        if(!ifs)
            break;
        ret.push_back(line);
    }

    return ret;
}

//read in 'path' file into words, split by space
std::vector<std::string> readAllInWords(const std::string & path) {
    std::vector<std::string> ret;

    // open file to read
    std::ifstream ifs(path);
    if(!ifs)
        throw std::runtime_error("cannot open file: " + path);

    std::string word;
    while(true) {
        ifs >> word;
        if(!ifs)
            break;
        ret.push_back(word);
    }

    return ret;
}

struct WordInfo {
    std::string word;
    std::vector<std::size_t> lines;
};

void printWordInfos(const std::vector<WordInfo> & wordInfos, const std::vector<std::string> & lines) {
    for(const WordInfo & info : wordInfos) {
        std::cout << std::endl <<  info.word << ": " << info.lines.size() << " in total"
            << std::endl;
        for(const std::size_t lineNumber : info.lines)
            std::cout << "@" << lineNumber /*<< ": " << lines[lineNumber] << std::endl;*/ << " ";
    }
}

int main(int argc, char * argv[])
{
    std::vector<std::string> lines = readAllInLines("file.txt");
    std::vector<std::string> analysisWords = readAllInWords("words.txt");

    // initialize 'wordInfos' with 'analysisWords' and empty vector
    std::vector<WordInfo> wordInfos;
    for(std::size_t i = 0; i < analysisWords.size(); ++i)
        wordInfos.push_back({ analysisWords[i], std::vector<std::size_t>() });

    // for each line
    for(std::size_t i = 0; i < lines.size(); ++i) {
        // i is actually the line number
        std::size_t lineNumber = i;

        std::vector<std::string> words = split(lines[i], isspace);
        // for each word in current line
        for(std::size_t j = 0; j < words.size(); ++j) {
            // if words[j] is in the 'wordInfos'
            auto iter = std::find_if(wordInfos.begin(), wordInfos.end(),
                    [&](const WordInfo & info) { return info.word == words[j]; });
            if(iter != wordInfos.end()) {
                // this means that word[j] is found
                iter->lines.push_back(lineNumber);
            }
        }
    }

    printWordInfos(wordInfos, lines);

    return 0;
}
