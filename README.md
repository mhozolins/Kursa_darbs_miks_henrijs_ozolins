==============================
CAR LIST PROJECT - MAKEFILE COMMANDS
==============================

1. Build the program
   Command:
      make
   Description:
      Compiles all .c files and creates the executable.

2. Clean build files
   Command:
      make clean
   Description:
      Removes all .o files and the executable.

3. Run program
   Command:
      make run
   Description:
      Executes the program interactively.

4. List all cars
   Command:
      make list
   Description:
      Displays the list of all cars.

5. Add a car
   Command:
      make add BRAND=BMW MODEL=320 YEAR=2020 PRICE=20000 KM=15000 ENGINE=2.0 GAS=Petrol TYPE=Sedan OWNERS=1
   Description:
      Adds a new car to the list.

6. Delete a car
   Command:
      make delete BRAND=BMW MODEL=320
   Description:
      Deletes a car from the list by brand and model.

7. Sort cars
   Command:
      make sort BRAND=BMW FIELD=price
   Description:
      Sorts cars by brand and field (price, year, km).

------------------------------
NOTES
------------------------------
- Object files (.o) and the executable are stored in the 'executables/' folder.
- Header files (.h) are located in the 'Headers/' folder.
- The main source file 'car_list.c' is in the 'src/' folder.
- All commands automatically build the program if needed.
- Example usage:
      make add BRAND=Audi MODEL=A4 YEAR=2018 PRICE=18000 KM=60000 ENGINE=1.8 GAS=Petrol TYPE=Sedan OWNERS=2
      make list
      make sort FIELD=year
