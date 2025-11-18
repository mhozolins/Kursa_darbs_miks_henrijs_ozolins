CAR MANAGEMENT SYSTEM

QUICK START
make                    - Build program
make run                - Interactive mode
./executables/car_list  - Interactive mode

BUILD COMMANDS
make                    - Build program
make clean              - Clean build files

INTERACTIVE MODE
make run                - Start interactive menu

SEARCH COMMANDS
make brand BRAND=BMW    - Search by brand
make fuel FUEL=Petrol   - Search by fuel type
make cartype TYPE=SUV   - Search by car type

SORT COMMANDS
make sort-year          - Sort by year (newest first)
make sort-price         - Sort by price (cheapest first)
make sort BRAND=BMW FIELD=year ORDER=newest  - Flexible sort

CAR MANAGEMENT
make add-car            - Add new car (interactive)
make add BRAND=... MODEL=... YEAR=... PRICE=... KM=... ENGINE=... GAS=... TYPE=... OWNERS=...
make delete-car         - Delete car (interactive)
make help               - Show help

DIRECT COMMANDS - SINGLE LETTER
./executables/car_list L        - List all cars
./executables/car_list M BMW    - Search by brand
./executables/car_list G Petrol - Search by fuel
./executables/car_list T SUV    - Search by type
./executables/car_list S        - Sort by year
./executables/car_list P        - Sort by price
./executables/car_list A        - Add car (interactive)
./executables/car_list D        - Delete car (interactive)
./executables/car_list Q        - Quit

DIRECT COMMANDS - FULL
./executables/car_list list                           - List all cars
./executables/car_list add BRAND MODEL YEAR PRICE KM ENGINE GAS TYPE OWNERS
./executables/car_list delete BRAND MODEL             - Delete car
./executables/car_list sort BRAND FIELD ORDER         - Sort cars
./executables/car_list search TYPE VALUE              - Search cars
./executables/car_list help                           - Show help

INTERACTIVE MENU OPTIONS
L - Show all cars
G - Search by fuel type
T - Search by car type
M - Search by brand
S - Sort by year (newest first)
P - Sort by price (cheapest first)
A - Add a new car
D - Delete a car
Q - Quit program

EXAMPLES - MAKEFILE
make brand BRAND=BMW
make sort BRAND=BMW FIELD=year ORDER=newest
make add BRAND=Toyota MODEL=Camry YEAR=2021 PRICE=20000 KM=10000 ENGINE=2.5 GAS=Petrol TYPE=Sedan OWNERS=1

EXAMPLES - DIRECT COMMANDS
./executables/car_list M BMW
./executables/car_list sort Honda km lowest
./executables/car_list add Honda Civic 2019 15000 80000 1.5 Petrol Sedan 2
./executables/car_list search brand Toyota

FILE STRUCTURE
Headers/     - Header files
src/         - Source files
executables/ - Compiled files
car_list.txt - Car database