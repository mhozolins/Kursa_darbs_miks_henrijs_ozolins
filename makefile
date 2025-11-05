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
       $(HDR_DIR)/searchop.c   # fixed filename

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

# ===== CLI Commands =====
run: $(TARGET)
	./$(TARGET)

list: $(TARGET)
	./$(TARGET) list

add: $(TARGET)
	./$(TARGET) add $(BRAND) $(MODEL) $(YEAR) $(PRICE) $(KM) $(ENGINE) $(GAS) $(TYPE) $(OWNERS)

delete: $(TARGET)
	./$(TARGET) delete $(BRAND) $(MODEL)

sort: $(TARGET)
	./$(TARGET) sort $(BRAND) $(FIELD)

.PHONY: all clean run list add delete sort
