// this be gone project is an app that will allocate chunks of memory for no
// specific reason. will just ask if you want to allocate one more gb of RAM
// and allocate if possible.

#include <cstdlib>
#include <iostream>
#include "include/CLI11.hpp"

int main(int argc, char **argv) {
    // Create a CLI app
    CLI::App app{"BeGoneMemory CLI Tool"};

    // Add an option for allocating memory
    int memorySize = 1024;  // Default to 1GB
    app.add_option("-m,--memory", memorySize, "Allocate memory size in MB");

    // Parse the command-line arguments
    CLI11_PARSE(app, argc, argv);

    // Check if the user wants to allocate memory
    if (memorySize > 0) {
        // Attempt to allocate memory
        try {
            std::cout << "Attempting to allocate " << memorySize << " MB of memory..." << std::endl;

            // Convert MB to bytes
            size_t bytesToAllocate = static_cast<size_t>(memorySize) * 1024 * 1024;

            // Allocate memory
            void* memory = malloc(bytesToAllocate);
            if (memory == nullptr) {
                throw std::bad_alloc();
            }

            // Memory allocation successful
            std::cout << "Memory allocation successful!" << std::endl;

            // Use the allocated memory as needed

            // Don't forget to free the memory when done
            free(memory);
        } catch (const std::bad_alloc& e) {
            // Memory allocation failed
            std::cerr << "Memory allocation failed. Not enough memory available." << std::endl;
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}

