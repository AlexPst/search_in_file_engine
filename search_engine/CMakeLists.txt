# CMakeList.txt: проект CMake для search_engine; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#

# Добавьте источник в исполняемый файл этого проекта.
add_executable (search_engine "search_engine.cpp" "include/search_engine.h" "ConverterJson.cpp" "include/ConverterJson.h" "include/InvertedIndex.h" "InvertedIndex.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET search_engine PROPERTY CXX_STANDARD 20)
endif()

set (BOOST_ROOT "C:/boost/") # Путь к библиотеке Boost
 
set (CMAKE_CXX_STANDARD 20) 
set (Boost_NO_SYSTEM_PATHS ON)
set (Boost_USE_MULTITHREADED ON)
set (Boost_USE_STATIC_LIBS ON)
set (Boost_USE_STATIC_RUNTIME OFF)
set (BOOST_ALL_DYN_LINK OFF)
  
# Подключаем необходимые модули. Для примера подключим program_options
find_package (Boost REQUIRED COMPONENTS program_options REQUIRED) 
  
# Если библиотека найдена, то
if (Boost_FOUND)
    include_directories (SYSTEM ${Boost_INCLUDE_DIR}) # подключаем заголовочные файлы
    add_executable (Boost_test "search_engine.cpp") # Создаем исполняемый файл для нашего проекта
    target_link_libraries (Boost_test ${Boost_LIBRARIES}) # подключаем библиотеку
endif ()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
