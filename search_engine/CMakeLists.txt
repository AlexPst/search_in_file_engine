# CMakeList.txt: проект CMake для search_engine; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#

# Добавьте источник в исполняемый файл этого проекта.
add_executable (search_engine "search_engine.cpp" "include/search_engine.h" "ConverterJson.cpp" "include/ConverterJson.h" "include/InvertedIndex.h" "InvertedIndex.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET search_engine PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
