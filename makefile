CC=g++
VERSION=0 0 1
CFLAGS=-Wall -Ofast -std=c++11

VERSION_FILE=res/version.txt
BUILD_FILE=res/build.txt
GLOBALS_DIR=src/globals/
DATABASE_DIR=src/database/
GLOBAL_OBJS = src/globals/main src/globals/timer
INDIE_OBJ = src/globals/set_version src/globals/increment_build_count
CONSOLE_OBJS = src/console_ui/console_ui src/console_ui/console_sprite src/console_ui/console_material
SDL_OBJS = src/sdl_ui/sdl_handler
DATABASE_OBJS = src/database/xugfile src/database/xugdirectory
NETWORK_OBJS = src/network/server src/network/client
OBJ=$(GLOBAL_OBJS) $(DATABASE_OBJS) $(NETWORK_OBJS) $(CONSOLE_OBJS) $(SDL_OBJS)
XUGFILE_OBJS=$(addsuffix .o, $(OBJ))
XUGFILE_SRC=$(addsuffix .cpp, $(OBJ))
INDIE_OBJS=$(addsuffix .c, $(INDIE_OBJ)
BIN=bin/
OBJ_DIR=obj/
SOFTWARE_NAME=xugciv
EXECUTABLE=$(BIN)$(SOFTWARE_NAME)
SERVER_EXECUTABLE=$(BIN)$(SOFTWARE_NAME)_server
CLIENT_EXECUTABLE=$(BIN)$(SOFTWARE_NAME)_client
INCREMENT_BUILD_COUNT_EXECUTABLE=$(BIN)increment_build_count
SET_VERSION_EXECUTABLE=$(BIN)set_version
DEPS=$(DATABASE_DIR)xugfile.h
DEFINES=-DUSE_NCURSES
LIBS=-lncurses -lSDL2

all: $(OBJ) console_version console_server console_client refresh_version compile_banner

$(OBJ):
	@echo Compiling $@ ...
	@$(CC) $@.cpp -c -o $@.o $(CFLAGS) $(LIBS) $(DEFINES)

oldall: $(OBJS) console_version console_server console_client refresh_version compile_banner

fresh: fresh_banner clean clean_client clean_server all

tools: increment_build_count set_version

refresh_version:
	@$(INCREMENT_BUILD_COUNT_EXECUTABLE) $(BUILD_FILE)
	@$(SET_VERSION_EXECUTABLE) $(VERSION_FILE) $(VERSION)

increment_build_count:
	$(CC) src/globals/increment_build_count.c -o $(INCREMENT_BUILD_COUNT_EXECUTABLE)

set_version:
	$(CC) src/globals/set_version.c -o $(SET_VERSION_EXECUTABLE)

compile_banner:
	@cat res/compile_banner.txt
	@echo -n "Version: "
	@cat res/version.txt
	@echo -n ", Build: "
	@cat res/build.txt
	@echo
	@echo

fresh_banner:
	@echo
	@echo Performing a fresh compile
	@echo ...
	@echo

console_server: $(XUGFILE_SRC) $(DEPS)
	@echo Compiling the server ...
	@$(CC) $(XUGFILE_OBJS) -o $(SERVER_EXECUTABLE) $(DEFINES) $(LIBS) $(CFLAGS)


console_client: $(XUGFILE_SRC) $(DEPS)
	@echo Compiling the client ...
	@$(CC) $(XUGFILE_OBJS) -o $(CLIENT_EXECUTABLE) $(DEFINES) $(LIBS) $(CFLAGS)

console_version: $(XUGFILE_SRC) $(DEPS)
	@echo Compiling the full version ...
	@$(CC) $(XUGFILE_OBJS) -o $(EXECUTABLE) $(DEFINES) $(LIBS) $(CFLAGS_MAIN)


clean:
	@rm -f $(XUGFILE_OBJS) $(EXECUTABLE)

clean_server:
	@rm -f $(SERVER_EXECUTABLE)

clean_client:
	@rm -f $(CLIENT_EXECUTABLE)
