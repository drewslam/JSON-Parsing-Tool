#include <iostream>
#include <map>
#include <vector>
#include <fstream>

std::map<char,char> closeToOpen{ {'}','{'}, {')','('}, {']','['} };

class Stack {
    private:
        std::vector<char> arr;
    public:
        Stack() { arr.resize(0); }
        void push(char item) { arr.push_back(item); }
        void pop() { arr.pop_back(); };
        char peek() const { return arr.back(); }
};

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Error: JSON file not provided\n";
        return -1;
    }

    std::string fileName = argv[1];

    std::ifstream inFS(fileName);
    std::string fs_data;
    
    if (inFS) {
        std::cout << fileName << ": opened\n";
    } else {
        std::cout << "Opening failed\n";
    }

    while (inFS) {
        std::getline(inFS, fs_data);
        std::cout << fs_data << "\n";
    }

    inFS.close();

    return 0;
}
