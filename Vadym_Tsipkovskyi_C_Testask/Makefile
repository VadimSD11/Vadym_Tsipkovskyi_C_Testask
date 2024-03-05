CC = g++
CFLAGS = -std=c++17 -Wall
LDFLAGS = -L"C:/Users/Vadim_y9xms2s/source/repos/Vadym_Tsipkovskyi_C_Testask/StaticLib1" -lfilesearch
SOURCES = "C:/Users/Vadim_y9xms2s/source/repos/Vadym_Tsipkovskyi_C_Testask/Vadym_Tsipkovskyi_C_Testask/main.cpp"
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = filesearchapp

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
    $(CC) $(CFLAGS) $(OBJECTS) $(LDFLAGS) -o $@

.cpp.o:
    $(CC) $(CFLAGS) -c $< -o $@

clean:
    rm -f $(OBJECTS) $(EXECUTABLE)
