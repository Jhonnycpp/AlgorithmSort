cmake_minimum_required(VERSION 3.10)

project(Order)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

set(WORKSPACE ${PROJECT_SOURCE_DIR})

SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${WORKSPACE}/build)
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${WORKSPACE}/build)
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${WORKSPACE}/build)

set(MERGESORT
    ${WORKSPACE}/src/mergesort/sort.c
    ${WORKSPACE}/src/mergesort/merge.c
    ${WORKSPACE}/src/mergesort/mergesort.c
)

set(SOURCES
    ${MERGESORT}
    ${WORKSPACE}/src/menu/mymenu.c
    ${WORKSPACE}/src/order.c
    ${WORKSPACE}/src/utils.c

    ${WORKSPACE}/src/shellsort/shellsort.c
    ${WORKSPACE}/src/timsort/timsort.c
    ${WORKSPACE}/src/quicksort/quicksort.c
    ${WORKSPACE}/src/heapsort/heapsort.c
    ${WORKSPACE}/src/countingsort/countingsort.c
    ${WORKSPACE}/src/radixsort/radixsort.c
    ${WORKSPACE}/src/bubblesort/bubblesort.c
    ${WORKSPACE}/src/selectionsort/selectionsort.c
    ${WORKSPACE}/src/insertionsort/insertionsort.c

    ${WORKSPACE}/main.c
)

include_directories(
    ${WORKSPACE}/headers/mergesort/
    ${WORKSPACE}/headers/shellsort/
    ${WORKSPACE}/headers/timsort/
    ${WORKSPACE}/headers/quicksort/
    ${WORKSPACE}/headers/heapsort/
    ${WORKSPACE}/headers/countingsort/
    ${WORKSPACE}/headers/radixsort/
    ${WORKSPACE}/headers/bubblesort/
    ${WORKSPACE}/headers/selectionsort/
    ${WORKSPACE}/headers/insertionsort/
    ${WORKSPACE}/headers/menu/
    ${WORKSPACE}/headers/
)

add_executable(Order ${SOURCES})