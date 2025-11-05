Makefile Commands

1. Build the program
   make
   - Compiles all .c files and creates the executable

2. Clean build files
   make clean
   - Removes all .o files and the executable

3. Run program
   make run
   - Executes the program interactively

4. Add a car

   make add BRAND=BMW MODEL=320 YEAR=2020 PRICE=20000 KM=15000 ENGINE=2.0 GAS=Petrol TYPE=Sedan OWNERS=1


   - Adds a new car to the list


5. Sort cars
   make sort BRAND=BMW FIELD=price
   - Sorts cars by brand and field (price, year, km)

Notes:
- Object files (.o) and the executable are stored in 'executables/'
- Header files (.h) are in 'Headers/'
- Source file 'car_list.c' is in 'src/'
- Commands automatically build the program if needed
