g++ CPUDriver.cpp cpu.cpp stack.cpp queue.cpp -o CPU
valgrind --leak-check=yes ./CPU
./CPU