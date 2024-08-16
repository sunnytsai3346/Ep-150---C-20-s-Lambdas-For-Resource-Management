# compiler explorer  compiler option : -std=c++2a -O3


Custom Deleter: The std::unique_ptr is constructed with a custom deleter [](FILE* f) { fclose(f); } that ensures the file is closed when the std::unique_ptr goes out of scope.

Automatic Resource Management: By using std::unique_ptr, you don't need to worry about manually closing the file, which helps prevent resource leaks.

Safe Handling: If the file fails to open, file.get() returns nullptr, and the program can handle this gracefully.

This pattern is especially useful when dealing with resources that require explicit cleanup, such as file handles, sockets, or dynamically allocated memory.
