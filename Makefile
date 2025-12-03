
CC = gcc
CFLAGS = -Wall -Iinclude
SRC = $(wildcard src/*.c test/*.c)
OBJDIR = obj
OBJ = $(patsubst %.c,$(OBJDIR)/%.o,$(notdir $(SRC)))
TARGET = exe

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

$(OBJDIR)/%.o: src/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@


$(OBJDIR)/%.o: test/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -f $(OBJDIR)/*.o $(TARGET)
	rmdir $(OBJDIR) 2>/dev/null || true

.PHONY: clean
