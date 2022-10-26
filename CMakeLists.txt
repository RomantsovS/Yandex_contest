cmake_minimum_required(VERSION 3.2)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

project(Yandex_contest VERSION ${PROJECT_VESRION})

add_executable(Difficult_numbes "Difficult_numbes.cpp")
add_executable(Game Game.cpp)
add_executable(Tournament_table Tournament_table.cpp)
add_executable(WalletsAndCoins WalletsAndCoins.cpp)
add_executable(Interesting_travel Interesting_travel.cpp)
add_executable(Dividing_a_number Dividing_a_number.cpp)
add_executable(MaximumDamage MaximumDamage.cpp)
add_executable(NestedRectangles NestedRectangles.cpp)
add_executable(GameWithNumbers GameWithNumbers.cpp)
add_executable(TheBestApproximation TheBestApproximation/TheBestApproximation.cpp)

set_target_properties(Difficult_numbes PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

include_directories("${CMAKE_BINARY_DIR}")

if (MSVC)
    set(MY_COMLILE_OPTIONS /WX)
else ()
    set(MY_COMLILE_OPTIONS -Wall -Wextra -pedantic -Werror -Wshadow -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -fsanitize=address)
endif()

target_compile_options(Difficult_numbes PRIVATE ${MY_COMLILE_OPTIONS})
target_compile_options(Game PRIVATE ${MY_COMLILE_OPTIONS})
target_compile_options(Tournament_table PRIVATE ${MY_COMLILE_OPTIONS})
target_compile_options(WalletsAndCoins PRIVATE ${MY_COMLILE_OPTIONS})
target_compile_options(Interesting_travel PRIVATE ${MY_COMLILE_OPTIONS})
target_compile_options(Dividing_a_number PRIVATE ${MY_COMLILE_OPTIONS})
target_compile_options(MaximumDamage PRIVATE ${MY_COMLILE_OPTIONS})
target_compile_options(NestedRectangles PRIVATE ${MY_COMLILE_OPTIONS})
target_compile_options(GameWithNumbers PRIVATE ${MY_COMLILE_OPTIONS})
target_compile_options(TheBestApproximation PRIVATE ${MY_COMLILE_OPTIONS})