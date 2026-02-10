CAR MANAGEMENT SYSTEM - COMMAND REFERENCE

QUICK START:
make              # Build program
make run          # Start interactive menu

MAIN FEATURES:
- Search cars by brand, fuel type, or car type
- Sort cars by price, year, mileage, etc.
- Add/delete cars from database
- Interactive menu or command-line options

BASIC COMMANDS:
make brand BRAND=Toyota     # Search by brand
make fuel FUEL=Petrol       # Search by fuel
make cartype TYPE=SUV       # Search by car type
make sort-year              # Sort by year (newest)
make sort-price             # Sort by price (cheapest)

INTERACTIVE MENU (after make run):
L - Show all cars
G - Search by fuel
T - Search by car type
M - Search by brand
S - Sort by year
P - Sort by price
A - Add new car
D - Delete car
Q - Quit

DIRECT COMMANDS:
./executables/car_list M Toyota    # Search brand
./executables/car_list G Diesel    # Search fuel
./executables/car_list list        # List all cars
./executables/car_list help        # Show full help

FILE: car_list.txt - Stores all car data