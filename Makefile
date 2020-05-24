# -----------------------------------------------------------------------------
# CMake project wrapper Makefile ----------------------------------------------
# -----------------------------------------------------------------------------

ifeq ($(OS),Windows_NT)
	RM    := rmdir /s /q build
	MKDIR := mkdir build > NUL 2>&1 & if ERRORLEVEL 1 cmd /c exit 0
	RUN_SILS   := ./build/sils_main.exe
	CMAKE_CMD  := cd build & cmake -G "MinGW Makefiles" ..
	MAKE_CMD   := cd build & make
endif

sils:
	@- $(MKDIR)
	@  $(CMAKE_CMD)
	@  $(MAKE_CMD)
	@  $(RUN_SILS)

clean:
	@  $(RM)
