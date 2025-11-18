CC = gcc
CFLAGS = -Wall -g -IHeaders

SRC_DIR = src
HDR_DIR = Headers
BIN_DIR = executables
TARGET = $(BIN_DIR)/car_list

SRCS = $(SRC_DIR)/car_list.c \
       $(HDR_DIR)/argument_handler.c \
       $(HDR_DIR)/add_del_op.c \
       $(HDR_DIR)/list_op.c \
       $(HDR_DIR)/same_string.c \
       $(HDR_DIR)/searchop.c \
       $(HDR_DIR)/single_letter_cmd.c \
       $(HDR_DIR)/utils.c

OBJS = $(patsubst %.c, $(BIN_DIR)/%.o, $(notdir $(SRCS)))

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

$(BIN_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN_DIR)/%.o: $(HDR_DIR)/%.c
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BIN_DIR)/*.o $(TARGET)

# ===== SINGLE WORD COMMANDS =====

# Interactive mode
run: $(TARGET)
	./$(TARGET)

# List all cars
list: $(TARGET)
	./$(TARGET) L

# Search commands
brand: $(TARGET)
	./$(TARGET) M $(BRAND)

fuel: $(TARGET)
	./$(TARGET) G $(FUEL)

cartype: $(TARGET)
	./$(TARGET) T $(TYPE)

# Sort commands
sort-year: $(TARGET)
	./$(TARGET) S

sort-price: $(TARGET)
	./$(TARGET) P

# Add car (interactive)
add-car: $(TARGET)
	./$(TARGET) A

# Delete car (interactive)
delete-car: $(TARGET)
	./$(TARGET) D

# Quit
quit: $(TARGET)
	./$(TARGET) Q

# Flexible sort command
sort: $(TARGET)
	./$(TARGET) sort $(BRAND) $(FIELD) $(ORDER)

# Add car with arguments
add: $(TARGET)
	./$(TARGET) add $(BRAND) $(MODEL) $(YEAR) $(PRICE) $(KM) $(ENGINE) $(GAS) $(TYPE) $(OWNERS)

# Help
help: $(TARGET)
	./$(TARGET) help

.PHONY: all clean run list brand fuel cartype sort-year sort-price add-car delete-car quit sort help