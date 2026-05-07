cmake_minimum_required(VERSION 3.10)
project(TemplateProject)

# Налаштування стандарту C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- Підключення Google Test ---
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
# Для Windows: запобігання помилкам з runtime бібліотеками
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# --- Основна програма (з вашим main.cpp) ---
add_executable(main_app main.cpp)

# --- Модуль тестів ---
# Створюємо окремий файл для тестів
add_executable(UnitTest UnitTest.cpp)

# Прив'язуємо GTest до наших тестів
# gtest_main автоматично додає функцію main(), тому в UnitTest.cpp вона не потрібна
target_link_libraries(UnitTest GTest::gtest_main)

# Додаємо можливість запуску через 'ctest'
enable_testing()
add_test(NAME MyTemplateTests COMMAND UnitTest)