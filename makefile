CC = gcc
CFLAGS = -Wall -g -IHeaders

SRC_DIR = src
HDR_DIR = Headers
BIN_DIR = executables
TARGET = $(BIN_DIR)/car_list

# All source files
SRCS = $(SRC_DIR)/car_list.c $(HDR_DIR)/add_del_op.c $(HDR_DIR)/list_op.c \
       $(HDR_DIR)/same_string.c $(HDR_DIR)/searchop.c

OBJS = $(patsubst %.c,$(BIN_DIR)/%.o,$(notdir $(SRCS)))

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compile .c files in src/
$(BIN_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Compile .c files in Headers/
$(BIN_DIR)/%.o: $(HDR_DIR)/%.c
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BIN_DIR)/*.o $(TARGET)

.PHONY: all clean run list add delete sort

run: $(TARGET)
	$(TARGET)

list: $(TARGET)
	$(TARGET)

add: $(TARGET)
	$(TARGET) add $(BRAND) $(MODEL) $(YEAR) $(PRICE) $(KM) $(ENGINE) $(GAS) $(TYPE) $(OWNERS)

delete: $(TARGET)
	$(TARGET) delete $(BRAND) $(MODEL)

sort: $(TARGET)
	$(TARGET) sort $(BRAND) $(FIELD)
