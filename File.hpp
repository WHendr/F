#ifndef FILE_HPP
#define FILE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<char> readFileToBuffer(const std::string& fileName)
{
    std::ifstream file(fileName, std::ios::binary | std::ios::ate); // Open at end
    if (!file) {
        throw std::runtime_error("Failed to open file: " + fileName);
    }

    std::streamsize size = file.tellg(); // Get file size
    file.seekg(0, std::ios::beg); // Rewind to beginning

    std::vector<char> buffer(size);
    if (!file.read(buffer.data(), size)) {
        throw std::runtime_error("Failed to read file: " + fileName);
    }

    return buffer;
}


#endif // !FILE_HPP
