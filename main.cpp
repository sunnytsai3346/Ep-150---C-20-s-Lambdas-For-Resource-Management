#include <memory>
#include <cstdio>
#include <iostream>

int main(){
    //C++ Weekly - Ep 150 - C++20's Lambdas For Resource Management
    // Open a file using fopen and wrap it in a std::unique_ptr
    //Custom Deleter: The std::unique_ptr is constructed with a custom deleter [](FILE* f) { fclose(f); } that ensures the file is closed when the std::unique_ptr goes out of scope.
    auto file = std::unique_ptr<FILE,decltype([](FILE *f){fclose(f);})>(fopen("example.txt","w"));
    // Check if the file was opened successfully
    if (!file) {
        std::cerr << "Failed to open the file!" << std::endl;
        return 1;
    }
    // Write some text to the file
    //Automatic Resource Management: By using std::unique_ptr, you don't need to worry about manually closing the file, which helps prevent resource leaks.
    //Safe Handling: If the file fails to open, file.get() returns nullptr, and the program can handle this gracefully.
    const char* text = "Hello, World!";
    if (fprintf(file.get(), "%s\n", text) < 0) {
        std::cerr << "Failed to write to the file!" << std::endl;
        return 1;
    }

}
