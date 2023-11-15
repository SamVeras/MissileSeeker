CXX := g++
CXXFLAGS := -g -Wall -W -Werror $(shell pkg-config sdl2 --cflags)
LIBS := $(shell pkg-config sdl2 --libs)

INCLUDE := -I include

# Estrutura de diretórios
SRCDIR := src
BINDIR := bin
BUILDDIR := build
TESTDIR := test

# Extensão dos arquivos de fonte
SRCEXT := cpp

# Encontrar arquivos-fonte e objetos de testes
TESTSRC := $(wildcard $(TESTDIR)/*.$(SRCEXT))
TESTAPP := $(patsubst $(TESTDIR)/%.$(SRCEXT), $(BINDIR)/%, $(TESTSRC))

# Encontrar arquivos-fonte e objetos
SOURCES := $(wildcard $(SRCDIR)/*.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))

# Nome da aplicação
TARGET := seeker


# Principal
$(BINDIR)/$(TARGET): $(OBJECTS)
	@$(CXX) $(CXXFLAGS) $^ -o $@ $(LIBS)
	@echo "$(GC)Executable built successfully -> $@ $(NC)"

# Objetos
$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@$(CXX) $(CXXFLAGS) $(INCLUDE) -c -o $@ $<
	@echo "$(CC)Object built -> $@$(NC)"

# Teste
test: $(TESTAPP)
$(BINDIR)/%: $(TESTDIR)/%.$(SRCEXT) $(filter-out $(BUILDDIR)/main.o, $(OBJECTS))
	@$(CXX) $(CXXFLAGS) $(INCLUDE) $^ -o $@ $(LIBS)
	@echo "$(MC)Test file built successfully -> $@$(NC)"

# Limpar
clean:
	@find $(BINDIR) -type f -executable -exec rm {} \;
	@rm -rf $(BUILDDIR)/*.o
	@echo "$(BC)Cleaned.$(NC)"

# Executar
run:
	@$(BINDIR)/$(TARGET)

.PHONY: all test clean run

# Legibilidade do output (cores (frescura))
NC := \033[0m
GC := \033[32m
MC := \033[35m
BC := \033[34m
CC := \033[36m
