CC = g++
TARGET = lexer
BUILD_DIR = build
OBJ = $(BUILD_DIR)/lexer.o

$(BUILD_DIR)/%.o: %.cpp
	mkdir -p $(BUILD_DIR)
	$(CC) -c $< -o $@

$(TARGET): $(OBJ)
	$(CC) -o $(BUILD_DIR)/$@ $^

run: $(TARGET)
	./$(BUILD_DIR)/$(TARGET)

clean:
	rm -rf $(BUILD_DIR)
